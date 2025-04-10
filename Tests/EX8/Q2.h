#include <iostream>
#include <fstream>

using namespace std;

class Robot{
  
  int serialNum;
  
  public:
  Robot(int serialNum){
      this->serialNum=serialNum;
  }
  
  int getSerialNum() const{ return serialNum;}
  
  Robot(ifstream& in){
      in.read((char*)&serialNum,sizeof(serialNum));
  }
  
  
  void save(ofstream& out){
      out.write((char*)&serialNum,sizeof(serialNum));
      saveAdditions(out);
  }
  
  void load(ifstream& in){
      in.read((char*)&serialNum,sizeof(serialNum));
      loadAdditions(in);
  }


  protected:  
  virtual void saveAdditions(ofstream& out) const =0;
  virtual void loadAdditions(ifstream& in)=0;
  
};

class GroundRobot: public virtual Robot{
    int speed;
    public:
    
    int getSpeed() const{
        return speed;
    }
    
    GroundRobot(int serialNum, int speed):Robot(serialNum){
        this->speed=speed;
    }
    
    GroundRobot(ifstream& in):Robot(in){
        loadAdditions(in);
    };
    
  virtual void saveAdditions(ofstream& out) const{
      out.write((char*)&speed,sizeof(speed));
  }
  virtual void loadAdditions(ifstream& in){
    in.read((char*)&speed,sizeof(speed));
  }
    
};

class UAV: public virtual Robot{
    double alt;
    public:
    
    double getAlt() const{
        return alt;
    }

    UAV(int serialNum, double alt):Robot(serialNum){
        this->alt=alt;
    }
    
    UAV(ifstream& in):Robot(in){
        loadAdditions(in);
    };
    
  virtual void saveAdditions(ofstream& out) const{
      out.write((char*)&alt,sizeof(alt));
  }
  virtual void loadAdditions(ifstream& in){
      in.read((char*)&alt,sizeof(alt));
  }
    
};

class GroundUAV: public GroundRobot, public UAV{
    public:
    GroundUAV(int serialNum, int speed, double alt):Robot(serialNum),GroundRobot(serialNum,speed), UAV(serialNum,alt){}
    
    GroundUAV(ifstream& in):Robot(in),GroundRobot(in),UAV(in){};
    
  virtual void saveAdditions(ofstream& out) const{
      GroundRobot::saveAdditions(out);
      UAV::saveAdditions(out);
  }
  virtual void loadAdditions(ifstream& in){
      GroundRobot::loadAdditions(in);
      UAV::loadAdditions(in);
  }
};


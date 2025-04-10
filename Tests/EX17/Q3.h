
#ifndef SRC_Q3_H_
#define SRC_Q3_H_

using namespace std;

class Clock{
  int h,m; // hours, minutes
  
  void set(){
    m%=60;
    if(m<0)
        m+=60;
    h%=12;
    if(h<0)
        h+=12;
  }
  
  public:
  
  int getM(){return m;}
  int getH(){return h;}
  void setM(int m){this->m=m;}
  void setH(int h){this->h=h;}
  
  void operator++(){
      m+=1;
      if(m==60)
        h+=1;
      set();
  }
  void operator--(){
      m-=1;
      if(m==-1)
        h-=1;
      set();
  }
  void operator+=(int min){
      m+=min%60;
      h+=min/60;
      set();
  }
  void operator-=(int min){
      m-=min%60;
      h-=min/60;
      set();
  }
  
  void operator*=(int hr){
      (*this)+=(hr*60);
  }
  
  void operator/=(int hr){
      (*this)-=(hr*60);
  }
  
  int operator[](int index){
      if(index==0)
        return h;
      if(index==1)
        return m;
      return 0;
  }
  
  void operator=(int time){
      h=time/60;
      m=time%60;
  }
  
};



#endif /* SRC_Q3_H_ */

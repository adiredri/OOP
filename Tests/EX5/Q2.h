#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

class Dog{
    int _id;
    float _weight;
    
    public:
    Dog(int id,float weight):_id(id),_weight(weight){}
    
    void print(ostream& out){
        out<<"ID: "<<_id<<endl;
        out<<"Weight: "<<_weight<<endl;
        printAdditionalFeatures(out);
    }
    int getID(){return _id;}
    float getWeight(){return _weight;}
	
    virtual ~Dog(){}
    
    protected:
    virtual void printAdditionalFeatures(ostream& out)=0;
};

class Bulldog: public virtual Dog{
    bool _friendly;
    public:
    Bulldog(int id,float weight, bool friendly=true):Dog(id,weight){
        _friendly=friendly;
    }
    
    protected:
    virtual void printAdditionalFeatures(ostream& out){
        out<<"Friendly "<<_friendly<<endl;
    }
};

class Poodle: public virtual Dog{
    bool _intelligent;
    public:
    Poodle(int id,float weight,bool intelligent=true):Dog(id,weight){
        _intelligent=intelligent;
    }
    
    protected:
    virtual void printAdditionalFeatures(ostream& out){
        out<<"Intelligent "<<_intelligent<<endl;
    }
    
};

class BulldogPoodle: public Bulldog, public Poodle{
    public:
    BulldogPoodle(const Bulldog& b, const Poodle& p):Dog(b),Bulldog(b),Poodle(p){}
    protected:
    virtual void printAdditionalFeatures(ostream& out){
        Bulldog::printAdditionalFeatures(out);
        Poodle::printAdditionalFeatures(out);
    }

};

void saveDogs(Dog** dogs,int size,ofstream& out){
    out<<size<<endl;
    for(int i=0;i<size;i++){
        out<<typeid(*dogs[i]).name()<<endl;
        dogs[i]->print(out);
    }
}

void loadDogs(Dog**& dogs,int& size,ifstream& in){
    in>>size;
    dogs=new Dog*[size];
    char type[20],someText[20];
    for(int i=0;i<size;i++){
        in>>type;
        int id;
        float weight;
        bool property;
        in>>someText;
        in>>id;
        in>>someText;
        in>>weight;
        in>>someText;
        in>>property;
        if(type[0]=='7')
            dogs[i]=new Bulldog(id,weight,property);
        if(type[0]=='6')
            dogs[i]=new Poodle(id,weight,property);
        if(type[0]=='1'){
            bool intelligent;
            in>>someText;
            in>>intelligent;
            Bulldog* b=new Bulldog(id,weight,property);
            Poodle* p=new Poodle(id,weight,intelligent);
            dogs[i]=new BulldogPoodle(*b,*p);
        }
    }
}

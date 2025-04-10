#ifndef SRC_EXAM_H_
#define SRC_EXAM_H_

#ifndef NULL
#define NULL 0
#endif

class Being{
    public:
    const int id;
    Being(int id):id(id){}    
    virtual ~Being(){}

};

class Human:public virtual Being{
    int power=10;
    public:
    Human(int id):Being(id){}
    virtual int getPower(){
        return power;
    }
    void setHumanPower(int power){
        this->power=power;
    }

};

class Orc:public virtual Being{
    int power=15;    
    public:
    Orc(int id):Being(id){}
    virtual int getPower(){
        return power;
    }
    void setOrcPower(int power){
        this->power=power;
    }
};


class BeingList{
    public:
    const BeingList* next;
    const Being* item;
    BeingList(BeingList* next,Being* item):next(next),item(item){}
    ~BeingList(){
        delete item;
        delete next;
    }
};



#endif /* SRC_EXAM_H_ */
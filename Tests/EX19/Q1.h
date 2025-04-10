#ifndef SRC_Q1_H_
#define SRC_Q1_H_

#include "exam.h"

class UrukHai: public Human, public Orc{
    public:
    UrukHai(int id):Being(id),Human(id),Orc(id){}

    virtual int getPower(){
        return Human::getPower()+Orc::getPower();
    }

};



#endif /* SRC_Q1_H_ */
#ifndef SRC_Q1_H_
#define SRC_Q1_H_
#include "exam.h"
using namespace std;

class UnicornCreator{
    int id;
    bool hasWings;
    char color;
    int power;

    public:

    UnicornCreator(){
        id=0;
        hasWings=false;
        color='w';
        power=0;
    }

    UnicornCreator& setID(int id){
        this->id=id;
        return *this;
    }

    UnicornCreator& addWings(){
        hasWings=true;
        return *this;
    }

    UnicornCreator& setColor(char color){
        this->color=color;
        return *this;
    }

    UnicornCreator& setPower(int power){
        this->power=power;
        return *this;
    }

    Unicorn build(){
        return Unicorn(id,hasWings,color,power);
    }

};


#endif /* SRC_Q1_H_ */
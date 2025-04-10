#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <typeinfo>
#include "exam.h"


template<class Predicate>
int countIf(Being** arr,int size,Predicate p){
    int c=0;
    for(int i=0;i<size;i++){
        if (p(arr[i]))
            c++;
    }
    return c;
}

struct isOrc{
    bool operator()(Being * b){
        return typeid(*b)==typeid(Orc);
    }
};

struct isHuman{
    bool operator()(Being * b){
        return typeid(*b)==typeid(Human);
    }
};

template<class Predicate, class SumFunc>
int sumIf(Being** arr,int size,Predicate p, SumFunc sf){
    int c=0;
    for(int i=0;i<size;i++){
        if (p(arr[i]))
             c+=sf(arr[i]);
    }
    return c;
}

struct SumPower{
    int operator()(Being * b){
        Human* h=dynamic_cast<Human*>(b);
        if (h)
            return h->getPower();        
        Orc* o=dynamic_cast<Orc*>(b);
        if (o)
            return o->getPower();
        return 0;
    }
};



#endif /* SRC_Q2_H_ */
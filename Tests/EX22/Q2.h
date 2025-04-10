#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <typeinfo>
#include "exam.h"


template<class func>
Array<Dog> getAll(Dog** array,int size, func f, int threshold){
    int c=0;
    for(int i=0;i<size;i++){
        if(f(array[i])>threshold){
            c++;
        }
    }

    Dog** r=new Dog*[c];
    int j=0;
    for(int i=0;i<size;i++){
        if(f(array[i])>threshold){
            r[j]=array[i];
            j++;
        }
    }
    
    return Array<Dog>(r,c);
}

struct NinjaLevel{
  int operator()(Dog* d){
      return (d->getPowerLevel()+d->getStealthLevel()*2)/3;
  }
};


#endif /* SRC_Q2_H_ */
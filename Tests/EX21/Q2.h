#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <typeinfo>
#include "exam.h"


template<class predicate>
Array<Cat> getAll(Cat** array,int size, predicate p){
    int c=0;
    for(int i=0;i<size;i++){
        if(p(array[i])){
            c++;
        }
    }
    
    Cat** r=new Cat*[c];
    int j=0;
    for(int i=0;i<size;i++){
        if(p(array[i])){
            r[j]=array[i];
            j++;
        }
    }
    
    return Array<Cat>(r,c);
}

struct isSamurai{
  bool operator()(Cat* c){
      return (dynamic_cast<SamuraiCat*>(c)!=NULL);
  }
};


#endif /* SRC_Q2_H_ */
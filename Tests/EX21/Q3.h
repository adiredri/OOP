#ifndef SRC_Q3_H_
#define SRC_Q3_H_
#include "exam.h"

template<class T>
class ArrayIterator{
    
    T* p; 
    int len;
    int i;
    Array<T> array;
    
    public:
    ArrayIterator(Array<T> array):array(array){
        len=array.length;
        p=array.array[0];
        i=0;
    }

    T operator*(){
        return *p;
    }
    
    ArrayIterator& operator++(){
        p++;
        i++;
        if(i==len){
            i=0;
            p=array.array[0];
        }
        return *this;
    }
    
    ArrayIterator& operator--(){
        p--;
        i--;
        if(i==-1){
            i=len-1;
            p=array.array[i];
        }
        return *this;
    }
    
    bool operator==(ArrayIterator it){
        return p==it.p;
    }
    
    bool operator!=(ArrayIterator it){
        return p!=it.p;
    }
};

#endif /* SRC_Q3_H_ */
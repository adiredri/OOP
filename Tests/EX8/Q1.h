#include <iostream>
#include <stdlib.h>
using namespace std;

class Array32{
    // ------------- do not change the code
    int mem;
    int array[32];
    int all;
    public:
    
    Array32& operator=(int val){
        all=val;
        mem=0;
        return *this;
    }
    
    int getMem(){ return mem;}
    
    // change code from here -------------
    
    int operator[](int index) const{
        int a=1;
        a<<=index;
        if(a&mem)
            return array[index];
        return all;
    }
    
    int& operator()(int index){
        int a=1;
        a<<=index;
        mem|=a;
        return array[index];
    }
    
};


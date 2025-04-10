#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Array{
    T* ts;
    size_t size; // size_t is simply unsigned int
    public:
    Array(size_t size){
        ts=new T[size];
        this->size=size;
    }
    
    T& operator[](size_t index)throw(const char*){
        if(index<0 || index>=size)
            throw "invalid index";
       return ts[index]; 
    }
    
    T get(size_t index)const throw(const char*){
        if(index<0 || index>=size)
            throw "invalid index";
        return ts[index];
    }
    
    void clear(){
        if(size>0){
            delete []ts;
            size=0;
        }
    }
    
    void resize(size_t newSize){
        if(newSize==0)
            clear();
        if(newSize>0 && newSize!=size){
            T* nts=new T[newSize];
            for(size_t i=0;i<min(newSize,size);i++){
                nts[i]=ts[i];
            }
            clear();
            ts=nts;
            size=newSize;
        }
    }
    
    template<class func>
    func forEach(func f){
        for(size_t i=0;i<size;i++)
            f(ts[i]);
        return f;
    }
    
    size_t getSize()const{
        return size;
    }
    
    size_t search(const T& t){
        for(size_t i=0;i<size;i++){
            if(t==ts[i])
                return i;
        }
        return -1;
    }
    
    Array<T>& operator+=(const Array<T>& a){
        size_t m=size;
        resize(size+a.getSize());
        for(size_t i=m;i<size;i++)
            ts[i]=a.get(i-m);
            
        return *this;
    }
    
    ~Array(){
        clear();
    }
};

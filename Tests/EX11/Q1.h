#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Box{
    vector<T> items;
    
    public:
    Box& operator+=(T t){
        items.push_back(t);
        return *this;
    }
    
    T operator[](int index){
        return items[index];
    }
    
    int size(){
        return items.size();
    }
    
};

template<class T>
ostream& operator<<(ostream& out,Box<T> box){
    out<<"{";
    if(box.size()>0){
        for(int i=0;i<box.size()-1;i++)
            out<<box[i]<<",";
        out<<box[box.size()-1];
    }
    out<<"}";
    return out;
}


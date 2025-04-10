#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


template<class T>
class Stream{
    list<T> buff;
    
    public:
    void push(const T& t){
        buff.push_front(t);
    }
    

    template<class func>
    Stream& process(func f){
        for_each(buff.begin(),buff.end(),f);
        return *this;
    }
    
    template<class mapper>
    Stream& map(mapper m){
        typename list<T>::iterator it=buff.begin();
        while(it!=buff.end()){
            *it = m(*it);
            it++;
        }
        return *this;
    }
    
    Stream& reverse(){
        list<T> temp;
        temp.insert(temp.begin(),buff.begin(),buff.end());
        buff.clear();
        typename list<T>::iterator it=temp.begin();
        while(it!=temp.end()){
            buff.push_front(*it);
            it++;
        }
        return *this;
    }

};
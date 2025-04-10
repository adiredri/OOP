#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// implement the missing operators such that the function below will work

template<class T>
void operator+=(list<T> & l1, list<T> & l2){
    for_each(l2.begin(),l2.end(),[&l1,&l2](T t){l1.push_back(t);});
}

template<class T>
void operator+=(list<T> & l, T t){
    l.push_back(t);
}


template<class T>
bool operator==(list<T> & l1, list<T> & l2){
    if(l1.size()!=l2.size())
        return false;
    typename list<T>::iterator it1=l1.begin();
    typename list<T>::iterator it2=l2.begin();
    while(it1!=l1.end() && it2!=l2.end()){
        if((*it1)!=(*it2))
            return false;
    }
    return true;
}

template<class T>
bool operator!=(list<T> & l1, list<T> & l2){
    return !(l1==l2);
}

template<class T>
ostream& operator<<(ostream& out,list<T> & l){
    for_each(l.begin(),l.end(),[&out](T t){out<<t<<", ";});
    return out;
}


#ifndef SRC_Q1_H_
#define SRC_Q1_H_
#include<vector>
using namespace std;

template<class iterator, class predicate, class T>
void filter(iterator begin, iterator end,predicate p,vector<T>& v){
    while(begin!=end){
        if(p(*begin))
            v.push_back(*begin);
        ++begin;
    }
}

template<class iterator, class func, class R>
void map(iterator begin, iterator end,func f,vector<R>& v){
    while(begin!=end){
        v.push_back(f(*begin));
        ++begin;
    }
}



#endif /* SRC_Q1_H_ */

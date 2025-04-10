
#ifndef SRC_Q1_H_
#define SRC_Q1_H_
#include<vector>
#include<algorithm>

using namespace std;

template<class iterator, class predicate>
int countIf(iterator begin, iterator end,predicate p){
	int count=0;
    while(begin!=end){
        if(p(*begin))
            count++;
        ++begin;
    }
	return count;
}

template<class T>
T mid(vector<T> v){
    vector<T> v1 = v; // copy
    sort(v1.begin(),v1.end());
    return v1[v1.size()/2];
}



#endif /* SRC_Q1_H_ */

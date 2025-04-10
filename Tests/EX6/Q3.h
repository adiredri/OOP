#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <class V>
class Property{
    V value;
    list<Property<V>*> boundToMe;
    
    public:
    
    void bindTo(Property<V>& p){
        p.boundToMe.push_back(this);
    }
    
    void set(V val){
        if(val!=value){
            value=val;
            // solution using one line of lambda expression:
            //for_each(boundToMe.begin(),boundToMe.end(),[&val](Property<V>* p){p->set(val);});

            // basic solution:
            typename list<Property<V>*>::iterator it=boundToMe.begin();
            while(it!=boundToMe.end()){
                (*it)->set(val);
                it++;
            }
        }
    }
    
    V get()const{        
        return value;
    }
};


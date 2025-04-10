#include <iostream>
#include <string.h>
#include <math.h>
#include "Q1.h"
#include "Q2.h"

using namespace std;

struct Set5{
    void operator()(int& x){
        x=5;
    }	
};

struct Sum{
    int sum;
    Sum():sum(0){}
    void operator()(int x){
        sum+=x;
    }
};

int test1(){
    
    Array<int> a(3); // CTOR
    // operator[] 
    a[0]=1;
    a[1]=2;
    a[2]=3;
    if(a[0]!=1 || a[1]!=2 || a[2]!=3)
        cout<<"problem with operator[] detected (-5)"<<endl;
    
    try{
        a[3]=4;
        cout<<"you did not throw an exception (-5)"<<endl;
    }catch(const char* msg){
        if(strcmp("invalid index",msg))
            cout<<"wrong message was thrown (-5)"<<endl;
    }
    
    a.resize(4); // resize
    a[3]=4;
    if(a.getSize()!=4 || a[0]!=1 || a[1]!=2 || a[2]!=3 || a[3]!=4)
        cout<<"problem with resize detected (-5)"<<endl;
        
    a.clear(); // clear

    int sum=0;
    for(size_t i=0;i<a.getSize();sum+=a.get(i),i++);
    
    if(sum!=0)
        cout<<"problem with clear detected (-5)"<<endl;

    // notice current size is 0
    a.resize(10);
    a.forEach(Set5()); // forEach

    Sum s;
    s=a.forEach(s);
    if(s.sum!=50)
        cout<<"problem with forEach detected (-10)"<<endl;

    for(size_t i=0;i<a.getSize();a[i]=i*2,i++);

    // search    
    if(a.search(10)!=5)
        cout<<"problem with search detected (-10)"<<endl;
        
    Array<int> b(3);
    b[0]=20;
    b[1]=22;
    b[2]=24;
    
    // operator +=
    a+=b;
    
    s.sum=0;
    s=a.forEach(s);
    if(s.sum!=156)
        cout<<"problem with forEach detected (-10)"<<endl;
    
    
}

void test2(){
    Employee e1(11), e2(12), e3(21), e4(22);
    BOS b1(1);
    BOS b2(2);

    try{
        // ok
        b1.add(&e1);
        b1.add(&e2);
        
        //ok
        b1.add(&b2);
    
        // ok
        b2.add(&e3);
        b2.add(&e4);
        
    }catch(const char* err){
        cout<<"you should NOT throw an exception here (-25)"<<endl;
    }
    try{
        b2.add(&b1);
        cout<<"you should have thrown an exception (-25)"<<endl;
    }catch(const char* err){
        if(strcmp(err,"ERROR: BOS circle"))
            cout<<"you should throw the exact message (-10)"<<endl;
    }

}

int main()
{
	test1();
	test2();
	cout<<"done"<<endl;
	return 0;
}

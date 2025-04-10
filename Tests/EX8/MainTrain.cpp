#include "Q1.h"
#include "Q2.h"
#include "Q3.h"



void test1(){
    Array32 arr;
    
    arr=5;
    
    // test 3 random indexes for arr[i]==5
    for(int i=0;i<3;i++){
        int index=rand() % 32;
        if(arr[index]!=5)
            cout<<"wrong value after setting all the array (-5)"<<endl;
    }
    
    arr(3)=19;
    if(arr[3]!=19)
        cout<<"wrong value after setting a particular index (-5)"<<endl;
    
    if(arr.getMem()!=8) // 000...001000
        cout<<"wrong value for mem (-10)"<<endl;
 }


void test2(){
	int serialNum=1101101;
	int speed=500;
	double alt=400.565;

	ofstream out("robotTrain.bin");
    GroundUAV(serialNum,speed,alt).save(out);
    out.close();
 
    ifstream in("robotTrain.bin") ;
    GroundUAV r(in);
    in.close();
   
    if(r.getSerialNum()!=serialNum)
     cout<<"wrong serialNum loaded (-11)"<<endl;
    if(r.getSpeed()!=speed)
     cout<<"wrong speed loaded (-12)"<<endl;
    if(r.getAlt()!=alt)
     cout<<"wrong alt loaded (-12)"<<endl;
}


void test3(){
    BiGraph<int,char> g;
    g.add(5);
    g.add(9);
    g.add(1);
    g.add('E');
    g.add('K');
    
    g.connect(5,'E');
    g.connect(9,'K');
    g.connect(1,'E');
    
    list<char> rc=g.getNeighbors(9);
    if(rc.size()!=1)
        cout<<"wrong size of returned neighbors list for node type A (-15)"<<endl;
    else{
        if(rc.front()!='K')
            cout<<"wrong values returned for neighbors list for node type A (-15)"<<endl;
    }

    list<int> ri=g.getNeighbors('E');
    if(ri.size()!=2)
        cout<<"wrong size of returned neighbors list for node type B (-20)"<<endl;
    else{
        if(ri.front()!=5)
            cout<<"wrong value returned for neighbors list for node type B (-10)"<<endl;
        ri.pop_front();
        if(ri.front()!=1)
            cout<<"wrong value returned for neighbors list for node type B (-10)"<<endl;
    }

}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;
	return 0;
}
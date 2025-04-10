#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <typeinfo>
#include "exam.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

using namespace std;

void test1(){
	srand (time(NULL));
	int arr[4];
	for(int i=0;i<4;i++){
		arr[i]=10+rand()%5;
	}
	
    SamuraiCat sc(5);	
	sc.setPowerLevel(arr[0]);
    sc.setStealthLevel(arr[1]);
    
	ThunderCat tc(10);
	tc.setPowerLevel(arr[2]);
    tc.setStealthLevel(arr[3]);

    Cat* c=new SamuraiThunderCat(0,sc,tc); // tests SamuraiThunderCat is a type of Cat. A fail cause runtime error...

    bool ok=true;
    if(dynamic_cast<SamuraiCat*>(c)==NULL){
        cout<<"Your SamuraiThunderCat is not a type of SamuraiCat (-11)"<<endl;
        ok=false;
    }

    if(dynamic_cast<ThunderCat*>(c)==NULL){
        cout<<"Your SamuraiThunderCat is not a type of ThunderCat (-11)"<<endl;
        ok=false;
    }

    if(ok){ 
        SamuraiThunderCat* stc=dynamic_cast<SamuraiThunderCat*>(c);
        if(stc){
			int p=stc->getPowerLevel();
			int s=stc->getStealthLevel();
			ok = (p==max(arr[0],arr[2]) && s==max(arr[1],arr[3]));
        }else
            ok=false;
    }

    if(!ok)
        cout<<"problem with SamuraiThunderCat methods (-11)"<<endl;
    
    delete c;
}

class DSC: public SamuraiCat{
    public:
    DSC(int id):Cat(id),SamuraiCat(id){}
};


void test2(){
    int c=0,c2=0;
    int N=100;
    Cat** array=new Cat*[N];
    for(int i=0;i<N;i++){
        int x=rand()%3;
        if(x==0)
            array[i]=new ThunderCat(0);
        if(x==1){
            array[i]=new SamuraiCat(0);
            c++;
        }
        if(x==2){
            array[i]=new DSC(0);
            c++;
        }
        int p=5+rand()%10;
        array[i]->setPowerLevel(p);
        if(p>12)
            c2++;
    }
    
    Array<Cat> samurais = getAll(array,N,isSamurai());

    if(samurais.length != c){
        cout<<"problem with the size of array getAll returned (-11)"<<endl;
    }
    
    bool ok=true;
    for(int i=0;i<samurais.length && ok; i++){
        if(typeid(*samurais.array[i])==typeid(ThunderCat))
            ok=false;
    }
    if(!ok){
        cout<<"your array contains none samurais (-11)"<<endl;
    }
    
    Array<Cat> strongCats=getAll(array,N,[](Cat* c){return c->getPowerLevel()>12;});
    
    ok=false;
    if(strongCats.length==c2){
        ok=true;
        for(int i=0;i<strongCats.length && ok; i++){
            if(strongCats.array[i]->getPowerLevel()<=12)
                ok=false;
        }
    }
    if(!ok){
        cout<<"wrong result for getAll function (-10)"<<endl;
    }
    
    
    for(int i=0;i<N;i++)
        delete array[i];
    delete [] array;
}


void test3() {
    
    int arr1[] = {rand()%100, rand()%100, rand()%100, rand()%100, rand()%100};
    int* ptrArr1[] = {arr1, arr1+1, arr1+2, arr1+3, arr1+4};
    Array<int> array1(ptrArr1, 5);
    ArrayIterator<int> it1(array1);

    // Test forward iteration
    for (int i = 0; i < 5; ++i) {
        if (*it1 != arr1[i]) {
            cout << "Forward iteration test failed (-2)" << endl;
        }
        ++it1;
    }

    // After the last element, it should point to the first element
    if (*it1 != arr1[0]) {
        cout << "Forward iteration wrap-around failed (-7)" << endl;
    }

    // Test backward iteration
    for (int i = 4; i >= 0; --i) {
        --it1;
        if (*it1 != arr1[i]) {
            cout << "Backward iteration test failed (-2)" << endl;
        }
    }
    --it1;
    // Before the first element, it should point to the last element
    if (*it1 != arr1[4]) {
        cout << "Backward iteration wrap-around failed (-8)" << endl;
    }
    
    

}

int main()
{
    test1(); // 30 points
    test2(); // 32 points
    test3(); // 35 points
    cout<<"done"<<endl;
    return 0;
}

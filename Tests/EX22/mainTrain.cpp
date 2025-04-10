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
	
    SamuraiDog sc(5);	
	sc.setPowerLevel(arr[0]);
    sc.setStealthLevel(arr[1]);
    
	ThunderDog tc(10);
	tc.setPowerLevel(arr[2]);
    tc.setStealthLevel(arr[3]);

    Dog* c=new SamuraiThunderDog(0,sc,tc); // tests SamuraiThunderDog is a type of Dog. A fail cause runtime error...

    bool ok=true;
    if(dynamic_cast<SamuraiDog*>(c)==NULL){
        cout<<"Your SamuraiThunderDog is not a type of SamuraiDog (-11)"<<endl;
        ok=false;
    }

    if(dynamic_cast<ThunderDog*>(c)==NULL){
        cout<<"Your SamuraiThunderDog is not a type of ThunderDog (-11)"<<endl;
        ok=false;
    }

    if(ok){ 
        SamuraiThunderDog* stc=dynamic_cast<SamuraiThunderDog*>(c);
        if(stc){
			int p=stc->getPowerLevel();
			int s=stc->getStealthLevel();
			ok = (p==(arr[0]+arr[2])/2 && s==(arr[1]+arr[3])/2);
        }else
            ok=false;
    }

    if(!ok)
        cout<<"problem with SamuraiThunderDog methods (-11)"<<endl;
    
    delete c;
}


void test2(){
    int c=0,c2=0;
    int N=100;
    int th=15+rand()%5;
    Dog** array=new Dog*[N];
    for(int i=0;i<N;i++){
        array[i]=new ThunderDog(0);
        int p=5 + rand()%10;
        if(p>12)
            c2++;
        int s=5 + rand()%10;
        int g=(p+s*2)/3;
        if(g>th)
            c++;
        array[i]->setStealthLevel(s);
        array[i]->setPowerLevel(p);
        
    }
    
    Array<Dog> ninjas = getAll(array,N,NinjaLevel(),th);

    if(ninjas.length != c){
        cout<<"problem with the size of array getAll returned (-11)"<<endl;
    }
    
    bool ok=true;
    for(int i=0;i<ninjas.length && ok; i++){
        int p=array[i]->getPowerLevel();
        int s=array[i]->getStealthLevel();
        if((s*2+p)/3<=th)
            ok=false;
    }
    if(!ok){
        cout<<"your array contains wrong cells (-11)"<<endl;
    }
    
    Array<Dog> strongDogs=getAll(array,N,[](Dog* c){return c->getPowerLevel();},12);
    
    ok=false;
    if(strongDogs.length==c2){
        ok=true;
        for(int i=0;i<strongDogs.length && ok; i++){
            if(strongDogs.array[i]->getPowerLevel()<=12)
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

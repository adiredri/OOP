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

    Being* b=new UrukHai(0); // tests UrukHai is a type of Being. A fail cause runtime error...

    bool ok=true;
    Human* h=dynamic_cast<Human*>(b);
    if(h==NULL){
        cout<<"Your UrukHai is not a type of Human (-11)"<<endl;
        ok=false;
    }

    Orc* o=dynamic_cast<Orc*>(b);
    if(o==NULL){
        cout<<"Your UrukHai is not a type of Orc (-11)"<<endl;
        ok=false;
    }

    if(ok){ 
        UrukHai* uh=dynamic_cast<UrukHai*>(b);
        if(uh){
            srand (time(NULL));
            int hp=10+rand()%5;
            uh->setHumanPower(hp);
            int op=15+rand()%3;
            uh->setOrcPower(op);
            if(uh->getPower()!=hp+op)
                ok=false;
        }else
            ok=false;
    }

    if(!ok)
        cout<<"problem with UrukHai power (-11)"<<endl;
    
    delete b;
}

void test2(){

    srand (time(NULL));
    int size=16;
    int hSize=0,oSize=0,hp=0,op=0;
    Being** beings=new Being*[size];
    for(int i=0;i<size;i++){
        if(rand()%2){// 0,1
            Human* h=new Human(rand()%1000);
            int p=10+(rand()%10);
            hp+=p;            
            h->setHumanPower(p);
            beings[i]=h;
            hSize++;
        }else{
            Orc* o=new Orc(rand()%1000);
            int p=15+(rand()%3);
            op+=p;
            o->setOrcPower(p);
            beings[i]=o;
            oSize++;                
        }
    }

    if(countIf(beings,size,isOrc()) != oSize)
        cout<<"wrong number of Orcs counted (-8)"<<endl;

    if(countIf(beings,size,isHuman()) != hSize)
        cout<<"wrong number of Humans counted (-8)"<<endl;


    if(sumIf(beings,size,isHuman(),SumPower()) != hp)
        cout<<"wrong value for Human power sum (-8)"<<endl;

    if(sumIf(beings,size,isOrc(),SumPower()) != op)
        cout<<"wrong value for Orc power sum (-8)"<<endl;
    

    for(int i=0;i<size;i++){
        delete beings[i];
    }

    delete [] beings;
}


void test3(){
    srand (time(NULL));
    int size=35;
    Being** beings=new Being*[size];
    for(int i=0;i<size;i++){
        beings[i]=new Being(rand()%1000);
    }

    BeingList* last=new BeingList(NULL,NULL);
    for(int i=size-1;i>=0;i--){
        BeingList* bl=new BeingList(last, beings[i]);
        last=bl;
    }
    BeingList* head=last;

    int i=0;
    BeingListIterator it(head);
    while (it.hasNext()){
        const Being* b = (*it);
        if(b->id !=beings[i]->id)
            cout<<"wrong id for a being (-1)"<<endl;
        ++it;
        ++i;
    }

    if (i!=size)
        cout<<"size error (-"<<(abs(size-i))<<")"<<endl;


    delete head; // delete the list and all items

    delete [] beings;
}

int main()
{
    test1(); // 30 points
    test2(); // 32 points
    test3(); // 35 points
    cout<<"done"<<endl;
    return 0;
}

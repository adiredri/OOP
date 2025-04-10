#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

#include <sstream>

struct INC{
    template<class Num>
    void operator()(Num& num){
        ++num;
    }
};

void test1(){
    BinTree<float> tree;
    float arr[]={5,3,6,1,2,4,7};
    float xarr[]={5,3,6,1,4,7,2};
    float xarr2[]={6,4,7,2,5,8,3};
    float xarr3[]={6,7,8};
    
    for(int i=0;i<7;i++)
        tree.insert(arr[i]); // 14 points
        
    stringstream out;
    tree.print(out);
    for(int i=0;i<7;i++){
        float x;
        out>>x;
        if(x!=xarr[i])
            cout<<"wrong value in tree for index "<<i<<" (-2)"<<endl;
    }

    tree.forEach(INC()); // 14 points
    
    tree.print(out);
    for(int i=0;i<7;i++){
        float x;
        out>>x;
        if(x!=xarr2[i])
            cout<<"wrong value in tree after INC for index "<<i<<" (-2)"<<endl;
    }
    

    tree.deleteSubTree(1); // 1 does not exist. Nothing happens.
    
    tree.deleteSubTree(4); // 6 points

    tree.print(out);
    for(int i=0;i<3;i++){
        float x;
        out>>x;
        if(x!=xarr3[i])
            cout<<"wrong value in tree after delete for index "<<i<<" (-2)"<<endl;
    }
}


void test2(){
    Dog** dogs=new Dog*[5];
    dogs[0]=new Bulldog(123,20);
    dogs[1]=new Bulldog(1234,20,false);
    dogs[2]=new Poodle(321,10,false);
    dogs[3]=new Poodle(4321,10);
    BulldogPoodle bp(Bulldog(111,30),Poodle(123,40));
    dogs[4]=&bp;
    

    ofstream out("output.txt");
    saveDogs(dogs,5,out);
    out.close();
    

    ifstream in("output.txt");
    Dog** dogs2;
    int size;
    loadDogs(dogs2,size,in);
    in.close();
    
    if(size!=5)
        cout<<"you did not load the same number of items (-35)"<<endl;
    else{
        for(int i=0;i<size;i++){
            if(typeid(*dogs[i])!=typeid(*dogs2[i]))
                cout<<"wrong type loaded for index "<<i<<" (-5)"<<endl;
            if(dogs[i]->getWeight()!=dogs2[i]->getWeight())
                cout<<"wrong weight loaded for index "<<i<<" (-1)"<<endl;
            if(dogs[i]->getID()!=dogs2[i]->getID())
                cout<<"wrong ID loaded for index "<<i<<" (-1)"<<endl;
        }
    }
    
    for(int i=0;i<4;i++){
         delete dogs[i];
    }
    delete[] dogs;

    for(int i=0;i<size;i++){
         delete dogs2[i];
    }
    delete[] dogs2;
}

int sum;

class Action1:public Delegate{
    public:
    virtual void operator()(){
        sum+=5;
    };
};

class Action2:public Delegate{
    public:
    virtual void operator()(){
        sum+=10;
    };
};

void test3(){
    sum=0;
    Event e;
    Action1* a1=new Action1();
    Action2* a2=new Action2();
    e+=a1;
    e();
    if(sum!=5)
      cout<<"not executing an action (-10)"<<endl;
    sum=0;
    e+=a2;
    e();
    if(sum!=15)
      cout<<"not executing two actions (-10)"<<endl;
    e+=a1;
    sum=0;
    e();
    if(sum!=20)
      cout<<"not executing three actions (-10)"<<endl;
        

    delete a1;
    delete a2;
}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;
	return 0;
}
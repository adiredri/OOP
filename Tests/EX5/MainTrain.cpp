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
   const Complex a(10,4) , b(3,5);
   
   Complex r1=a+b;
   Complex r2=a-b;
   Complex r3=a*b;
   
   if(r1.getReal()!=13 || r1.getImg()!=9)
    cout<<"wrong implementation of operator+ (-3)"<<endl;
   if(r2.getReal()!=7 || r2.getImg()!=-1)
    cout<<"wrong implementation of operator- (-3)"<<endl;
   if(r3.getReal()!=10 || r3.getImg()!=62)
    cout<<"wrong implementation of operator* (-3)"<<endl;
   
   char text[15];
   stringstream out;
   
   out<<Complex(0,0)<<endl;
   out>>text;
   if(text[0]!='0' || text[1]!='\0')
    cout<<"wrong output for value 0 (-3)"<<endl;
    
   out<<Complex(20,0)<<endl;
   out>>text;
   if(text[0]!='2' || text[1]!='0' || text[2]!='\0')
    cout<<"wrong output for value 20 (-3)"<<endl;

   out<<Complex(0,8)<<endl;
   out>>text;
   if(text[0]!='8' || text[1]!='i' || text[2]!='\0')
    cout<<"wrong output for value 8i (-3)"<<endl;
    
   out<<Complex(0,1)<<endl;
   out>>text;
   if(text[0]!='i' || text[1]!='\0')
    cout<<"wrong output for value i (-3)"<<endl;
    
   out<<Complex(0,-1)<<endl;
   out>>text;
   if(text[0]!='-' || text[1]!='i' || text[2]!='\0')
    cout<<"wrong output for value -i (-3)"<<endl;
    
   out<<Complex(5,1)<<endl;
   out>>text;
   if(text[0]!='5' || text[1]!='+' || text[2]!='i' || text[3]!='\0')
    cout<<"wrong output for value 5+i (-3)"<<endl;
    
   out<<Complex(5,-1)<<endl;
   out>>text;
   if(text[0]!='5' || text[1]!='-' || text[2]!='i' || text[3]!='\0')
    cout<<"wrong output for value 5-i (-3)"<<endl;
}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;
	return 0;
}
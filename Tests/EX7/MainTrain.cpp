#include "Q1.h"
#include "Q2.h"
#include "Q3.h"



void test1(){
    BinTree<int> tree;
    /* the bin tree to create:
            5
		 /     \
        2       8
	   / \     / \
      1   3   7   9
	  
    */
    tree.insert(5); // root
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);

    BinTree<int>::iterator it=tree.getRoot();
    if((*it)!=5)
        cout << "wrong implementation of operator* (-6)" << endl;
    
    *it=6;

    if((*it)!=6)
        cout << "wrong implementation of operator* (-5)" << endl;
    
    ++it; // goes to 2

    if((*it)!=2)
        cout << "wrong implementation of prefix operator++ (-6)" << endl;

    it++; // goes to 3

    if((*it)!=3)
        cout << "wrong implementation of postfix operator++ (-6)" << endl;
    
    --it; // goes up to 2
    
    if((*it)!=2)
        cout << "wrong implementation of prefix operator minus minus (-6)" << endl;
        
    it--; // goes up to 5
    if((*it)!=6)
        cout << "wrong implementation of postfix operator minus minus (-6)" << endl;
	
}


void test2(){
   ofstream out("student.txt");
   DirectStudent(123,95,1,1000).save(out);
   out.close();
 
   ifstream in("student.txt") ;
   DirectStudent s(in);
   in.close();
   
   if(s.getID()!=123)
    cout<<"wrong ID loaded (-7)"<<endl;
   if(s.getAverage()!=95)
    cout<<"wrong average loaded (-7)"<<endl;
   if(s.getYear()!=1)
    cout<<"wrong year loaded (-8)"<<endl;
   if(s.getSalary()!=1000)
    cout<<"wrong salary loaded (-8)"<<endl;
}


void test3(){
    Stream<int> s;
    
    for(int i=1;i<=35;i++)
        s.push(i);
        
    int expectedResult[]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70};
    
    int i=0;
    s.map([](int x){return 2*x;}).reverse().process([&expectedResult,&i](int x){
        if(x!=expectedResult[i])
           cout<<"wrong value in the stream (-1)"<<endl;
        i++;
    });
}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;
	return 0;
}
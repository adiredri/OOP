#include<iostream>
#include <typeinfo>
#include <type_traits>

#include "Tree.h"
#include "covid19.h"
#include "Q2.h"
#include "Q3.h"

using namespace std;

void test1(){
	Tree root(0);
	if(root.getID()!=0)
		cout<<"wrong id (-5)"<<endl;

	root+=1;
	root+=2;
	root+=3;
	/*
		0
	  / | \
	  1 2 3

	 */

	auto it=root.getIterator(); // 0

	if((*it).getID()!=0)
		cout<<"error: id "<<(*it).getID()<<" !=0 of iterator (-5)"<<endl;

	it.down(); // 1
	it.down(); // doesn't do a thing
	if((*it).getID()!=1)
		cout<<"error: id "<<(*it).getID()<<" !=1 of iterator (-5)"<<endl;

	(*it)+=11;
	(*it)+=12;
	(*it)+=13;

	/*
			  0
		   /  |  \
		  1   2   3
		/ | \
	   11 12 13
	 */

	++it; // 2
	++it; // 3
	++it; // still 3

	if((*it).getID()!=3)
		cout<<"error: id "<<(*it).getID()<<" !=3 of iterator (-5)"<<endl;

	it.up(1); // 0
	it.down(); // 1
	it.down(); // 11

	if((*it).getID()!=11)
		cout<<"error: id "<<(*it).getID()<<" !=11 of iterator (-5)"<<endl;

	++it; // 12
	if((*it).getID()!=12)
		cout<<"error: id "<<(*it).getID()<<" !=12 of iterator (-5)"<<endl;

	--it; // 11
	if((*it).getID()!=11)
		cout<<"error: id "<<(*it).getID()<<" !=13 of iterator (-5)"<<endl;

}

void test2(){
	// this tests a simple example

	Manager* m=new Manager();
	m->setCovid19();

	Employee** emps=new Employee*[3];
	emps[0]=new Employee();
	emps[0]->setCovid19();
	emps[1]=new Manager();
	emps[1]->setCovid19();
	emps[2]=new Employee();
	m->setEmps(emps,3);

	Employee** emps1=new Employee*[2];
	emps1[0]=new Employee();
	emps1[0]->setCovid19();
	emps1[1]=new Employee();
	((Manager*)emps[1])->setEmps(emps1,2);

	int x=deepPositiveCount(m);
	float g=x-4;
	if(g<0) g=-g;
	g=30*g/4;
	if(g>30)
		g=30;

	if(x!=4)
		cout<<"wrong number of positive count (-"<<(int)g<<")"<<endl;

	delete m;

}


void test3(){
	if(!is_base_of<Covid19,BrCovid20>())
		cout<<"BrCovid20 should be type of Covid19 (-5)"<<endl;
	if(!is_base_of<Covid19,SaCovid20>())
		cout<<"SaCovid20 should be type of Covid19 (-5)"<<endl;

	if(!is_base_of<BrCovid20,IlCovid21>())
		cout<<"IlCovid21 should be type of BrCovid20 (-5)"<<endl;
	if(!is_base_of<SaCovid20,IlCovid21>())
		cout<<"IlCovid21 should be type of SaCovid20 (-5)"<<endl;


	Covid19* p=new IlCovid21(5000); // success = 3 points
	if(p->getCount()!=1)
		cout<<"Covid19 Object should appear only once in memory (-10)"<<endl;
	if(p->getID()!=972)
		cout<<"Covid19 Object ID should be taken from BrCovid20 (-2)"<<endl;

	delete p;
}


int main(){

	test1();
	test2();
	test3();
	cout<<"done"<<endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "node.h"
#include "employee.h"
#include "Q2.h"
#include "Q3.h"

using namespace std;

struct Sum{
	int sum;
	Sum():sum(0){}

	void operator()(int x){
		sum+=x;
	}
};

int mainTrain1(){

	Node<int> n1(1);
	//...
	Node<int> n2(2);
	Node<int> n3(3);
	Node<int> n4(4);

	n1.setNext(&n2);
	n2.setNext(&n3);
	n3.setNext(&n4);

	// the list is 1->2->3->4

	auto it=n1.begin();
	auto end=n1.end();

	if(*it!=1)
		cout<<"wrong value for *it (-5)"<<endl;

	++it;

	if(*it!=2)
		cout<<"wrong value for *it (-5)"<<endl;

	++it; // 3
	++it; // 4
	++it; // end
	if(it!=end)
		cout<<"it is not at the end of the list (-5)"<<endl;


	Sum s;
	s=for_each(n1.begin(),n1.end(),s);
	if(s.sum!=1+2+3+4)
		cout<<"you did not make for_each work for type Node (-20)"<<endl;

	cout<<"done"<<endl;
	return 0;
}

int mainTrain2(){

	list<Employee*> emps;
	emps.push_back(new Employee("Eli Khalastchi",3.14));
	emps.push_back(new Employee("Yehuda Elmalech",2.71));
	emps.push_back(new Manager("Igor Rochlin",1,'A'));

	saveEmps("train1.txt",emps);
	list<Employee*> emps2=loadEmps("train1.txt");

	auto it=emps.begin();
	auto it2=emps2.begin();

	for(int i=0;i<3;++i){
		if(!(*it)->equals(**it2))
			cout<<"wrong Employee saved or loaded (-10)"<<endl;
		++it;
		++it2;
	}

	for(Employee* e : emps)
		delete e;

	for(Employee* e : emps2)
		delete e;

	cout<<"done"<<endl;
	return 0;
}

int mainTrain3(){
	vector<Point> v;
	v.push_back(Point(10,20));
	v.push_back(Point(-10,-10));
	v.push_back(Point(15,11));

	// average point is 5,7

	sortPoints(v);

	// the new order:
	// 	point		distance to average
	//	15,11 		10.7703
	//	10,20 		13.9284
	//	-10,-10 	22.6716

	if(v[0].x!=15 || v[0].y!=11)
		cout<<"wrong order for first point (-12)"<<endl;
	if(v[1].x!=10 || v[1].y!=20)
		cout<<"wrong order for second point (-12)"<<endl;
	if(v[2].x!=-10 || v[2].y!=-10)
		cout<<"wrong order for third point (-11)"<<endl;

	cout<<"done"<<endl;
	return 0;
}

int main(){
	mainTrain1();
	mainTrain2();
	mainTrain3();
	return 0;
}

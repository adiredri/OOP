#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#include "Student.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"

void test1() { // question 1 test
	Vector<int> arr(4);
	arr.add(3);
	if (arr.itemInPos(0) != 3)
		cout << "wrong value for adding in vector (-2)" << endl;
	arr.add(6);
	if (arr.itemInPos(1) != 6)
		cout << "wrong value for adding in vector (-2)" << endl;
	arr.add(8);
	if (arr.itemInPos(2) != 8)
		cout << "wrong value for adding in vector (-2)" << endl;
	arr.add(1);
	if (arr.itemInPos(3) != 1)
		cout << "wrong value for adding in vector (-2)" << endl;

	arr.add(9);
	if (arr.itemInPos(3) != 1)
		cout << "wrong value for adding in vector (-2)" << endl;

	Vector<int> arr2(4);
	arr2.add(3);
	arr2.add(6);
	arr2.add(8);
	arr2.add(1);

	if (arr2.isEqual(arr) == false)
		cout << "wrong value for isEqual in vector (-8)" << endl;

	Vector<double> arr3(3);
	arr3.add(1.1);
	arr3.add(2.1);
	arr3.add(3.1);
	arr3.itemInPos(1) = 7.1;

	if (arr3.itemInPos(1) != 7.1)
		cout << "wrong value for changing item in vector(-7)" << endl;
}



void test2(){ // question 2 test
    float grades[5]={85,50,91,78,98};
    Student e(1234, "Bjarne Stroustrup", 5 , grades);
    save("train.stu",e);
    e.compareTo(load("train.stu"));
}


void test3() { // question 3 test
	Radio r;
	if (r.getFreq() != 91.8f)
		cout << "wrong initial value for radio (-2)" << endl;

	++r;

	if (r.getFreq() != 99.0f)
		cout << "wrong value for radio after op++ (-2)" << endl;

	Radio r2;
	r2 = ++r;

	if (r2.getFreq() != 94.4f)
		cout << "wrong value for radio after op++ (-2)" << endl;

	--r;

	if (r.getFreq() != 99.0f)
		cout << "wrong value for radio after op-- (-2)" << endl;

	--r; // Galgalatz
	--r; // Radio 103

	if (r.getFreq() != 103.0f)
		cout << "wrong value for radio after op-- with rounding (-3)" << endl;

	++r;
	if (r.getFreq() != 91.8f)
		cout << "wrong value for radio after op++ with rounding (-2)" << endl;

	r += 8;
	if (r.getVolume() != 18)
		cout << "wrong value for radio after op+= (-3)" << endl;

	r += 10;
	if (r.getVolume() != 20)
		cout << "wrong value for radio after op+= with rounding (-2)" << endl;

	r -= 22;
	if (r.getVolume() != 0)
		cout << "wrong value for radio after op-= with rounding (-2)" << endl;

	r(4);
	if (r.getFreq() != 95.5f)
		cout << "wrong value for radio after op() (-3)" << endl;

	r[8];
	if (r.getVolume() != 8)
		cout << "wrong value for radio after op[] (-2)" << endl;
}

void test4() { // question 4 test
	float grades[10] = { 85,90,50,60,91,70,78,98,99,100 };
	Student* s1 = new Student(10, "Moshe Cohen", 10, grades);
	for (int i = 0; i < 10; i++)
		grades[i] -= 5;
	Student* s2 = new Student(20, "Israel Israeli", 10, grades);
	for (int i = 0; i < 10; i++)
		grades[i] -= 10;
	Student* s3 = new Student(30, "Ananda Lev", 10, grades);

	Student* arr[] = { s1,s2,s3 }; // some pointers to students

	StuSorter* s = new NameStuSorter();
	s->bubbleSort(arr, 3); // sorts by Name

	if (!(arr[0]->getName()[0] == 'A' &&
		  arr[1]->getName()[0] == 'I' &&
		  arr[2]->getName()[0] == 'M'))
		cout << "sorting by Name error (-12)" << endl;

	delete s;

	s = new AvgStuSorter();
	s->bubbleSort(arr, 3); // sorts by Average
	if (!(arr[0]->getAVG() < arr[1]->getAVG() && arr[1]->getAVG() < arr[2]->getAVG()))
		cout << "sorting by average error (-12)" << endl;

	delete s1;
	delete s2;
	delete s3;
}

int main()
{
	test1();
	test2();
	test3();
    test4();
    cout<<"done"<<endl;

    return 0;
}



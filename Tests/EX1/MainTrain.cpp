
#include "Student.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include <sstream>

using namespace std;
void testQ2();
void testQ1();
void testQ3();

int main() {
	// test API:
	//testQ1API();
	//testQ2API();
	//testQ3API();

	// Train Mode:
	testQ1();
	testQ2();
	testQ3();
	cout << "done" << endl;
	return 0;
}



struct nameCollector {
	int i;
	char output[4];
	nameCollector() :i(0) { output[3] = '\0'; }
	void operator()(Student& s) {
		output[i] = s.getName();
		i++;
	}
};

void testQ1() {
	Map<Student> map;
	map.put("X", Student('X', 25));
	map.put("Y", Student('Y', 22));
	map.put("Z", Student('Z', 26));
	nameCollector nc;
	nc=map.forEachValue(nc);
	if (strcmp(nc.output, "ZYX") != 0) {
	cout << "put method does not place items in the head of the list (-10)" << endl;
	}

	
	if(map["Y"].getAge()!=22)
	cout<<"operator[] does not return the correct student (-5)"<< endl;

}

void testQ2() {
	ostringstream str;
	Student*s2 = new MAStudent('B', 25, false);
	s2->print(str);
	if (str.str().compare("name: B\nage: 25\nwithout thesis\n") != 0)
		cout << "failed to output MAStudent correctly (-10)" << endl;
	str.str(""); str.clear();

	delete s2;
}

void testQ3(){

	{
		Point3D p;
		p.color = 'r';
		p.x = 3;
		p.y = 4;
		p.z = 5;
		ofstream out("p3d.dat", ios::binary);
		savePoint(p, out);
		out.close();

		ifstream in("p3d.dat", ios::binary);
		Point* pd = loadPoint(in);
		in.close();
		Point3D * p3d = dynamic_cast<Point3D*>(pd);
		if (!(p3d && p3d->color == 'r' && p3d->x == 3 && p3d->y == 4 && p3d->z == 5))
			cout << "problem in saving or loading Point3D (-15)" << endl;

		delete p3d;
	}

}
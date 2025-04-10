#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include<string.h>
#include "Student.h"

using namespace std;
    

template<class T>
void write(ofstream& out, T t){
    out.write((char*)& t,sizeof(T));
}
template<class T>
void read(ifstream& in, T& t){
    in.read((char*)& t,sizeof(T));
}

void save(const char* filename, Student& s){
    ofstream out(filename);
    write(out,s.getID());
	int l=strlen(s.getName());
    write(out,l);
	out.write(s.getName(),l);
	write(out,s.getAVG());    
    out.close();
}

Student load(const char* filename){
    ifstream in(filename);
    int id, l;
    read(in,id);
	read(in,l);
    char* name=new char[l+1];
    for(int i=0;i<l;i++)
        read(in,name[i]);
	name[l]='\0';
	float avg;
	read(in,avg);
    in.close();
    Student s(id,name,avg);
    delete[] name;
    return s;
}

#endif /* SRC_Q2_H_ */
#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <fstream>
using namespace std;

template<class T>
void write(ostream& out, T t){
    out.write((char*)&t,sizeof(t));
}

template<class T>
void write(ostream& out, T* arr, int length){
    write(out,length);
    for(int i=0;i<length;i++)
        write<T>(out,arr[i]);
}

template<class T>
T read(ifstream& in){
    T t;
    in.read((char*)&t,sizeof(t));
    return t;
}

template<class T>
T* readBuff(ifstream& in){
    int n;
    n = read<int>(in);
    T* arr=new T[n];
    for(int i=0;i<n;i++)
        arr[i]=read<T>(in);
    return arr;
}

#endif /* SRC_Q2_H_ */
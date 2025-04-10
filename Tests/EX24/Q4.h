#define _CRT_SECURE_NO_WARNINGS

#ifndef SRC_Q4_H_
#define SRC_Q4_H_
#include "Student.h"

using namespace std;

class StuSorter{

  public:

    void bubbleSort(Student** arr, int n){
        int i, j;
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (compare(arr[j] , arr[j + 1])>0) {
                    Student* t=arr[j];
                    arr[j]= arr[j + 1];
                    arr[j + 1]=t;
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
    
    virtual int compare(Student* e1,Student* e2)=0;
};

class NameStuSorter:public StuSorter{
    int compare(Student* e1,Student* e2){
        return strcmp(e1->getName(),e2->getName());
    }
};

class AvgStuSorter:public StuSorter{
    int compare(Student* e1,Student* e2){
        return (int)(e1->getAVG()*1000 - e2->getAVG()*1000);
    }
};

#endif /* SRC_Q4_H_ */

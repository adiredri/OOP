
#ifndef SRC_Q4_H_
#define SRC_Q4_H_

#include "Employee.h"

using namespace std;

class EmpSorter{

  public:

    void bubbleSort(Employee** arr, int n){
        int i, j;
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (compare(arr[j] , arr[j + 1])>0) {
                    Employee* t=arr[j];
                    arr[j]= arr[j + 1];
                    arr[j + 1]=t;
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
    
    virtual int compare(Employee* e1,Employee* e2)=0;
};

class IdEmpSorter:public EmpSorter{
    int compare(Employee* e1,Employee* e2){
        return e1->getID() - e2->getID();
    }
};

class AvgEmpSorter:public EmpSorter{
    int compare(Employee* e1,Employee* e2){
        return (int)(e1->getAVG()*1000 - e2->getAVG()*1000);
    }
};

#endif /* SRC_Q4_H_ */

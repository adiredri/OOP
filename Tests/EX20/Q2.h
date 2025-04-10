#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <typeinfo>
#include "exam.h"

template<class Predicate, class Func>
Func applyIf(Person** arr, int size, Predicate p, Func f) {
    for (int i = 0; i < size; i++) {
        if (p(arr[i]))
            f(arr[i]);
    }
    return f;
}

struct isStudent {
    bool operator()(Person* p) {
        return typeid(p) == typeid(Student);
    }
};

struct Sum {
    int sum = 0;
    void operator()(Person* p) {
        sum += p->id;
    }
    int get() {
        return sum;
    }
};

#endif /* SRC_Q2_H_ */
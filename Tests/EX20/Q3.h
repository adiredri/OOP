#ifndef SRC_Q3_H_
#define SRC_Q3_H_
#include "exam.h"

class PersonListIterator{

    const PersonList* p;

    public:
    PersonListIterator(PersonList* p):p(p){}

    const Person* operator*(){
        return p->item;
    }

    PersonListIterator& operator++(){
        if (p->next!=NULL)
            p=p->next;
        return *this;
    }


    bool hasNext(){
        return p->next!=NULL;
    }
};

#endif /* SRC_Q3_H_ */
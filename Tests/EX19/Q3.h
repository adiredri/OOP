#ifndef SRC_Q3_H_
#define SRC_Q3_H_
#include "exam.h"

class BeingListIterator{

    const BeingList* p;

    public:
    BeingListIterator(BeingList* p):p(p){}

    const Being* operator*(){
        return p->item;
    }

    BeingListIterator& operator++(){
        if (p->next!=NULL)
            p=p->next;
        return *this;
    }


    bool hasNext(){
        return p->next!=NULL;
    }
};

#endif /* SRC_Q3_H_ */
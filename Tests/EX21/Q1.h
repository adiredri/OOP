#ifndef SRC_Q1_H_
#define SRC_Q1_H_

#include "exam.h"

class SamuraiThunderCat: public SamuraiCat, public ThunderCat{
    public:
    SamuraiThunderCat(int id,const SamuraiCat& sc,const ThunderCat& tc):Cat(id),SamuraiCat(sc),ThunderCat(tc){
        int psc=sc.getPowerLevel();
        int ssc=sc.getStealthLevel();
        int ptc=tc.getPowerLevel();
        int stc=tc.getStealthLevel();
        setPowerLevel((psc>ptc?psc:ptc));
        setStealthLevel((ssc>stc?ssc:stc));
	}
};



#endif /* SRC_Q1_H_ */
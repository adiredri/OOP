#ifndef SRC_Q1_H_
#define SRC_Q1_H_

#include "exam.h"

class SamuraiThunderDog: public SamuraiDog, public ThunderDog{
    public:
    SamuraiThunderDog(int id,const SamuraiDog& sc,const ThunderDog& tc):
        Dog(id),SamuraiDog(sc),ThunderDog(tc){
        int psc=sc.getPowerLevel();
        int ssc=sc.getStealthLevel();
        int ptc=tc.getPowerLevel();
        int stc=tc.getStealthLevel();
        setPowerLevel((psc+ptc)/2);
        setStealthLevel((ssc+stc)/2);
	}
};



#endif /* SRC_Q1_H_ */
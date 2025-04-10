#ifndef SRC_EXAM_H_
#define SRC_EXAM_H_

#ifndef NULL
#define NULL 0
#endif

class Cat{
	private:
    int powerLevel;
	int stealthLevel;
	
    public:
    const int id;
    Cat(int id):id(id){
		powerLevel = 1;
		stealthLevel = 1;
	}    
    virtual ~Cat(){}

	int getPowerLevel() const{
        return powerLevel;
    }
    void setPowerLevel(int powerLevel){
        this->powerLevel=powerLevel;
    }
    int getStealthLevel() const{
        return stealthLevel;
    }
    void setStealthLevel(int stealthLevel){
        this->stealthLevel=stealthLevel;
    }
};

class ThunderCat:public virtual Cat{
    public:
    ThunderCat(int id):Cat(id){
		setPowerLevel(10);
		setStealthLevel(5);
	}
};


class SamuraiCat:public virtual Cat{
    public:
    SamuraiCat(int id):Cat(id){
		setPowerLevel(8);
		setStealthLevel(8);
	}
};


template<class T>
struct Array{
    T** array;
    const int length;
    Array(T** array,int length):array(array),length(length){}
};





#endif /* SRC_EXAM_H_ */
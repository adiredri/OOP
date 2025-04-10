#ifndef SRC_EXAM_H_
#define SRC_EXAM_H_

#ifndef NULL
#define NULL 0
#endif

class Dog{
	private:
    int powerLevel;
	int stealthLevel;
	
    public:
    const int id;
    Dog(int id):id(id){
		powerLevel = 1;
		stealthLevel = 1;
	}    
    virtual ~Dog(){}

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

class ThunderDog:public virtual Dog{
    public:
    ThunderDog(int id):Dog(id){
		setPowerLevel(10);
		setStealthLevel(5);
	}
};


class SamuraiDog:public virtual Dog{
    public:
    SamuraiDog(int id):Dog(id){
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
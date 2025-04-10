#ifndef SRC_Q3_H_
#define SRC_Q3_H_

using namespace std;

class Radio{

    const char* names[6]={"Galgalatz","Eco99","Kan Kol Hamusica","Kan 88","Kan Reshset Bet","Radio 103"};
    float freq[6]={ 91.8,99.0,94.4,88.0,95.5,103.0};

    int index;
	int volume;//between 0 to 20

    public:
    Radio(){
        index=0;
		volume = 10;
    }

	float getFreq() {
		return freq[index];
	}

	const char* getName() {
		return names[index];
	}

	int getVolume() {
		return volume;
	}

    Radio& operator++(){
        index++;
        index%=6;
        return *this;
    }
    Radio& operator--(){
        index--;
        if(index<0)
            index+=6;
        return *this;
    }

    Radio& operator+=(int x){
		volume += x;
		if (volume > 20)
			volume = 20;
        return *this;
    }

    Radio& operator-=(int x){
		volume -= x;
		if (volume < 0)
			volume = 0;
        return *this;
    }

	Radio& operator()(int x)
	{
		if (x >= 0 && x <= 6)
			index = x;
		return *this;
	}

	Radio& operator[](int x)
	{
		if (x >= 0 && x <= 20)
			volume = x;
		return *this;
	}
};

#endif /* SRC_Q3_H_ */
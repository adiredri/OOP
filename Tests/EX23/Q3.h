#ifndef SRC_Q3_H_
#define SRC_Q3_H_
using namespace std;

class Piano{

    char notes[14]={'C','D','E','F','G','A','B','C','D','E','F','G','A','B'};
    float freq[14]={130.81,146.83,164.81,174.61,196,220,246.93,261.63,293.66,329.63,349.23,392,440,493.88};

    int index;

    public:
    Piano(){
        index=0;
    }

    Piano& operator++(){
        index++;
        index%=14;
        return *this;
    }
    Piano& operator--(){
        index--;
        if(index<0)
            index+=14;
        return *this;
    }

    Piano& operator+=(int x){
        index+=x;
        index%=14;
        return *this;
    }

    Piano& operator-=(int x){
        index-=x;
        if(index<0){
            int c=index/(-14);
            index+=(c+1)*14;
        }
        return *this;
    }

    float getFreq(){
        return freq[index];
    }

    char getNote(){
        return notes[index];
    }

};

#endif /* SRC_Q3_H_ */
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "exam.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

using namespace std;

void test1(){
    int totalPoints = 33;
    int pointsPerTest = 11; // Assuming 3 tests, each with 11 points.

    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Random values for the tests
    int randomID1 = rand() % 101; // Random ID between 0 and 100
    bool randomHasWings1 = rand() % 2; // Random bool (0 or 1)
    char randomColor1 = 'a' + rand() % 26; // Random char between 'a' and 'z'
    int randomPower1 = rand() % 101; // Random power between 0 and 100

    int randomID2 = rand() % 101;
    bool randomHasWings2 = rand() % 2;
    char randomColor2 = 'a' + rand() % 26;
    int randomPower2 = rand() % 101;

    int randomID3 = rand() % 101;
    bool randomHasWings3 = rand() % 2;
    char randomColor3 = 'a' + rand() % 26;
    int randomPower3 = rand() % 101;

    // Test 1: Default unicorn creation
    Unicorn defaultUnicorn = UnicornCreator().build();
    if (defaultUnicorn.id != 0 || defaultUnicorn.hasWings != false || defaultUnicorn.color != 'w' || defaultUnicorn.power != 0) {
        cout << "Default unicorn creation failed. (-" << pointsPerTest << ")\n";
        totalPoints -= pointsPerTest;
    }

    // Test 2: Custom unicorn creation
    Unicorn customUnicorn = UnicornCreator().setID(randomID1).addWings().setColor(randomColor1).setPower(randomPower1).build();
    if (customUnicorn.id != randomID1 || customUnicorn.hasWings != true || customUnicorn.color != randomColor1 || customUnicorn.power != randomPower1) {
        cout << "Custom unicorn creation failed. (-" << pointsPerTest << ")\n";
        totalPoints -= pointsPerTest;
    }

    // Test 3: Partial unicorn creation
    Unicorn partialUnicorn = UnicornCreator().setID(randomID2).setColor(randomColor2).build();
    if (partialUnicorn.id != randomID2 || partialUnicorn.hasWings != false || partialUnicorn.color != randomColor2 || partialUnicorn.power != 0) {
        cout << "Partial unicorn creation failed. (-" << pointsPerTest << ")\n";
        totalPoints -= pointsPerTest;
    }    
}

void test2(){
    int x=rand()%101;
    double y= rand()%101;
    char z = 'a' + rand()%28;
    const char* str="some test string";
    float* farr=new float[x];
    for(int i=0;i<x;i++)
        farr[i]=rand()%101;

    ofstream out("test.bin");
    write(out,x); // int
    write(out,y); // double
    write(out,z); // char
    write(out,str,16); // char array
    write(out,farr,x); // float array
    out.close();

    ifstream in("test.bin");
    int x1=read<int>(in);
    double y1=read<double>(in);
    char z1=read<char>(in);
    char* str2=readBuff<char>(in);
    float* farr2=readBuff<float>(in);
    in.close();

    if(x1!=x)
        cout<<"wrong value for handling int (-6)"<<endl;
    if(y1!=y)
        cout<<"wrong value for handling double (-6)"<<endl;
    if(z1!=z)
        cout<<"wrong value for handling char (-6)"<<endl;
    
    
    bool ok=true;
    for(int i=0;i<16;i++){
        if(str[i]!=str2[i]){
            ok=false;            
            break;
        }
    }
    if(!ok)
        cout<<"wrong value for handling char array (-7)"<<endl;
    
    ok=true;
    for(int i=0;i<x;i++){
        if(farr[i]!=farr2[i]){
            ok=false;            
            break;
        }
    }
    if(!ok)
        cout<<"wrong value for handling float array (-7)"<<endl;



    delete [] farr;
    delete [] farr2;
    delete [] str2;
}


void test3(){
    Piano p;
    if (p.getFreq()!=130.81f || p.getNote()!='C')
        cout<<"wrong initial value for piano (-2)"<<endl;
    
    ++p;

    if (p.getFreq()!=146.83f || p.getNote()!='D')
        cout<<"wrong value for piano after op++ (-3)"<<endl;

    ++p;

    if (p.getFreq()!=164.81f || p.getNote()!='E')
        cout<<"wrong value for piano after op++ (-2)"<<endl;

    --p;

    if (p.getFreq()!=146.83f || p.getNote()!='D')
        cout<<"wrong value for piano after op-- (-3)"<<endl;

    --p; // C
    --p; // B

    if (p.getFreq()!=493.88f || p.getNote()!='B')
        cout<<"wrong value for piano after op-- with rounding (-5)"<<endl;

    ++p;
    if (p.getFreq()!=130.81f || p.getNote()!='C')
        cout<<"wrong value for piano after op++ with rounding (-5)"<<endl;
    
    p+=8;
    if (p.getFreq()!=293.66f || p.getNote()!='D')
        cout<<"wrong value for piano after op+= (-5)"<<endl;
    
    p+=10;
    if (p.getFreq()!=196 || p.getNote()!='G')
        cout<<"wrong value for piano after op+= with rounding (-5)"<<endl;

    p-=8;
    if (p.getFreq()!=349.23f || p.getNote()!='F')
        cout<<"wrong value for piano after op-= with rounding (-5)"<<endl;

}



int main()
{
    test1(); // 33 points
    test2(); // 32 points
    test3(); // 35 points


    cout<<"done"<<endl;
    return 0;
}

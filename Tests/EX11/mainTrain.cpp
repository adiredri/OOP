#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Q1.h"
#include "Q2.h"

template<class T>
bool test(Box<T>& box,const char* s){
    char str[50];
    stringstream ss;
    ss<<box<<endl;
    ss>>str;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]!=str[i])
            return false;
        i++;
    }
    return str[i]=='\0';
}


void test1(){ // 6 checks for Q1, each equals 5 points
    Box<int> bint;
    cout<<bint<<endl; // output: {}
    if(!test(bint,"{}"))
        cout<<"wrong output for test0 (-5)"<<endl;
        
    bint+=5;
    bint+=1;
    bint+=2;
    cout<<bint<<endl; // output: {5,1,2}
    
    // check output
    if(!test(bint,"{5,1,2}"))
        cout<<"wrong output for test1 (-5)"<<endl;
    
    Box< Box<int> > bbint;
    bbint+=bint;
    cout<<bbint<<endl; // output: {{5,1,2}} 
    if(!test(bbint,"{{5,1,2}}"))
        cout<<"wrong output for test2 (-10)"<<endl;

    bbint+=bint;
    cout<<bbint<<endl; // output: {{5,1,2},{5,1,2}} 
    if(!test(bbint,"{{5,1,2},{5,1,2}}"))
        cout<<"wrong output for test3 (-10)"<<endl;
    
    Box< Box < Box<int> > > bbbint;
    bbbint+=bbint;
    cout<<bbbint<<endl; // output: {{{5,1,2},{5,1,2}}}
    if(!test(bbbint,"{{{5,1,2},{5,1,2}}}"))
        cout<<"wrong output for test4 (-10)"<<endl;
    
    bbbint+=bbint;
    cout<<bbbint<<endl; // output: {{{5,1,2},{5,1,2}},{{5,1,2},{5,1,2}}}
    if(!test(bbbint,"{{{5,1,2},{5,1,2}},{{5,1,2},{5,1,2}}}"))
        cout<<"wrong output for test5 (-10)"<<endl;

}	


void test2(){
    UndergradStudent s1(1);
    UndergradStudent s2(2);
    MAStudent s3(3);
    PhDStudent s4(4);
    DirectStudent s5(5);
    DirectStudent s6(6);

    // notice that not all the cases are tested!
    bool test[10];
    test[0]=s1.help(s2);    // true
    test[1]=s1.help(s3);    // false
    test[2]=s1.help(s4);    // false
    test[3]=s1.help(s5);    // false
    test[4]=s3.help(s2);    // true
    test[5]=s3.help(s4);    // false
    test[6]=s4.help(s2);    // true
    test[7]=s4.help(s3);    // true
    test[8]=s5.help(s6);    // true
    test[9]=s5.help(s4);    // false
    
    bool result[]={1,0,0,0,1,0,1,1,1,0};
    
    for(int i=0;i<10;i++)
        if(test[i]!=result[i])
            cout<<"wrong result for test "<<i+1<<" (-5)"<<endl;

}

int main()
{
	test1();
	test2();
	cout<<"done"<<endl;
	return 0;
}

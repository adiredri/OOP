#include<iostream>
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Student.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<algorithm>

using namespace std;

void test1a(){ // question 1.a test
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    
    int c=countIf(v.begin(),v.end(),[](int i){return i%2==0;});
    if(c!=5){
        cout<<"wrong result for count_if (-5)"<<endl;
        return;
    }

    vector<float> v1;
    for(float i=0;i<5;i+=0.5f)
        v1.push_back(i);
        
    c=count_if(v1.begin(),v1.end(),[](float i){return i>2.5f;});
    
    if(c!=4){
        cout<<"wrong result for count_if (-5)"<<endl;
        return;
    }
    
    
}

void test1b(){ // question 1.b test
    for(int t=0;t<3;t++){
        int size=(1+rand()%10)*2 + 1; // odd random size
        // init different random numbers
        vector<int> v;
        for(int i=0;i<size;i++){
            int x=rand() % 100 + 1;
            while(find(v.begin(),v.end(),x)!=v.end())
                x=rand() % 100 + 1;
                
            v.push_back(x);
        }

        int md = mid(v);

        int countS=0;
        int countB=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<md)
                countS++;
            if(v[i]>md)
                countB++;
        }
        if(countS!=countB)
            cout<<"wrong mid returned (-5)"<<endl;
    }
}



void test2(){ // question 2 test
    Student s(1234, "Yerachmiel" , 85.3);
    save("train.std",s);
    s.compareTo(load("train.std"));
}
bool testDate(Date d,int day, int month, int year){
    return d.getDay()==day && d.getMonth()==month && d.getYear()==year;
}

void test3(){ // question 3 test
    Date d(7,3,1981);
    
    ++d;
    if(!testDate(d,8,3,1981))
        cout<<"wrong result for op++ (-4)"<<endl;
    
    d.set(7,3,1981);
    --d; // 6.03.81
    --d; // 5.03.81
    --d; // 4.03.81
    --d; // 3.03.81
    --d; // 2.03.81
    --d; // 1.03.81
    --d; // 30.02.81
    if(!testDate(d,30,2,1981))
        cout<<"wrong result for op-- (-4)"<<endl;
        
    d.set(7,3,1981);
    d+=24; // 01.04.81;
    if(!testDate(d,1,4,1981))
        cout<<"wrong result for op+= (-4)"<<endl;

    d.set(7,3,1981);
    d-=64; // -7 --> 30.02.81, -30--> 30.01.81, -27--> 03.01.81;
    if(!testDate(d,3,1,1981))
        cout<<"wrong result for op-= (-4)"<<endl;
    
    d.set(7,3,1981);
    d*=12; // 07.03.1982
    if(!testDate(d,7,3,1982))
        cout<<"wrong result for op*= (-4)"<<endl;

    d.set(7,3,1981);
    d/=15; // -12-->07.03.1980, -3-->07.12.1979
    if(!testDate(d,7,12,1979))
        cout<<"wrong result for op/= (-4)"<<endl;
    
    d.set(7,3,1981);
    Date d2(7,3,1981);
    Date d3(3,7,1981);
    if(d==d3 || !(d==d2))
        cout<<"wrong result for op== (-1)"<<endl;

}

Student* max(Student** arr,int size,StudentUtil& su){
    Student *s=arr[0];
    for(int i=1;i<size;i++){
        if(su.areEqual(su.max(*s,*arr[i]),*arr[i]))
            s=arr[i];
    }
    return s;
}

Student* min(Student** arr,int size,StudentUtil& su){
    Student *s=arr[0];
    for(int i=1;i<size;i++){
        if(su.areEqual(su.min(*s,*arr[i]),*arr[i]))
            s=arr[i];
    }
    return s;
}


void test4(){ // question 4 test
    Student** arr=new Student*[3];
    
    Student* s1=new Student(1,"Alice",100);
    Student* s2=new Student(2,"Bob",90);
    Student* s3=new Student(3,"Charlie",80);
    
    arr[0]=s1;
    arr[1]=s2;
    arr[2]=s3;
    
    StudentAVGUtil sau;
    StudentNameUtil snu;
    
    if(max(arr,3,sau)!=s1)
        cout<<"wrong result for max with AVGUtil (-6)"<<endl;
    if(min(arr,3,sau)!=s3)
        cout<<"wrong result for min with AVGUtil (-6)"<<endl;
    
    if(max(arr,3,snu)!=s3)
        cout<<"wrong result for max with NameUtil (-6)"<<endl;
    if(min(arr,3,snu)!=s1)
        cout<<"wrong result for min with NameUtil (-6)"<<endl;
        
    delete s1;
    delete s2;
    delete s3;
    delete [] arr;
}

int main()
{
	srand (time(NULL));
    test1a();
    test1b();
    test2();
    test3();
	test4();
    cout<<"done"<<endl;

    return 0;
}



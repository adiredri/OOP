#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Q1.h"
#include "Q2.h"

void test1(){
	SetInt s1(1),s2(2),s3(3),sim(10); // CTOR parameters are IDs
	SuperSet s4(4), s5(5),s6(6);
	
	s1+=1; //s1 = {1}
	s1+=2; //s1 = {1,2}
	s2+=3; //s2 = {3}
	s2+=4; //s2 = {3,4}
	s2+=5; //s2 = {3,4,5}
	s4+=&s1; //s4 = {{1,2}} 
	s4+=&s2; //s4 = {{1,2},{3,4,5}}
	s5+=&s1; //s5 = {{1,2}}
	s5+=&s4; //s5 = {{1,2},{{1,2},{3,4,5}}}
	s3 = s1; //s3 = {1,2}
	s1 = s2; //s1 = {3,4,5}
	s5 = s4; //s5 = {{1,2},{3,4,5}}
	if(s1.isEqual(&s3))
		cout<<"Error: s1 is not equal to s3 (-10)"<<endl;
	s1+=1; //s1 = {3,4,5,1}
	if(s1.isEqual(&s2))
		cout<<"Error: s1 is not equal to s2 (-10)"<<endl;
	s4 = s6; //s4 = {}
	s1 = sim; //s1 = {}
	s1+=1; //s1 = {1}
	s1+=2; //s1 = {1,2}
	s4+=&s1; //s4 = {{1,2}}
	s1 = sim; //s1 = {}
	s1+=3;
	s1+=4;
	s1+=5; //s1 = {3,4,5}
	s4+=&s1; //s4= {{1,2},{3,4,5}}
	if(!(s4.isEqual(&s5)))
		cout<<"Error: s4 is equal to s5 (-30)"<<endl;
}	

int sum(char test[50]){
    int sum=0;
    for(int i=0;i<50;i++)
            sum+=test[i];
    return sum;
}

int sum(char test[50][50]){
    int sum=0;
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            sum+=test[i][j];
    return sum;
}


void test2(){
    srand(time(NULL));
    for(int i=0;i<5;i++){ // 5 checks, each check equals 10 points
    
        Node::initCount();
        Edge::initCount();
        
        int size=10+rand()%50; // a random size
        
        GraphFactory* gf=new GraphFactory();
        
        char testE[50][50],testN[50];
        for(int ti=0;ti<50;ti++){
            testN[ti]=0;
            for(int tj=0;tj<50;testE[ti][tj]=0,tj++);
        }
        
        for(int j=0;j<size;j++){
            int id=rand()%50;
            gf->getNode(id);
            testN[id]=1;
            
            int from=rand()%50,to=rand()%50;
            
            testN[from]=1;
            testN[to]=1;
            
            gf->getEdge(from,to,0.5);
            testE[from][to]=1;
        }
        
        int nodesCount=sum(testN);
        int edgesCount=sum(testE);
        
        if(nodesCount!=Node::getCount())
            cout<<"wrong number of nodes for Q2 test "<<(i+1)<<" expecting "<<nodesCount<<" you created "<<Node::getCount()<<" nodes (-4)"<<endl;
        if(edgesCount!=Edge::getCount())
            cout<<"wrong number of edges for Q2 test "<<(i+1)<<" expecting "<<edgesCount<<" you created "<<Edge::getCount()<<" edges (-4)"<<endl;

        delete gf;
        
        if(Node::getCount()!=0 || Edge::getCount()!=0)
            cout<<"all nodes and edges should be deleted (-2)"<<endl;
        
    }
	
}

int main()
{
	test1();
	test2();
	cout<<"done"<<endl;
	return 0;
}

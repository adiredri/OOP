#include "Q1.h"
#include "node.h"

void testSave(){
	Employee* arr1[5];
	ofstream outFile("out.bin");
	
	arr1[0] = new Manager(10,5000,34567);
	arr1[1] = new Engineer(7,23456783);
	arr1[2] = new Manager(13,6000,3254689);
	arr1[3] = new TeamLeader(9,7,4300,2345534);
	arr1[4] = new TeamLeader(6,5,2000,345345);
	saveAllKindOfEmployee(arr1,5,outFile);
	outFile.close();
	
	int i;
	for(i=0;i<5;i++)
		delete arr1[i];
}

void testQ1(){
	testSave();
	
	ifstream inFile("out.bin");
	Employee** arr2;
	loadAllKindOfEmployee(arr2,inFile);
	
	if(typeid(*(arr2[3])) != typeid(TeamLeader) )
		cout<<"Error: Type of object (-10)"<<endl;
	if(typeid(*(arr2[2])) != typeid(Manager) )
		cout<<"Error: Type of object (-10)"<<endl;
	if(arr2[2]->getId() != 3254689)
		cout<<"Error: Id error (-10)"<<endl;
	if(arr2[3]->getId() != 2345534)
		cout<<"Error: Id error (-10)"<<endl;
	if(typeid(*(arr2[4])) == typeid(TeamLeader))
	{
		TeamLeader* tl = dynamic_cast<TeamLeader*>(arr2[4]);
		if(!tl)
		    cout<<"Problem in Dynamic Cast (-10)"<<endl;
		  else
		  {
		    if(tl->getGroupSize() != 5)
			    cout<<"Error: Type of object (-5)"<<endl;
		  }
	}else cout<<"Error: Type of object (-10)"<<endl;
	
	int i;
	for(i=0;i<5;i++)
		delete arr2[i];
	delete[] arr2;
}

void test1(){
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);

    n1->addEdge(n2,0.5);
    n1->addEdge(n3,0.5);
    n3->addEdge(n2,0.6);
    n2->addEdge(n1,0.3);
    
    delete n1;
    delete n2;
    delete n3;
    if(Edge::getCount()!=0)
        cout<<"some edges are left not deleted (-10)"<<endl;
}

void test2(){
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    n1->addEdge(n2,0.5);
    n1->addEdge(n3,0.5);
    n3->addEdge(n2,0.6);
    n2->addEdge(n1,0.3);
    
    n1->removeEdge(n2);
    if(Edge::getCount()!=3)
        cout<<"the edge was not deleted (-10)"<<endl;

    delete n1;
    delete n2;
    delete n3;
}

void test3(){
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    //n1->addEdge(n2,0.5);
    n1->addEdge(n3,0.5);
    n3->addEdge(n2,0.6);
    n2->addEdge(n1,0.3);
    
    if(n1->hasEdge(n2))
        cout<<"n1 should not have an edge to n2 (-5)"<<endl;
    if(!n2->hasEdge(n1))
        cout<<"n2 should have an edge to n1 (-5)"<<endl; // 1 -> TRUE

    delete n1;
    delete n2;
    delete n3;
}

void test4(){
    Node* n1=new Node(1);
    Node* n2=new Node(2);
    Node* n3=new Node(3);
    //n1->addEdge(n2,0.5);
    n1->addEdge(n3,0.5);
    n3->addEdge(n2,0.6);
    n2->addEdge(n1,0.3);
    
    list<Node*> path=n1->getPath(n2); // n1->n3->n2;
    
    int sum=0;
    for_each(path.begin(),path.end(),[&sum](Node* n){sum*=10;sum+=n->getID();});
    if(sum!=132)
        cout<<"wrong path returned (-20)"<<endl;

    delete n1;
    delete n2;
    delete n3;
}
int main(){
	// Q1:
	testQ1();
	// Q2:
    test1();
    test2();
    test3();
    test4();
    cout<<"done"<<endl;
    return 0;
}
#include <iostream>
#include <list>
#include<typeinfo>
#include<algorithm>
using namespace std;

template<class A,class B>
class BiGraph{
    
    class Node{
        public:
        list<Node*> neighbors;
        virtual void nowItsPolymorphic(){}
    };
    
    class NodeA:public Node{
        public:
        A a;
    };
    class NodeB:public Node{
        public:
        B b;
    };
    
    list<Node*> nodes;
    
    public:
    void add(A a){
        NodeA* n=new NodeA();
        n->a=a;
        nodes.push_back(n);
    }
    void add(B b){
        NodeB* n=new NodeB();
        n->b=b;
        nodes.push_back(n);
    }
    
    void connect(A a, B b){
        Node *na=NULL, *nb=NULL;
        typename list<Node*>::iterator it=nodes.begin();
        while(it!=nodes.end() && (na==NULL || nb==NULL)){

            if(typeid(**it)==typeid(NodeA) && ((NodeA*)(*it))->a==a)
                na=*it;
            
            if(typeid(**it)==typeid(NodeB) && ((NodeB*)(*it))->b==b)
                nb=*it;
                
            it++;
        }
        na->neighbors.push_back(nb);
        nb->neighbors.push_back(na);
    }
    
    list<B> getNeighbors(A a){
        Node* n;
        typename list<Node*>::iterator it=nodes.begin();
        while(it!=nodes.end()){
            if(typeid(**it)==typeid(NodeA) && ((NodeA*)(*it))->a==a){
                n=*it;
                break;
            }
            it++;
        }
        
        list<B> result;
        for_each(n->neighbors.begin(),n->neighbors.end(),[&result](Node* x){result.push_back(((NodeB*)x)->b);});
        
        return result;
    }
    
    list<A> getNeighbors(B b){
        Node* n;
        typename list<Node*>::iterator it=nodes.begin();
        while(it!=nodes.end()){
            if(typeid(**it)==typeid(NodeB) && ((NodeB*)(*it))->b==b){
                n=*it;
                break;
            }
            it++;
        }
        
        list<A> result;
        for_each(n->neighbors.begin(),n->neighbors.end(),[&result](Node* x){result.push_back(((NodeA*)x)->a);});
        
        return result;
    }
    
    
};
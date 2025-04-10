
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
using namespace std;

class GraphFactory{
    vector<Node*> nodes;
    vector<Edge*> edges;
    
    public:
    int sumNew=0,sumEx=0;
    Node* getNode(int id){
        Node* ret=NULL;
        for_each(nodes.begin(),nodes.end(),[&id,&ret](Node* n){
            if(n->getID()==id)
                ret=n;
        });
        
        if(ret==NULL){
            ret=new Node(id);
            nodes.push_back(ret);
        }
        
        return ret;
    }
    
    Edge* getEdge(int idFrom, int idTo, double weight){
        Node* n1=getNode(idFrom);
        Node* n2=getNode(idTo);

        Edge* ret=NULL;
        for_each(edges.begin(),edges.end(),[&n1,&n2,&weight,&ret](Edge* e){
            if(e->getFromNode()==n1 && e->getToNode()==n2 && e->getWeight()==weight)
                ret=e;
        });
        
        if(ret==NULL){
            ret=new Edge(n1,n2,weight);			
            edges.push_back(ret);
        }
        
        return ret;
    }
    
    ~GraphFactory(){
        for_each(nodes.begin(),nodes.end(),[](Node* n){
            delete n;
        });
        for_each(edges.begin(),edges.end(),[](Edge* e){
            delete e;
        });
    }
    
};
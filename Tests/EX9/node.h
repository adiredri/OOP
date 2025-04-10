#include <iostream>

#include <list>
#include <algorithm>
#include "edge.h"
using namespace std;


class Node{
    list<Edge*> edges;
    int id;
    public:
    Node(int id){
        this->id=id;
    }
    int getID(){return id;}
    // given
    void addEdge(Node* to, double weight){
        edges.push_front(new Edge(this,to,weight));
    }
    
    //q1a
    void removeEdge(Node* to){
        Edge* toBeDeleted;
        edges.remove_if([&to,&toBeDeleted](Edge *e){toBeDeleted=e; return (e->getTo()==to);});
        delete toBeDeleted;
    }
    
    // q1b
    bool hasEdge(Node* to){
        list<Edge*>::iterator it=edges.begin();
        while(it!=edges.end() && (*it)->getTo()!=to) it++;
        return it!=edges.end();
    }
    
    // q1c
    list<Node*> getPath(Node* dest){
        list<Node*> path;
        getPath(dest,path);
        path.push_front(this);
        return path;
    }
    
    bool getPath(Node* dest,list<Node*> & path){
        for_each(edges.begin(),edges.end(),[&dest, &path](Edge *e){
           if(e->getTo()==dest){
               path.push_front(e->getTo());
               return true;
           }else{
               bool b=e->getTo()->getPath(dest,path);
               if(b)
                   path.push_front(e->getTo());
               return b;
           } 
        });
    }
    
    // q1d
    ~Node(){
        for_each(edges.begin(),edges.end(),[](Edge* e){delete e;});
    }
};

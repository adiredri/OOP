#include <iostream>
#include <stack>
using namespace std;

template<class Num>
class BinTree{
    
    class Item{
        public:
        Item* left;
        Item* right;
        Num number;
        
        Item(){
            left=NULL;
            right=NULL;
        }
        
        ~Item(){
            delete left;
            delete right;
        }
    };
    
    Item* root;
    int size;
    
    public:
    BinTree(){
        root=new Item();
        size=0;
    }
    
    ~BinTree(){
        delete root;
    }
    
    
    void insert(Num number){
        if(size==0){
            root->number=number;
        } else{
            Item* i=root;
            while(number< i->number && i->left!=NULL) i=i->left;
            while(number> i->number && i->right!=NULL) i=i->right;
            Item* t=new Item();
            t->number=number;
            if(number< i->number) i->left=t;
            if(number> i->number) i->right=t;
        }
        size++;
    }
    
    // ------------------   CHANGE CODE FROM HERE  ---------------
    class iterator{
        stack<Item*> parents;
        Item* p;
        public:
        iterator(Item* i):p(i){}
        Num& operator*(){
            return p->number;
        }
        iterator& operator++(int){
            parents.push(p);
            p=p->right;
            return *this;
        }
        iterator& operator++(){
            parents.push(p);
            p=p->left;
            return *this;
        }
        iterator& operator--(){
            p=parents.top();
            parents.pop();
            return *this;
        }
        iterator& operator--(int){
            p=parents.top();
            parents.pop();
            return *this;
        }

    };
    
    // ------------------   DO NOT CHANGE ANYTHING FROM HERE  ---------------

    iterator getRoot(){ return iterator(root);}

};

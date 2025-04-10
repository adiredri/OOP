#include <iostream>

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
    
    // ------------------   CHANGE CODE FROM HERE  ---------------
   
    void insert(Num number){
        if(size==0){
            root->number=number;
        } else{
            Item* i=root;
            while(i->left!=NULL && i->right!=NULL){
                while(number< i->number && i->left!=NULL) i=i->left;
                while(number> i->number && i->right!=NULL) i=i->right;
            }
            Item* t=new Item();
            t->number=number;
            if(number< i->number) i->left=t;
            if(number> i->number) i->right=t;
        }
        size++;
    }
    
    void deleteSubTree(Num number){
        Item* i=root;
        Item* prev;
        while(i!=NULL && i->number!=number){
            prev=i;
            if(number < i->number)
                i=i->left;
            else
                if(number > i->number)
                    i=i->right;
        }
         if(i!=NULL && number==i->number){
             if(prev->left==i)
                prev->left=NULL;
            else
                prev->right=NULL;
             delete i;
         }
    }
    
    
    template<class func>
    void forEach(func f){
        apply(f,root);
    }
    
    private:
    template<class func>
    void apply(func f,Item* i){
        if(i!=NULL){
            f(i->number);
            apply(f,i->left);
            apply(f,i->right);
        }
    }
    
    // ------------------   DO NOT CHANGE ANYTHING FROM HERE  ---------------
    public:
    void print(ostream& out){
        printData=new Num*[size];
        for(int i=0;i<size;i++){
            printData[i]=new Num[size];
            for(int j=0;j<size;j++)
                printData[i][j]=0;
        }
        
        print(root,0,size/2);
        
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
                if(printData[i][j]==0)
                    out<<" ";
                else
                    out<<printData[i][j];

            out<<endl;
        }
        // delete
        for(int i=0;i<size;i++)
            delete[] printData[i];
        delete[] printData;
        
    }
    
    private:
    Num** printData;
    void print(Item* i,int level,int col){
        printData[level][col]=i->number;
        if(i->left!=NULL)
            print(i->left,level+1,col-1);
        if(i->right!=NULL)
            print(i->right,level+1,col+1);
    }
};



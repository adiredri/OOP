
class Node;
class Edge{
    static int count;
    Node *from, *to;
    double weight;
    public:
    Edge(Node* from, Node* to,double weight){
        this->from=from;
        this->to=to;
        this->weight=weight;
        count++;
    }
    
    Node* getTo(){
        return to;
    }
    
    ~Edge(){
        count--;
    }
    
    static int getCount(){ return count;}
    
};
int Edge::count=0;

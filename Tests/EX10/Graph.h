class GraphFactory;

class Node{
    static int count;
    int id;
    
    Node(int id){
        this->id=id;
        count++;
    }
    
    ~Node(){
        count--;
    }
    
    friend class GraphFactory;
    
    public:
    int getID(){ return id;}
    static void initCount(){ count=0;}
    static int getCount(){return count;}
};
int Node::count=0;

class Edge{
    static int count;
    Node *from, *to;
    double weight;
    
    Edge(Node *from,Node *to,double weight){
        this->from=from;
        this->to=to;
        this->weight=weight;
        count++;
    }
    ~Edge(){
        count--;
    }
    
    friend class GraphFactory;
    
    public:
    Node* getFromNode(){ return from;}
    Node* getToNode(){ return to;}
    double getWeight(){return weight;}
    static void initCount(){ count=0;}
    static int getCount(){return count;}
};
int Edge::count=0;

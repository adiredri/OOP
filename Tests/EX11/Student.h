class Student{
    protected:
    int id;
    
    public:
    Student(int id){
        this->id=id;
    }
    
    virtual bool help(Student& s)=0;
    
    virtual ~Student(){ }
};

#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>

using namespace std;

class Employee
{
	int _id;
	public:
	Employee(){}
	Employee(int id){_id = id;}
	void save(ofstream& out){
		out.write((char*)&_id, sizeof(_id));
		saveAdditional(out);
	}
	void load(ifstream& in)
	{
		in.read((char*)&_id, sizeof(_id));
		loadAdditional(in);
	}
	int getId()const{return _id;}
	virtual void loadAdditional(ifstream& in)=0;
	virtual void saveAdditional(ofstream& out)=0;
	virtual void saveType(ofstream& out) = 0;
	
	virtual ~Employee(){}
};

class Engineer: virtual public Employee
{
	int _experience;
	public:
	Engineer(){}
	Engineer(int experience, int id):Employee(id),_experience(experience){}
	void saveAdditional(ofstream& out)
	{
		out.write((char*)&_experience, sizeof(_experience));
	}
	virtual void loadAdditional(ifstream& in)
	{
		in.read((char*)&_experience, sizeof(_experience));
	}
	virtual void saveType(ofstream& out){
		out.write("En",2);
	}
	int getExperience()const {return _experience;}
};
class Manager: virtual public Employee
{
	int _groupSize;
	int _bonus;
	public:
	Manager(){}
	Manager(int groupSize, int bonus, int id):
		Employee(id),_groupSize(groupSize),_bonus(bonus){}
	void saveAdditional(ofstream& out)
	{
		out.write((char*)&_groupSize, sizeof(_groupSize));
		out.write((char*)&_bonus, sizeof(_bonus));
	}
	void loadAdditional(ifstream& in)
	{
		in.read((char*)&_groupSize, sizeof(_groupSize));
		in.read((char*)&_bonus, sizeof(_bonus));
	}
	virtual void saveType(ofstream& out){
		out.write("Ma",2);
	}	
	int getGroupSize()const {return _groupSize;}
	int getBonus()const {return _bonus;}
};

class TeamLeader: public Engineer, public Manager
{
	public:
	TeamLeader(){}
	TeamLeader(int experience, int groupSize, int bonus,int id):
		Employee(id), Engineer(experience, id), Manager(groupSize, bonus, id){}
	void saveAdditional(ofstream& out)
	{
		Engineer::saveAdditional(out);
		Manager::saveAdditional(out);
	}
	void loadAdditional(ifstream& in)
	{
		Engineer::loadAdditional(in);
		Manager::loadAdditional(in);
	}
	virtual void saveType(ofstream& out){
		out.write("Te",2);
	}	
};

void saveAllKindOfEmployee(Employee** em, int size, ofstream& out)
{
	int i;
	out.write((char*)&size,sizeof(size));
	for(i=0;i<size;i++)
	{
		em[i]->saveType(out);
		em[i]->save(out);
	}
}

void loadAllKindOfEmployee(Employee**& em, ifstream& in)
{
	int i;
	char type[2];
	int size;
	in.read((char*)&size, sizeof(size));
	em=new Employee*[size];
	for(i=0;i<size;i++)
	{
		in.read(type,2*sizeof(char));
		if(strncmp(type,"En",2) == 0)
			em[i] = new Engineer();
		else if(strncmp(type,"Ma",2) == 0)
			em[i] = new Manager();
		else if(strncmp(type,"Te",2) == 0)
			em[i] = new TeamLeader();
		
		em[i]->load(in);
	}
}





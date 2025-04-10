#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>

using namespace std;

class Set
{
	int _id;
	public:
	Set(int id): _id(id){}
	virtual void print() = 0;
	virtual bool isEqual(Set* s) = 0;
	virtual ~Set(){}
};
class SetInt: public Set
{
	int* arr;
	int size;
	public:
	SetInt(int id):Set(id){ arr = NULL; size = 0;}
	SetInt(const SetInt& si):Set(si)
	{
		arr = NULL;
		*this = si;
	}
	const SetInt& operator=(const SetInt& s)
	{
		int i;
		if(this != &s)
		{
			delete [] arr;
			Set::operator=(s);
			arr = new int[s.size];
			size = s.size;
			for(i=0;i<size;i++)
				arr[i] = s.arr[i];
		}
		return *this;
	}
	SetInt& operator+=(int num)
	{
		int i;
		int* tmp = new int[size+1];
		for(i=0;i<size;i++)
			tmp[i] = arr[i];
		tmp[i] = num;
		delete [] arr;
		arr = tmp;
		size++;	
		return *this;
	}
	
	virtual void print()
	{
		int i;
		cout<<"{";
		for(i=0;i<size-1;i++)
			cout<<arr[i]<<", ";
		cout<<arr[i]<<"}";
	}
	virtual bool isEqual(Set* s)
	{
		int i,j;
		SetInt* p;
		if(typeid(*s) != typeid(SetInt))
			return false;
		
		p = (SetInt*)s;
		if(size != p->size)
			return false;
		int* elementSeen = new int[size];
		for(i=0;i<size;i++)
			elementSeen[i] = 0;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				if((arr[i] == p->arr[j]) &&
					(elementSeen[j] == 0))
					{
						elementSeen[j] = 1;
						break;
					}
		for(j=0;j<size;j++)
			if(elementSeen[j] == 0)
			{
				delete [] elementSeen;
				return false;
			}
		delete [] elementSeen;
		return true;
	}
	virtual ~SetInt(){
		delete [] arr;
	}	
};

class SuperSet: public Set
{
	Set** arr;
	int size;
	public:
	SuperSet(int id):Set(id),arr(NULL),size(0){}
	SuperSet(const SuperSet& si):Set(si)
	{
		arr = NULL;
		*this = si;
	}
	const SuperSet& operator=(const SuperSet& s)
	{
		int i;
		if(this != &s)
		{
			if(arr != NULL)
			{
				for(i=0;i<size;i++)
					delete arr[i];
				delete [] arr;
			}
			Set::operator=(s);
			arr = new Set*[s.size];
			size = s.size;
			for(i=0;i<size;i++)
			{
				if(typeid(*(s.arr[i])) == typeid(SetInt))
				{
					SetInt *p = (SetInt*)(s.arr[i]);
					arr[i] = new SetInt(*p);
				}
				else if(typeid(*(s.arr[i])) == typeid(SuperSet))
				{
					SuperSet *p = (SuperSet*)(s.arr[i]);
					arr[i] = new SuperSet(*p);
				}
			}
		}
		return *this;
	}
	
	SuperSet& operator+=(Set* s)
	{
		Set** tmp;
		int i;
		tmp = new Set*[size+1];
		for(i=0;i<size;i++)
			tmp[i] = arr[i];
		if(typeid(*s) == typeid(SetInt))
		{
			SetInt* p = (SetInt*)s;
			tmp[i] = new SetInt(*p);
		}
		else //(typeid(*s) == typeid(SuperSet))
		{
			SuperSet* p = (SuperSet*)s;
			tmp[i] = new SuperSet(*p);
		}
		size++;
		delete [] arr;
		arr = tmp;
		return *this;
	}
	virtual void print()
	{
		int i;
		cout<<"{";
		for(i=0;i<size-1;i++)
		{
			arr[i]->print();
			cout<<", ";
		}
		arr[i]->print();
		cout<<"}";
	}
	virtual bool isEqual(Set* s)
	{
		int i,j;
		SuperSet* p;
		if(typeid(*s) != typeid(SuperSet))
			return false;
		p = (SuperSet*)s;
		if(size != p->size)
			return false;
		int* elementSeen = new int[size];
		for(i=0;i<size;i++)
			elementSeen[i] = 0;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				if((elementSeen[j] == 0) &&
					(arr[i]->isEqual(p->arr[j])))
				{
					elementSeen[j] = 1;
					break;
				}
		for(j=0;j<size;j++)
			if(elementSeen[j] == 0)
			{
				delete [] elementSeen;
				return false;
			}
		delete [] elementSeen;
		return true;
	}
	virtual ~SuperSet(){
		int i;
		for(i=0;i<size; i++)
			delete arr[i];
		delete [] arr;
	}
};





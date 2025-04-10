// Adir Edri 206991762

#include "str.h"

Str::Str() {
	m_str = new char[strlen("none") + 1];
	strcpy(m_str, "none");
}

Str::~Str() {
	delete[] m_str;
}

Str::Str(const Str& other) {
	m_str = nullptr;
	*this = other;//opretor=
}

Str::Str(const char* str) {
	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);
}

const Str& Str::operator=(const Str& other) {
	if (this != &other) {
		delete[]m_str;
		m_str = new char[strlen(other.m_str) + 1];
		strcpy(m_str,other.m_str);
	}
	return *this;
}

const Str& Str::operator=(const char* str) {
	delete[]m_str;
	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);
	return *this;
}

bool Str::operator==(const Str& other) const {
	int res = strcmp(m_str, other.getStr());
	if (res == 0)
		return true;

	else
		return false;
}

bool Str::operator!=(const Str& other) const {
	return !(*this == other);
}

bool Str::operator>(const Str& other) const {
	int res = strcmp(m_str, other.getStr());
	if (res > 0)
		return true;

	else
		return false;
}
bool Str::operator<(const Str& other) const {
	int res = strcmp(m_str, other.getStr());
	if (res <  0)
		return true;

	else
		return false;
}

char& Str::operator[](int index) const {
	if (index < 0 || index >= strlen(m_str))
		return m_str[0];
	return m_str[index];
}

const Str& Str::operator++() { //prefix
	for (int i = 0; i < strlen(m_str); i++) {
		m_str[i] = (m_str[i] + 1) % 128;
	}
	return *this;
}
Str Str::operator++(int) { //after
	Str oldstring(*this);
	++(*this);
	return oldstring;
}

Str::operator int() const {
	if (m_str == NULL)
	{
		return 0;
	}
	return strlen(m_str);
}
int	Str::operator()(char ch) const {

	for (int i = 0; i < strlen(m_str); i++) {
		if(m_str[i] ==ch)
		return i;
	}
	return -1;
}

Str	Str::operator+(const Str& other) const {
	int size = strlen(m_str) + strlen(other.getStr())+1;
	Str newstring;
	delete[] newstring.m_str;
	newstring.m_str = new char[size];
	strcpy(newstring.m_str, m_str);
	strcat(newstring.m_str, other.m_str);
	return newstring;
}

const Str& Str::operator+=(const Str& other) {
	int size = strlen(this->m_str) + strlen(other.m_str) + 1;
	char* newstring = new char[size];
	strcpy(newstring, this->m_str);
	strcat(newstring, other.m_str);
	delete[]this->m_str;
	this->m_str= newstring;
	return *this;
	
}
Str operator+(const char* str, const Str& other) {
	int size = strlen(str) + strlen(other.getStr()) + 1;
	Str newstring;
	delete[] newstring.m_str;
	newstring.m_str = new char[size];
	strcpy(newstring.m_str, str);
	strcat(newstring.m_str, other.m_str);
	return newstring;
	
}
Str operator*(int num, const Str& other) {
	int size = ((strlen(other.getStr())) * num) + 1;
	Str newstring;
	delete[] newstring.m_str;
	newstring.m_str = new char[size];
	strcpy(newstring.m_str, other.m_str);
	for (int i = 0; i < num-1; i++) {
		strcat(newstring.m_str, other.getStr());
	}
	return newstring;
	
}
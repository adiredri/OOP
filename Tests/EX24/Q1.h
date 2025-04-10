#ifndef SRC_Q1_H_
#define SRC_Q1_H_
using namespace std;

template <class T>
class Vector
{
	int _size;
	T* _arr;
	int _curr;

public:
	Vector(int n): _size(n), _curr(0) {
		_arr = new T[n];
	}
	~Vector() {
		delete[] _arr;
	}

	void add(const T& item);
	bool isEqual(const Vector& other);
	T& itemInPos(int post);
};

template <class T>
void Vector<T>::add(const T& item)
{
	if (_curr < _size)
		_arr[_curr++] = item;
}

template <class T>
bool Vector<T>::isEqual(const Vector<T>& other)
{
	if (_size != other._size || _curr != other._curr)
		return false;
	for (int i = 0; i < _curr; ++i)
	{
		if (_arr[i] != other._arr[i])
			return false;
	}
	return true;
}

template <class T>
T& Vector<T>::itemInPos(int pos)
{
	return this->_arr[pos];
}

#endif /* SRC_Q1_H_ */
#pragma once
#include <iostream>
#include <cstring>
template <class T>
class Pair
{
private:
	char* key;
	T value;
public:
	Pair();
	Pair(const T value);
	Pair(const Pair& other);
	Pair<T>& operator=(const Pair<T>& rhs);
	~Pair();

	void setkey(const char* key);
	void setvalue(const T value);

	const char* getkey()const;
	const T getvalue()const;

	void print();
};

template<class T>
Pair<T>::Pair() :key(nullptr), value(0)
{
}
template<class T>
Pair<T>::Pair(const T value)
{
	this->key = nullptr;
	setvalue(value);
}
template<class T>
Pair<T>::Pair(const Pair & other)
{
	this->key = nullptr;
	setkey(other.getkey());
	setvalue(other.getvalue());
}
template<class T>
Pair<T> & Pair<T>::operator=(const Pair<T> & rhs)
{
	this->key = nullptr;
	setkey(rhs.getkey());
	setvalue(rhs.getvalue());
	return *this;
}
template<class T>
Pair<T>::~Pair()
{
	delete[] key;
}
template<class T>
void Pair<T>::setkey(const char * key)
{
	if (key == nullptr)
	{
		this->key = nullptr;
	}
	else
	{
		int size = strlen(key) + 1;
		delete[] this->key;
		this->key = new char[size];
		strcpy(this->key, key);
	}
}
template<class T>
inline void Pair<T>::setvalue(const T value)
{
	this->value = value;
}

template<class T>
inline const char * Pair<T>::getkey() const
{
	return this->key;
}

template<class T>
const T Pair<T>::getvalue() const
{
	return this->value;
}

template<class T>
void Pair<T>::print()
{
	std::cout << "Key: ";
	if (this->key == nullptr)
	{
		std::cout << "There is no key!" << " Value: " << getvalue() << "\n";
	}
	else
	{
		std::cout << getkey() << " Value: " << getvalue() << "\n";
	}
}

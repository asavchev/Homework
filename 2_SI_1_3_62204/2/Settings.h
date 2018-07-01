#pragma once
#include "Pair.h"
template <class T>
class Settings
{
private:
	Pair<T> * pairs;
	int countp=0;
public:
	Settings();
	Settings(const Settings& other);
	Settings<T>& operator=(const Settings<T>& rhs);
	~Settings();

	void set(const char* key,const T value);
	bool get(const char* key,const T& value);
	const bool ifkey();
	int count();
	void print();
	int iskey(const char* key);
};


template<class T>
inline Settings<T>::Settings():pairs(nullptr),countp(0)
{
}

template<class T>
inline Settings<T>::Settings(const Settings & other)
{
	delete[] pairs;
	if (other.pairs == 0)
	{
		pairs = nullptr;
		countp = 0;
	}
	else
	{
		pairs = new Pair[other.countp];
		for (int i = 0; i < other.countp; i++)
		{
			pairs[i] = other.pairs[i];
		}
		countp = other.countp;
	}
}

template<class T>
inline Settings<T> & Settings<T>::operator=(const Settings<T> & rhs)
{
	delete[] pairs;
	if (rhs.pairs == 0)
	{
		pairs = nullptr;
		countp = 0;
	}
	else
	{
		pairs = new Pair[rhs.countp];
		for (int i = 0; i < rhs.countp; i++)
		{
			pairs[i] = rhs.pairs[i];
		}
		countp = rhs.countp;
	}
	return *this;
}

template<class T>
inline Settings<T>::~Settings()
{
	delete[] pairs;
}

template<class T>
inline void Settings<T>::set(const char * key,const T value)
{
	if (countp == 0)
	{
		countp++;
		pairs = new Pair<T>[countp];
		pairs[0].setvalue(value);
		pairs[0].setkey(key);
	}
	else if (iskey(key)>=0)
	{
		pairs[iskey(key)].setvalue(value);
	}
	else
	{
		Pair<T>* newp = new Pair<T>[countp];
		for (int i = 0; i < countp; i++)
		{
			newp[i] = pairs[i];
		}
		delete[] pairs;
		countp++;
		pairs = new Pair<T>[countp];
		countp--;
		for (int i = 0; i < countp; i++)
		{
			pairs[i] = newp[i];
		}
		delete[] newp;
		pairs[countp].setvalue(value);
		pairs[countp].setkey(key);
		countp++;
	}
}

template<class T>
inline bool Settings<T>::get(const char * key,const T & value)
{
	for (int i = 0; i < countp; i++)
	{
		if (strcmp(pairs[i].getkey(), key) == 0)
		{
			pairs[i].setvalue(value);
		    return true;
		}
	}
	return false;
}

template<class T>
inline const bool Settings<T>::ifkey()
{
	for (int i = 0; i < countp; i++)
	{
		if (pairs[i].getkey() != nullptr)
			return true;
	}
	return false;
}

template<class T>
inline int Settings<T>::count()
{
	return countp;
}

template<class T>
inline void Settings<T>::print()
{
	for (int i = 0; i < countp; i++)
	{
		pairs[i].print();
	}
}

template<class T>
inline int Settings<T>::iskey(const char * key)
{
	for (int i = 0; i < countp; i++)
	{
		if (strcmp(key, pairs[i].getkey()) == 0)
			return i;
	}
	return -1;
}

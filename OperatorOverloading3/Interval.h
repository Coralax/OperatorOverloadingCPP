/*Written by Coral Ifergan */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IPrintable.h"


template<class T>
class Interval :public IPrintable {
public:
	virtual void output() const;
	virtual void input();
	virtual ~Interval();
	Interval(T first, T second);
	Interval(const Interval& other);
	bool isEmpty()const;
	bool isBefore(const Interval<T>&)const;
	bool isAfter(const Interval<T>&)const;
	bool intersects(const Interval<T>&)const;
	bool contains(const T&)const;
	Interval<T> operator&&(const Interval<T>&) const;
	Interval<T> operator||(const Interval<T>&) const;
	Interval<T>& operator=(const Interval<T>&);

private:
	bool IsValid;
	char Problem[100];
	T a;
	T b;
};


template <class T>
Interval<T>::Interval(T first, T second) :a(first), b(second) {
	if (first > second)
	{
		IsValid = false;
		strcpy(Problem, "Invalid interval");
	}
	else
	{
		IsValid = true;
		Problem[0] = '\0';
	}
}

template<class T>
Interval<T>::~Interval()
{
}

template<class T>
Interval<T>::Interval(const Interval& other) {
	operator=(other);
}

template<class T>
bool Interval<T>::isEmpty() const {
	return (a == b);
}

template<class T>
bool Interval<T>::isBefore(const Interval<T>& other) const {
	return (b <= other.a);
}

template<class T>
bool Interval<T>::isAfter(const Interval<T>& other) const {
	return (a >= other.b);
}

template<class T>
bool Interval<T>::intersects(const Interval<T>& other) const {
	if (IsValid && other.IsValid && !(isAfter(other)) && !(isBefore(other)))
		return true;
	return false;
}

template<class T>
bool Interval<T>::contains(const T& num) const {
	return (a < num && b > num);
}


template<class T>
Interval<T> Interval<T>::operator&&(const Interval<T>& other) const {
	if (intersects(other)) {
		return Interval<T>(a > other.a ? a : other.a, b < other.b ? b : other.b);
	}
	else {
		Interval<T> k = other;
		k.IsValid = false;
		strcpy(k.Problem, "EMPTY");
		return k;
	}
}

template<class T>
Interval<T> Interval<T>::operator||(const Interval<T>& other) const {
	if (intersects(other))
		return Interval<T>(a < other.a ? a : other.a, b > other.b ? b : other.b);

	Interval<T> k = other;
	k.IsValid = false;
	strcpy(k.Problem, "Invalid interval");
	return k;
}

template<class T>
void Interval<T>::input() {
	cin >> a >> b;
	if (a > b)
	{
		IsValid = false;
		strcpy(Problem, "Invalid interval");
	}
}

template<class T>
void Interval<T>::output() const {
	if (IsValid)
		cout << "(" << a << ", " << b << ")";
	else
		cout << Problem;
}

template<class T>
Interval<T>& Interval<T>::operator=(const Interval<T>& other) {
	a = other.a;
	b = other.b;
	IsValid = other.IsValid;
	strcpy(Problem, other.Problem);
	return *this;
}





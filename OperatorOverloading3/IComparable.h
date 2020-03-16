/*Written by Coral Ifergan */
#pragma once
#define _CRT_SECURE_NO_WARNINGS

template<typename T>
class IComparable {
public:
	virtual bool operator< (const T& other) const = 0;
	virtual bool operator> (const T& other) const = 0;
	virtual bool operator== (const T& other) const = 0;
	virtual bool operator!= (const T& other) const = 0;
	virtual bool operator<= (const T& other) const = 0;
	virtual bool operator>= (const T& other) const = 0;
};


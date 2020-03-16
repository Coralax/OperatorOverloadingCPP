
/*Written by Coral Ifergan */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <iostream>
using namespace std;

class IPrintable {
public:
	virtual void output() const = 0;
	virtual void input() = 0;
};

ostream& operator<< (ostream & os, const IPrintable& p) {
	p.output();
	return os;
}
istream& operator>> (istream & in, IPrintable& p) {
	p.input();
	return in;
}


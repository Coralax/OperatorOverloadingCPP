/*Written by Coral Ifergan */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "IComparable.h"
#include "IPrintable.h"

using namespace std;
class Date :public IComparable<Date>, public IPrintable {
public:
	Date(int day, int month, int year);
	Date(const Date& other);
	~Date();
	virtual void input();
	virtual void output() const;
	void setMonth(const int& month);
	void setYear(const int& year);
	void setDay(const int& day);
	bool operator< (const Date& other) const override;
	bool operator> (const Date& other) const override;
	bool operator<= (const Date& other) const override;
	bool operator>= (const Date& other) const override;
	bool operator== (const Date& other) const override;
	bool operator!= (const Date& other) const override;
	Date& operator=(const Date& other);

private:
	int _day;
	int _month;
	int _year;
	bool IsValid;
	char Problem[100];
	bool is_valid();
	bool is_leap() const;
};

Date::~Date() {
}

void Date::setMonth(const int& month) {
	_month = month;
	is_valid();
	if (IsValid)
	{
		Problem[0] = '\0';
	}
}

void Date::setDay(const int& day) {
	_day = day;
	is_valid();
	if (IsValid)
		Problem[0] = '\0';
}

void Date::setYear(const int& year) {
	_year = year;
	is_valid();
	if (IsValid)
		Problem[0] = '\0';

}

Date::Date(int day, int month, int year) :_day(day), _month(month), _year(year) {
	is_valid();
	if (IsValid)
		Problem[0] = '\0';
}

Date::Date(const Date& other) {
	operator=(other);
}


Date &Date::operator=(const Date& other) {
	_day = other._day;
	_month = other._month;
	_year = other._year;
	IsValid = other.IsValid;
	strcpy(Problem, other.Problem);
	return *this;
}

bool Date::operator>(const Date& other) const {
	return (operator<(other) || operator==(other));
}

bool Date::operator<(const Date& other) const {
	if (_year < other._year)
		return true;
	if (_year > other._year)
		return false;
	if (_month < other._month)
		return true;
	if (_month > other._month)
		return false;
	if (_day < other._day)
		return true;
	if (_day >= other._day)
		return false;
	return false;
}

bool Date::operator>=(const Date& other) const {
	return (operator>(other) || operator==(other));
}

bool Date::operator<=(const Date& other) const {
	return (operator<(other) || operator==(other));
}

bool Date::operator!=(const Date& other) const {
	return (!(operator==(other)));
}

bool Date::operator==(const Date& other) const {
	return (_day == other._day && _month == other._month && _year == other._year);
}


void Date::input()
{
	char str[100];
	int i = 0, res_day = 0, res_month = 0, res_year = 0, sign = 1;
	cin.getline(str, 100);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '/')
	{
		res_day = (res_day * 10) + (str[i] - '0');
		i++;
	}
	_day = sign * res_day;
	sign = 1;
	i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '/')
	{
		res_month = (res_month * 10) + (str[i] - '0');
		i++;
	}
	_month = sign * res_month;
	sign = 1;
	i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res_year = (res_year * 10) + (str[i] - '0');
		i++;
	}
	_year = sign * res_year;
	IsValid = is_valid();
}


bool Date::is_leap() const {
	return (((_year % 4 == 0) &&
		(_year % 100 != 0)) ||
		(_year % 400 == 0));

}

void Date::output() const
{
	if (IsValid) {
		if (_day < 10)
			cout << 0 << _day << "/";
		else
			cout << _day << "/";

		if (_month < 10)
			cout << 0 << _month << "/";
		else
			cout << _month << "/";
		cout << _year;
	}
	else
		cout << Problem;
}



bool Date::is_valid() {
	IsValid = false;
	if (_month < 1 || _month > 12) {
		strcpy(Problem, "Illegal month");
		return false;
	}
	if (_day < 1 || _day > 31) {
		strcpy(Problem, "Illegal day for month");
		return false;
	}
	switch (_month) {
	case 2:
		if (_day > 29)
		{
			strcpy(Problem, "Illegal day for month");
			IsValid = false;
			return false;
		}
		else if (_day == 29)
		{
			if (is_leap())
				return (IsValid = true);
			else
			{
				strcpy(Problem, "Not a leap year");
				IsValid = false;
				return false;
			}
		}
		else {
			IsValid = true;
			return true;

		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (_day > 30)
		{
			strcpy(Problem, "Illegal day for month");
			IsValid = false;
			return false;
		}
		break;
	default:
		IsValid = true;
	}
	return true;
}







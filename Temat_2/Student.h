#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
	char* name;
	int year;
	int64_t number;
	double avmark;

public:
	Student();
	Student(const char* _name, int _year, int64_t _number, double _avmark);
	~Student();

	void showStudent();
	const char* getName();
	int getYear();
	int64_t getNumber();
	double getAvmark();

	void setName(const char* _name);
	void setYear(int _year);
	void setNumber(int64_t _number);
	void setAvmark(double _avmark);

	void toBinFile(FILE* fp);
	void frBinFile(FILE* fp);
};


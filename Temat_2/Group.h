#pragma once
#include"Student.h"

class Group
{
	char* Gname;
	int Gamount;
	Student** arr;

public:
	Group();
	Group(const char* name);
	~Group();

	void setGname(const char* name);
	const char* getGname();
	int getGamount();
	void showGroup();
	int findIdByName(const char* name);

	void addStudent(Student* obj);
	void delStudent(int id);
	void showStudent(int id);


	void setinfoStudent(int id);
	void getinfoStudent(int id);


	void toBinFile(FILE* fp);
	void frBinFile(FILE* fp);
};

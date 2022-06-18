#include "Group.h"

Group::Group()
{
	Gname = new char[50]{ "39PR31" };
	Gamount = 0;
	arr = nullptr;
}

Group::Group(const char* name)
{
	Gname = new char[strlen(name) + 1];
	strcpy_s(Gname, strlen(name) + 1, name);
}

Group::~Group()
{
	delete[] Gname;
	if (Gamount > 0)
	{
		for (int i = 0; i < Gamount; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		cout << "\n������ ������� �������!\n\n";
	}
}

void Group::setGname(const char* name)
{
	if (Gname!=NULL)
	{
		delete[] Gname;
	}
	Gname = new char[strlen(name) + 1];
	strcpy_s(Gname, strlen(name) + 1, name);
}

const char* Group::getGname()
{
	return Gname;
}

int Group::getGamount()
{
	return Gamount;
}

void Group::showGroup()
{
	cout << "\n============================================";
	cout << "\n\t���������� � ������:";
	cout << "\n�������� ������: " << Gname;
	cout << "\n���������� ���������: " << Gamount << endl << endl;
	for (int i = 0; i < Gamount; i++)
	{
		cout << "\t������� #" << i + 1 << endl;
		arr[i]->showStudent();
	}
	cout << "\n============================================\n\n";

}

void Group::addStudent(Student* obj)
{
	Student** tmp = new Student * [++Gamount];
	for (int i = 0; i < Gamount - 1; i++)
	{
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[]arr;
	tmp[Gamount - 1] = obj;
	arr = tmp;
}

int Group::findIdByName(const char* name)
{
	int id = -1;
	for (int i = 0; i < Gamount; i++)
	{
		if (strcmp(name,arr[i]->getName()) == 0)
		{
			id = i;
		}
	}
	return id;
}

void Group::delStudent(int id)
{
	Student** tmp = new Student * [--Gamount];
	for (int i = 0; i < Gamount; i++)
	{
		if (i < id)
		{
			tmp[i] = arr[i];
		}
		else if (i >= id)
		{
			tmp[i] = arr[i + 1];
		}
	}
	delete arr[id];//<<<  !!!!
	if (arr != NULL) delete[] arr;
	arr = tmp;
	cout << "\n�������, ������������ � ������ ��� ������� [" << id+1 << "] ����� �������!\n\n";
}

void Group::showStudent(int id)
{
	arr[id]->showStudent();
}

void Group::setinfoStudent(int id)
{
	int menu;
	char name[50] = "";
	int year;
	int64_t number;
	double avmark;

	do
	{
		cout << "\n1. �������� ��� ��������.";
		cout << "\n2. �������� ��� �������� ��������.";
		cout << "\n3. �������� ��������� ����� ��������.";
		cout << "\n4. �������� ������� ���� ��������.";
		cout << "\n0. ����� �� ����.\n�����: ";
		cin >> menu;
		switch (menu)
		{
		case 1: 
			cout << "\n����� ��� ��������: ";
			cin.ignore();
			cin.getline(name, 50);
			arr[id]->setName(name);
			cout << "\n��� ���������!\n\n";
			break;

		case 2: 
			cout << "\n��� �������� ��������: ";
			cin >> year;
			arr[id]->setYear(year);
			cout << "\n��� �������� �������!\n\n";
			break;

		case 3: 
			cout << "\n����� �������� ��������: ";
			cin >> number;
			arr[id]->setNumber(number);
			cout << "\n����� �������� �������!\n\n";
			break;

		case 4: 
			cout << "\n������� ���� ��������: ";
			cin >> avmark;
			arr[id]->setAvmark(avmark);
			cout << "\n������� ���� �������!\n\n";
			break;

		default: if (menu > 4 && menu != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu != 0);

}

void Group::getinfoStudent(int id)
{
	int menu;
	do
	{
		cout << "\n1. ��� �������� ��������.";
		cout << "\n2. ��������� ����� ��������.";
		cout << "\n3. �������� ������� ���� ��������.";
		cout << "\n0. ����� �� ����.\n�����: ";

		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\n��� �������� ��������: " << arr[id]->getYear() << endl << endl;
			break;

		case 2:
			cout << "\n��������� ��������: " << arr[id]->getNumber() << endl << endl;
			break;

		case 3:
			cout << "\n��������� ��������: " << arr[id]->getAvmark() << endl << endl;
			break;

		default: if (menu > 3 && menu != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu != 0);
}

void Group::toBinFile(FILE* fp)
{
	fopen_s(&fp, "Group.dat", "wb");

	if (fp == NULL)
	{
		cout << "\n������ �������� ���� ������ ������! ��������� �����\n\n";
	}
	else
	{
		int size = strlen(Gname) + 1;
		fwrite(&size, sizeof(int), 1, fp);
		fwrite(Gname, sizeof(char), size, fp);

		fwrite(&Gamount, sizeof(int), 1, fp);
		for (int i = 0; i < Gamount; i++)
		{
			arr[i]->toBinFile(fp);
		}
		fclose(fp);
		cout << "\n������ ������ ������� ��������� � ���� ������!\n\n";
	}
}

void Group::frBinFile(FILE* fp)
{
	fopen_s(&fp, "Group.dat", "rb");

	if (fp == NULL)
	{
		cout << "\n������ �������� ���� ������ ������! ��������� �����\n\n";
	}
	else
	{
		char tmp[50] = "";
		int size = 0;

		fread(&size, sizeof(int), 1, fp);
		fread(tmp, sizeof(char), size, fp);
		Gname = new char[size];
		strcpy_s(Gname, size, tmp);


		fread(&Gamount, sizeof(int), 1, fp);

		arr = new Student * [Gamount];
		for (int i = 0; i < Gamount; i++)
		{
			arr[i] = new Student();
			arr[i]->frBinFile(fp);
		}
		fclose(fp);
		cout << "\n������ ������ ������� ��������� �� ���� ������!\n\n";
	}
}

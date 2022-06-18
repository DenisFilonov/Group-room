#include "Student.h"

Student::Student()
{
	name = new char[50]{ "Ivanov" };
	year = 1900;
	number = 380951112233;
	avmark = 4.5;
}

Student::Student(const char* _name, int _year, int64_t _number, double _avmark)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	year = _year;
	number = _number;
	avmark = _avmark;
}

Student::~Student()
{
	delete[] name;
	cout << "\nСтудент успешно удалён!\n\n";
}

void Student::showStudent()
{
	cout << "\n============================================";
	cout << "\n\tИнформация о студенте:";
	cout << "\nИнициалы: " << name;
	cout << "\nГод рождения: " << year;
	cout << "\nМобильный номер: " << number;
	cout << "\nСредний балл: " << avmark;
	cout << "\n============================================\n\n";
}

const char* Student::getName()
{
	return name;
}

int Student::getYear()
{
	return year;
}

int64_t Student::getNumber()
{
	return int64_t(number);
}

double Student::getAvmark()
{
	return avmark;
}


void Student::setName(const char* _name)
{
	if (name != NULL) delete[] name;

	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
	cout << "\nИмя записано!\n\n";
}

void Student::setYear(int _year)
{
	if (_year > 1900)
	{
		year = _year;
		cout << "\nГод записан!\n\n";
	}
	else cout << "\nОшибка ввода данных!\n\n";
}

void Student::setNumber(int64_t _number)
{
	if (_number > 0)
	{
		number = _number;		
		cout << "\nНомер записан!\n\n";
	}
	else cout << "\nОшибка ввода данных!\n\n";
}

void Student::setAvmark(double _avmark)
{
	if (_avmark > 1 && _avmark < 12)
	{
		avmark = _avmark;
		cout << "\nСредняя оценка записана!\n\n";
	}
	else cout << "\nОшибка ввода данных!\n\n";
}

void Student::toBinFile(FILE* fp)
{
	int size = strlen(name) + 1;
	fwrite(&size, sizeof(int), 1, fp);
	fwrite(name, sizeof(char), size, fp);

	fwrite(&year, sizeof(int), 1, fp);
	fwrite(&number, sizeof(number), 1, fp);
	fwrite(&avmark, sizeof(double), 1, fp);
	cout << "\nИнформация о студенте успешно сохранена!\n\n";

}

void Student::frBinFile(FILE* fp)
{
	char tmp[50] = "";
	int size = 0;

	fread(&size, sizeof(int), 1, fp);
	fread(tmp, sizeof(char), size, fp);
	name = new char[size];
	strcpy_s(name, size, tmp);

	fread(&year, sizeof(int), 1, fp);
	fread(&number, sizeof(number), 1, fp);
	fread(&avmark, sizeof(double), 1, fp);
	cout << "\nИнформация о жильце успешно загружена!\n\n";
}

#include"Group.h"
#include<Windows.h>

int main()
{
	setlocale(NULL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Student* A = new Student();
	Student* B = new Student("Pupkin",1999,380966347282,3.5);
	A->showStudent();
	cout << endl;
	B->showStudent();
	cout << "\n------------------------------------------------------\n\n";
	A->setName("Abdiabdia");
	A->setYear(1999);
	A->setNumber(380953332211);
	A->setAvmark(8.9);
	A->showStudent();
	delete A;
	delete B;*/
	
	/*Group* A = new Group();
	A->showGroup();
	A->addStudent(new Student("Denis", 1995, 48727812235, 11.5));
	A->addStudent(new Student("Dima", 2000, 1231231231, 11.5));
	A->addStudent(new Student("Eva", 2000, 1231231231, 11.5));
	A->addStudent(new Student("Anton", 2000, 1231231231, 11.5));
	A->showGroup();
	delete A;*/
	int menu;
	char str[50] = "";
	int value;

	FILE* fp = nullptr;
	Group* G = new Group();
	G->frBinFile(fp);
	do
	{
		cout << "\n1. ���������� �������� ������.";
		cout << "\n2. ����������� �������� ������.";
		cout << "\n3. ����������� ���������� ��������� � ������.";
		cout << "\n4. �������� ������ ���������.";
		cout << "\n5. �������� ��� ���������� � ��������.";
		cout << "\n6. �������� ���������� � ��������.";
		cout << "\n7. ������������� ���������� � ��������.";
		cout << "\n8. �������� �������� � ������.";
		cout << "\n9. ������� �������� �� ������.";
		cout << "\n0. ����� � ���������.\n�����: ";
		cin >> menu;
		switch (menu)
		{
		case 1: 
			cout << "\n�������� ������: ";
			cin.ignore();
			cin.getline(str, 50);
			G->setGname(str);
			cout << "\n�������� ������ �����������!\n\n";
			break;

		case 2: 
			cout << "\n�������� ������: " << G->getGname() << endl << endl;
			break;

		case 3: 
			value = G->getGamount();
			cout << "\n���������� ��������� � ������: " << value << " �������.\n\n";
			break;

		case 4: 
			G->showGroup();
			break;

		case 5: 
			cout << "\n��� ��������: ";
			cin.ignore();
			cin.getline(str, 50);
			value = G->findIdByName(str);
			if (value == -1) cout << "\n������� �� ������! ��������� �������� ������.\n\n";
			else
			{
				G->showStudent(value);
			}
			break;

		case 6: 
			cout << "\n��� ��������: ";
			cin.ignore();
			cin.getline(str, 50);
			value = G->findIdByName(str);
			if (value == -1) cout << "\n������� �� ������! ��������� �������� ������.\n\n";
			else
			{
				G->getinfoStudent(value);
			}
			break;

		case 7: 
			cout << "\n��� ��������: ";
			cin.ignore();
			cin.getline(str, 50);
			value = G->findIdByName(str);
			if (value == -1) cout << "\n������� �� ������! ��������� �������� ������.\n\n";
			else
			{
				G->setinfoStudent(value);
			}
			break;

		case 8: //� ��������� ��� ������� :) �� �������� ��������� ����� ���������� ���� ������������� ������) �� ���, � ����, ������)
			G->addStudent(new Student());
			cout << "\n������� ��������! �������� ���������� � ��������.\n\n";	
			value = G->getGamount();
			G->setinfoStudent(value - 1);
			break;

		case 9: 
			cout << "\n��� ��������: ";
			cin.ignore();
			cin.getline(str, 50);
			value = G->findIdByName(str);
			if (value == -1) cout << "\n������� �� ������! ��������� �������� ������.\n\n";
			else
			{
				G->delStudent(value);
			}
			break;


		default: if (menu > 9 && menu != 0) cout << "\n������� ������ ����� ����.\n\n";	break;
		}
	} while (menu!=0);


	G->toBinFile(fp);
	if (G != NULL) delete G;
	return 0;
}
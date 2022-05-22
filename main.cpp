#include "Rectanglle.h"
#include "Circle.h"
#include "Right_Triangle.h"
#include "Trapezoid.h"
#include <fstream> 
#include <string>
#include <conio.h>
#include <typeinfo>
#include <Windows.h>

using namespace std;

void show(Square** object, int num_elem)									// ������� ������ �������� �� �����
{																																
	int mode = 0;															
	int celem = 0;														
	string type[4] = { "Trapezoid", "Right_Triangle", "Rectanglle", "Circle"};

	if (num_elem == 0)															
	{
		cout << "No added shapes!" << endl;
		return;
	}

	for (int i = 0; i < 4; i++, mode++)									
	{
		cout << "Square " << type[i] << ":" << endl;
		for (int j = 0; j < num_elem; j++)									
		{
			if (mode == 0)														
			{
				if (typeid(*object[j]) == typeid(Rectanglle))						
				{
					object[j]->print();										
					celem++;
				}
			}
			else if (mode == 1)													
			{
				if (typeid(*object[j]) == typeid(Circle))						
				{
					object[j]->print();								
					celem++;
				}
			}
			else if (mode == 2)													
			{
				if (typeid(*object[j]) == typeid(Right_Triangle))					
				{
					object[j]->print();
					celem++;
				}
			}
			else if (mode == 3)													
			{
				if (typeid(*object[j]) == typeid(Trapezoid))					
				{
					object[j]->print();
					celem++;
				}
			}
		}

		if (celem == 0)													
		{
			cout << "You do not have" << type[i] << endl;
		}
		celem = 0;
		cout << endl;
	}
}

void write_to_file(Square** object, int num_elem, string path, int mode)	// ������� ������ ��������� � ����
{
	ofstream fout;																
	fout.open(path);															

	if (!fout.is_open())														
	{
		cout << "Error when opening a file on the path" << path << endl;
		return;
	}

	for (int i = 0; i < num_elem; i++)										
	{
		if (mode == 0)															
		{ 

			if (typeid(*object[i]) == typeid(Rectanglle))							
				fout.write((char*)&(*object[i]), sizeof(Rectanglle));				
		}
		else if (mode == 1)														
		{
			if (typeid(*object[i]) == typeid(Circle))
				fout.write((char*)&(*object[i]), sizeof(Circle));
		}
		else if (mode == 2)
		{
			if (typeid(*object[i]) == typeid(Right_Triangle))
				fout.write((char*)&(*object[i]), sizeof(Right_Triangle));
		}
		else if (mode == 3)
		{
			if (typeid(*object[i]) == typeid(Trapezoid))
				fout.write((char*)&(*object[i]), sizeof(Trapezoid));
		}
	}
	
	fout.close();																
}

Square** read_from_file(Square** object, int& num_elem, string path, int mode)			// ������� ������ �� �����
{
	int i;																		
	size_t size = 0;																	
	ifstream fin;
	fin.open(path);																		
	Square** obj = new Square *[num_elem + 1];											// ������� ������ ���������� �� ������� ����� �� 1 ��������

	if (!fin.is_open())																	// ���� ���� �� ��������
	{
		cout << "Error when opening a file on the path" << path << endl;				// ������� ������, ������� ������ ���������� � ������
		delete[] obj;
		return object;
	}

	for (i = 0; i < num_elem; i++)														// ����� �������� ��� �������� �� ����� ��������
	{																					// � �����
		obj[i] = object[i];
	}

	if (mode == 0) { obj[i] = new Rectanglle; size = sizeof(Rectanglle); }					
	else if (mode == 1) { obj[i] = new Circle; size = sizeof(Circle); }				
	else if (mode == 2) { obj[i] = new Right_Triangle; size = sizeof(Right_Triangle); }
	else if (mode == 3) { obj[i] = new Trapezoid; size = sizeof(Trapezoid); }
																			
	while (fin.read((char*)&(*obj[i]), size))											// ��-������� ��������� (����� read, ���������� 
	{																					// true, ���� ������� �������, � false, ���� ���)
		if (object != nullptr)															// �������� �������� ������
		{
			delete[] object;
		}

		object = obj;																	// ����� ���������� �������� �������� 
		num_elem++;																		// ����������� ���. ��������� � ������� ����� �����
 		obj = new Square * [num_elem + 1];

		for (i = 0; i < num_elem; i++)													// �������� ��� ��������� �� ��������� � ����� �����
		{
			obj[i] = object[i];
		}
		
		if (mode == 0) { obj[i] = new Rectanglle; }											
		else if (mode == 1) { obj[i] = new Circle; }
		else if (mode == 2) { obj[i] = new Right_Triangle; }
		else if (mode == 3) { obj[i] = new Trapezoid; }

	}

	delete[] obj;																		

	fin.close();																		
	return object;																		
}

int main()
{
	int i;
	bool exit = 1;																
	char choice = 0;																	
	double r, h, a, b;
	string path[4] = { "Rectanglle.txt", "Circle.txt", "Right_Triangle.txt",  "Trapezoid.txt"};
																			
	Square** line, **temp;
	int num_elem;																	
		
	num_elem = 0;
	line = nullptr;
	r = a = b = h = 0;

	SetConsoleCP(1251);																	
	SetConsoleOutputCP(1251);

	while (exit)																		
	{
		cout << "Choosing an action:\n1) Add a rectangle\n2) Add a circle\n3) Add a right triangle\n4) Add a trapezoid\n5) Display all squares on the screen\n6) Read from file\n7) Write to file\n8) Output\n" << endl;
		choice = _getch();																

		switch (choice)
		{
		case '1':
			try
			{
				cout << "Add a rectangle" << endl;

				cout << "Enter a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				cout << "Enter b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				num_elem++;																// ����������� ���. ��������� 
				if (num_elem == 1)														// ���� ��� ������ ������� � ����� �������, ��
				{
					line = new Square * [num_elem];										// ������ ������ ��� ������ ������� ����
					line[0] = new Rectanglle(a, b);										// �������� ���� ��������
				}

				else																	// � ���� ������
				{
					temp = new Square * [num_elem];										// ������� ����� ������ ����������

					for (i = 0; i < num_elem - 1; i++)									// �������� ��������� �� �������
					{
						temp[i] = line[i];
					}

					temp[i] = new Rectanglle(a, b);										// ��������� ����� �������
					delete[] line;														// ������� ������ ������
					line = temp;														// ��������� �� ������ ������ ������ ��������� �� �����
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// ������� ���������� 
				cin.clear();															// ���. ����� �����
				cin.ignore(32767, '\n');												// �������� ��� �����
			}

			system("pause");
			system("cls");
			break;

		case '2':
			try
			{
				cout << "Add a circle" << endl;

				cout << "Enter r: ";
				cin >> r;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				num_elem++;																// ����������� ���. ��������� 
				if (num_elem == 1)														// ���� ��� ������ ������� � ����� �������, ��
				{
					line = new Square * [num_elem];										// ������ ������ ��� ������ ������� ����
					line[0] = new Circle(r);											// �������� ���� ��������
				}

				else																	// � ���� ������
				{
					temp = new Square * [num_elem];										// ������� ����� ������ ����������

					for (i = 0; i < num_elem - 1; i++)									// �������� ��������� �� �������
					{
						temp[i] = line[i];
					}

					temp[i] = new Circle(r);											// ��������� ����� �������
					delete[] line;														// ������� ������ ������
					line = temp;														// ��������� �� ������ ������ ������ ��������� �� �����
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// ������� ���������� 
				cin.clear();															// ���. ����� �����
				cin.ignore(32767, '\n');												// �������� ��� �����
			}

			system("pause");
			system("cls");
			break;

		case '3':
			try
			{
				cout << "Add a right triangle" << endl;

				cout << "Enter a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				cout << "Enter b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				num_elem++;																// ����������� ���. ��������� 
				if (num_elem == 1)														// ���� ��� ������ ������� � ����� �������, ��
				{
					line = new Square * [num_elem];										// ������ ������ ��� ������ ������� ����
					line[0] = new Right_Triangle(a, b);									// �������� ���� ��������
				}

				else																	// � ���� ������
				{
					temp = new Square * [num_elem];										// ������� ����� ������ ����������

					for (i = 0; i < num_elem - 1; i++)									// �������� ��������� �� �������
					{
						temp[i] = line[i];
					}

					temp[i] = new Right_Triangle(a, b);									// ��������� ����� �������
					delete[] line;														// ������� ������ ������
					line = temp;														// ��������� �� ������ ������ ������ ��������� �� �����
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// ������� ���������� 
				cin.clear();															// ���. ����� �����
				cin.ignore(32767, '\n');												// �������� ��� �����
			}

			system("pause");
			system("cls");
			break;

		case '4':
			try
			{
				cout << "Add a trapezoid" << endl;

				cout << "Enter a: ";
				cin >> a;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				cout << "Enter b: ";
				cin >> b;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				cout << "Enter h: ";
				cin >> h;
				cin.ignore(32767, '\n');
				if (cin.fail())
				{
					throw "The entered character is not a number!";
				}

				num_elem++;																// ����������� ���. ��������� 
				if (num_elem == 1)														// ���� ��� ������ ������� � ����� �������, ��
				{
					line = new Square * [num_elem];										// ������ ������ ��� ������ ������� ����
					line[0] = new Trapezoid(a, b, h);									// �������� ���� ��������
				}

				else																	// � ���� ������
				{
					temp = new Square * [num_elem];										// ������� ����� ������ ����������

					for (i = 0; i < num_elem - 1; i++)									// �������� ��������� �� �������
					{
						temp[i] = line[i];
					}

					temp[i] = new Trapezoid(a, b, h);									// ��������� ����� �������
					delete[] line;														// ������� ������ ������
					line = temp;														// ��������� �� ������ ������ ������ ��������� �� �����
					temp = nullptr;
				}
			}
			catch (const char* exc)
			{
				cout << exc << endl;													// ������� ���������� 
				cin.clear();															// ���. ����� �����
				cin.ignore(32767, '\n');												// �������� ��� �����
			}

			system("pause");
			system("cls");
			break;

		case '5':
			cout << "Display all squares on the screen" << endl;

			cout << "\nSquares:" << endl;
			show(line, num_elem);												// �������� �-�� show(), ��������� �� ���������
			cout << endl;														// �� ������ ���������� �� ������� �����

			system("pause");
			system("cls");
			break;

		case '6':
			cout << "Read from file" << endl;
			line = read_from_file(line, num_elem, path[0], 0);					// �������� �-�� show(), ��������� �� ���������
			line = read_from_file(line, num_elem, path[1], 1);					// �� ������ ���������� �� ������� �����, � ����������� 
			line = read_from_file(line, num_elem, path[2], 2);					// ����� ��������� ������������ ��������
			line = read_from_file(line, num_elem, path[3], 3);					// ����� ��������� ������������ ��������
																				// (������ ������ �� �����, �� � �-�� �� �������� ���������� ���������)
			system("pause");
			system("cls");
			break;

		case '7':
			cout << "Write to file" << endl;
			write_to_file(line, num_elem, path[0], 0);							// �������� �-�� show(), ��������� �� ���������
			write_to_file(line, num_elem, path[1], 1);							// �� ������ ���������� �� ������� �����
			write_to_file(line, num_elem, path[2], 2);
			write_to_file(line, num_elem, path[3], 3);

			system("pause");
			system("cls");
			break;

		case '8':
			cout << "Output" << endl;
			for (i = 0; i < num_elem; i++)										// �������� ��� ������, ������� �� �������� ��� �������
			{
				delete line[i];
			}	
			delete[] line;														// � ��� ������ ����������

			exit = 0;
			system("pause");
			break;

		default:
			cout << "Error when choosing a category! Try again." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
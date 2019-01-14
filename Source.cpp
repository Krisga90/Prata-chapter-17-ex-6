//#include <iostream>
#include <fstream>
//#include <string>
#include "emp.h"
#include <vector>

enum class_kind { Employee, Manager, Fink, HighFink };

bool read_employee(std::vector <abstr_emp *> & emp, std::istream & read);
void read_employee(std::vector <abstr_emp *> & emp, class_kind type);
void write_employee(const std::vector <abstr_emp *> & emp, int number_of_employee, std::ostream & write, int begin=0);
void write_employee(const std::vector <abstr_emp *> & emp, int number_of_employee);


int main(void)
{
	//proba odczytu z pliku(zakladamy ¿e plik istnieje)
	std::ifstream read_file;
	std::ofstream write_file;
	std::string file_name;
	std::vector <abstr_emp *> emp_list;
	std::cout << "Podaj nazwe pliku: ";
	std::cin >> file_name;
	while (std::cin.get() != '\n')
		continue;


	//odczyt pliku jesli istnieje
	read_file.open(file_name.c_str());
	if (read_file.is_open())
	{
		while (read_employee(emp_list, read_file));
		write_employee(emp_list, emp_list.size());
		read_file.close();
	}
	//plik odczytany.
	
	int emp_list_size_begin = emp_list.size();
	//menu g³ówne
	
	char ch='n';

	while (ch != 'k')
	{
		std::cout << "Co chcesz zrobic? wpisz odpowiednia litekre:\na - dodac nowego pracownika\nw - wyswietlic liste pracownikow"
			"\nk - zakonczyc program\: ";

		std::cin.get(ch);
		while (std::cin.get() != '\n')
			continue;
		switch (ch)
		{
		case 'a':
		case 'A':
			std::cout << "Na jakim stanowisku pracuje: \ne- employee \t\tm = manager"
				"\nf - fink \t\th - highFink\n: ";
			
			std::cin.get(ch);
			while (std::cin.get() != '\n')
				continue;

			switch (ch)
			{
			case 'e':
				read_employee(emp_list, class_kind::Employee);
				break;
			case 'm':
				read_employee(emp_list, class_kind::Manager);
				break;
			case 'f':
				read_employee(emp_list, class_kind::Fink);
				break;
			case 'h':
				read_employee(emp_list, class_kind::HighFink);
				break;
			}
			break;
		case 'w':
		case 'W':
			write_employee(emp_list, emp_list.size());
			break;
		}
		

	}
	


	//zapis do pliku mo¿na wykonac na dwa sposoby: 
	//#1. uzywamy wartosci wpisanych do wektora i dopisujemy do niego dalsze elementy, po czym zerujemy plik i wpisujemy wszystko od nowa.
	//#2 otwieramy plik i dopisujemy wartosci na koniec foldera

	//#1.
	if(0)
	{
		write_file.open(file_name);
		if (write_file.good())
		{
			write_employee(emp_list, emp_list.size(), write_file);
		}
		write_file.close();
	}

	//#2.
	if (1)
	{
		write_file.open(file_name, std::ios_base::out|std::ios_base::app);
		if (write_file.good())
		{
			write_employee(emp_list, emp_list.size(), write_file);
		}
		write_file.close();
	}

	return 0;
}




void write_employee(const std::vector <abstr_emp *> & emp, int number_of_employee, std::ostream & write, int begin)
{
	for (int i = begin; i < number_of_employee; i++)
	{
		if (typeid(*emp[i]) == typeid(employee))
		{
			write << Employee << std::endl;
		}
		else if (typeid(*emp[i]) == typeid(fink))
		{
			write << Fink << std::endl;
		}
		else if (typeid(*emp[i]) == typeid(manager))
		{
			write << Manager << std::endl;
		}
		else if (typeid(*emp[i]) == typeid(highfink))
		{
			write << HighFink << std::endl;
		}
		emp[i]->ShowAll(write);

	}
}

void write_employee(const std::vector <abstr_emp *> & emp, int number_of_employee)
{
	for (int i = 0; i < number_of_employee; i++)
	{
		emp[i]->ShowAll();
	}
}

bool read_employee(std::vector <abstr_emp *> & emp, std::istream & read)
{
	int type;
	read >> type;
	if (read.peek() == '\n')
		read.get();
	if (type == 0)
	{
		employee *temp = new employee;
		temp->SetAll(read);
		emp.push_back(temp);
	}
	else if (type == 1)
	{
		manager *temp = new manager;
		temp->SetAll(read);
		emp.push_back(temp);
	}
	else if (type == 2)
	{
		fink *temp = new fink;
		temp->SetAll(read);
		emp.push_back(temp);
	}
	else if (type == 3)
	{
		highfink *temp = new highfink;
		temp->SetAll(read);
		emp.push_back(temp);
	}
	read.peek();
	if (read.eof())
	{
		read.clear();
		return false;
	}
	return true;
}

void read_employee(std::vector <abstr_emp *> & emp, class_kind type)
{
	if (type == 0)
	{
		employee *temp= new employee;
		temp->SetAll();
		emp.push_back(temp);
	}
	else if (type == 1)
	{
		manager *temp= new manager;
		temp->SetAll();
		emp.push_back(temp);
	}
	else if (type == 2)
	{
		fink *temp = new fink;
		temp->SetAll();
		emp.push_back(temp);
	}
	else if (type == 3)
	{
		highfink *temp= new highfink ;
		temp->SetAll();
		emp.push_back(temp);
	}

}


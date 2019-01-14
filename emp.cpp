#include "emp.h"
#include <iostream>


abstr_emp::abstr_emp() :fname(""), lname(""), job("")
{
}

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string & j):fname(fn), lname(ln), job(j)
{
}


void abstr_emp::ShowAll() const		//opisuje i wyœwietla wszystkie dane
{
	std::cout << "Imie: " << fname << "\nNazwisko: " << lname << "\nStanowisko: " << job<<"\n";
}
 void abstr_emp::SetAll()			//prosi u¿ytkownika o podanie wartoœci
{
	 std::cout << "Podaj imie pracownika: ";
	 getline(std::cin, fname);
	 std::cout << "Podaj nazwisko pracownika: ";
	 getline(std::cin, lname);
	 std::cout << "Podaj stanowisko pracownika: ";
	 getline(std::cin, job);
}


 void abstr_emp::ShowAll(std::ostream & write) const		//opisuje i wyœwietla wszystkie dane
 {
	 write << fname << "\n"<< lname << "\n" << job << "\n";
 }

 void abstr_emp::SetAll(std::istream  & read)			//prosi u¿ytkownika o podanie wartoœci
 {
	 getline(read, fname);
	 getline(read, lname);
	 getline(read, job);
 }




 abstr_emp::~abstr_emp()
 {
 }


std::ostream & operator<<(std::ostream & os, const abstr_emp & e)	//tylko wyswietla imie i nazwisko
{
	os << e.fname << " " << e.lname;
	return os;
}




employee::employee():abstr_emp()
{

}

employee::employee(const std::string &fn, const std::string &ln, const std::string & j)
	:abstr_emp(fn,ln,j)
{

}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << '\n';
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::ShowAll(std::ostream & write) const
{
	abstr_emp::ShowAll(write);
}

void employee::SetAll(std::istream & read)
{
	abstr_emp::SetAll(read);
}



manager::manager() :abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string &fn, const std::string &ln, const std::string & j, int ico )
	:abstr_emp(fn, ln, j), inchargeof(ico)
{

}
	
manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico)
{

}
	
manager::manager(const manager & m)
	: abstr_emp(m), inchargeof(m.inchargeof)
{
	
}
	
void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "kieruje " << inchargeof << " pracownikami\n";
	std::cout << '\n';
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	Set_ICO();
}

void manager::ShowAll(std::ostream & write) const
{
	abstr_emp::ShowAll(write);
	write <<  inchargeof <<"\n";
}

void manager::SetAll(std::istream & read)
{
	abstr_emp::SetAll(read);
	Set_ICO(read);
}

void manager::Set_ICO()
{
	std::cout << "Podaj liczbe pracownikow za ktora jest odpowiedzialny: ";
	while (!(std::cin >> inchargeof))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Blad znaku \nPodaj liczbe pracownikow za ktora jest odpowiedzialny: ";
	}

	if(1)
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
}

void manager::Set_ICO(std::istream & read)
{
	if (read.peek() == '\n')
		read.get();

	if (!(read >> inchargeof))
	{
		read.clear();
		while (std::cin.get() != '\n')
			continue;
		inchargeof = 0;
	}

}


fink::fink()
	:abstr_emp(), reportsto("")
{

}
	
fink::fink(const std::string &fn, const std::string &ln, const std::string & j, const std::string &rpo)
	: abstr_emp(fn,ln,j),reportsto(rpo)
{

}

fink::fink(const abstr_emp & e, const std::string &rpo)
	:abstr_emp(e), reportsto(rpo)
{

}
	
fink::fink(const fink & f)
	:abstr_emp(f), reportsto(f.reportsto)
{
	
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "sklada donosy do: " << reportsto<<'\n';
	std::cout << '\n';
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	Set_RPO();
}

void fink::ShowAll(std::ostream & write) const
{
	abstr_emp::ShowAll(write);
	write << reportsto << '\n';
}

void fink::SetAll(std::istream & read)
{
	abstr_emp::SetAll(read);
	Set_RPO(read);
}

void fink::Set_RPO()
{
	std::cout << "Do kogo sklada donosy?: ";
	getline(std::cin, reportsto);
}

void fink::Set_RPO(std::istream & read)
{
	getline(read, reportsto);
}


highfink::highfink()
:abstr_emp(), fink(),manager()
{

}
	
highfink::highfink(const std::string &fn, const std::string &ln, const std::string & j, const std::string &rpo, int ico)
	: abstr_emp(fn, ln, j), fink(fn,ln,j,rpo), manager(fn, ln, j, ico)
{

}
	
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	:abstr_emp(e), fink(e, rpo), manager(e, ico)
{

}
	
highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), fink(f), manager(f, ico)
{

}
	
highfink::highfink(const manager & m, const std::string & rpo)
	: abstr_emp(m), fink(m,rpo), manager(m)
{

}
	
highfink::highfink(const highfink & h)
	: abstr_emp(h), fink(h), manager(h)
{

}
	
void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "sklada donosy do: " << ReportsTo()<<'\n';
	std::cout << "kieruje " << InCHargeOf() << " pracownikami\n";
	std::cout << '\n';

}
	
void highfink::SetAll()
{
	abstr_emp::SetAll();
	Set_RPO();
	Set_ICO();
}


void highfink::ShowAll(std::ostream & write) const
{
	abstr_emp::ShowAll(write);
	write << ReportsTo() << '\n';
	write  << InCHargeOf() << "\n";
}

void highfink::SetAll(std::istream &read)
{
	abstr_emp::SetAll(read);
	Set_RPO(read);
	Set_ICO(read);
}

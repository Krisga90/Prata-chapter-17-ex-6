#ifndef EMP_H_
#define EMP_H_


#include <iostream>
#include <string>




class abstr_emp
{
private:
	std::string fname;		//imiê obiektu abste_emp
	std::string lname;		//nazwisko obiektu abstr_emp
	std::string job;		//zawód obiektu abstd_emp
public:
	abstr_emp();
	abstr_emp(const std::string &fn, const std::string &ln, const std::string & j);
	virtual void ShowAll() const;		//opisuje i wyœwietla wszystkie dane
	virtual void ShowAll(std::ostream & write) const;
	virtual void SetAll();									//prosi u¿ytkownika o podanie wartoœci
	virtual void SetAll(std::istream & read);				//pobiera wartosci z pliku
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);	//tylko wyswietla imie i nazwisko
	virtual ~abstr_emp() = 0;//wirtualna klasa bazowa
};


class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string &fn, const std::string &ln, const std::string & j);
	virtual void ShowAll() const;
	virtual void ShowAll(std::ostream & write) const;
	virtual void SetAll();
	virtual void SetAll(std::istream & read);
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;			//liczba obiektów abstr_emp którymi zarz¹dza
protected:
	int InCHargeOf()const { return inchargeof; }		//wyjœcie;
	int & InChargeOf() { return inchargeof; }			//wejœcie
	void Set_ICO();
	void Set_ICO(std::istream & read);
public:
	manager();
	manager(const std::string &fn, const std::string &ln, const std::string & j, int ico = 0);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void ShowAll(std::ostream & write) const;
	virtual void SetAll();
	virtual void SetAll(std::istream & read);

};


class fink : virtual public abstr_emp
{
private:
	std::string reportsto;		//do kogo fink (donosiciel) przesy³a raporty
protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string & ReportsTo() { return reportsto; }
	void Set_RPO();
	void Set_RPO(std::istream & read);
public:
	fink();
	fink(const std::string &fn, const std::string &ln, const std::string & j, const std::string &rpo);
	fink(const abstr_emp & e, const std::string &rpo);
	fink(const fink & f);
	virtual void ShowAll() const;
	virtual void ShowAll(std::ostream & write) const;
	virtual void SetAll();
	virtual void SetAll(std::istream & read);
};

class highfink : public manager, public fink //g³ówny donosiciel
{
public:
	highfink();
	highfink(const std::string &fn, const std::string &ln, const std::string & j, const std::string &rpo, int ico);
	highfink(const abstr_emp & e, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void ShowAll(std::ostream & write) const;
	virtual void SetAll();
	virtual void SetAll(std::istream & read);
};

#endif
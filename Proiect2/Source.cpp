/*
Date de intrare:Colectiile claselor Client*,Credit,Rate si fisierul credit.txt din care se pot prelua informatii despre credit.
Operatii posibile:
-vizualizarea elementelor colectiilor prin meniu
-adaugarea,stergerea elementelor din colectii

Programul poate afisa datele despre clienti:persoane fizice sau firme, creditul acestora si ratele pe care acestea le au*/




#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#define MAX_DIM 1000
using namespace std;


class Client{
private:
	double cui;
	char* nume;
public:
	
	Client(double c=0, char* n="nimic"){
		cui = c;
		nume = new char[strlen(n) + 1];
		strcpy(nume, n);
	}
	Client(const Client &c){
		cui = c.cui;
		nume = new char[strlen(c.nume) + 1];
		strcpy(nume, c.nume);
	}

	 Client& operator=(Client& c){
		if (nume)
			delete nume;
		cui = c.cui;
		nume = new char[strlen(c.nume) + 1];
		strcpy(nume, c.nume);
		return *this;
	}
	~Client(){
		if (nume)
			delete nume;
	}

	double getCui() const {
		return cui;
	}

	void setCui(double cui) {
		this->cui = cui;
	}


	char* getNume() const {
		return nume;
	}

	void setNume(char* nume) {
		if (this->nume=="nimic")
			delete nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	friend ostream& operator<<(ostream&, Client);
};
ostream& operator<<(ostream& out, Client c){
	out << "CUI:" << c.cui << endl
		<< "Nume:" << c.nume << endl;
	return out;
}
class PersFizica:public Client{
private:
	double cnp;
	char* adresa;
	char* prenume;
public:

	PersFizica(double cui=0, char* nume="nimic", double cnp=0, char* adresa="nimic", char* prenume="nimic") :Client(cui, nume){
		this->cnp = cnp;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
	}
	PersFizica(const PersFizica &p){
		this->cnp = p.cnp;
		this->adresa = new char[strlen(p.adresa) + 1];
		strcpy(this->adresa, p.adresa);
		this->prenume = new char[strlen(p.prenume) + 1];
		strcpy(this->prenume, p.prenume);
	}
	PersFizica& operator=(PersFizica &p){
		if (adresa)
			delete adresa;
		if (prenume)
			delete prenume;
		this->cnp = p.cnp;
		this->adresa = new char[strlen(p.adresa) + 1];
		strcpy(this->adresa, p.adresa);
		this->prenume = new char[strlen(p.prenume) + 1];
		strcpy(this->prenume, p.prenume);
		return *this;
	}

	int operator==(PersFizica& p){
		int count=0;
		if (this->getCui() == p.getCui())count++;
		if (this->getNume() == p.getNume())count++;
		if (this->cnp == p.cnp)count++;
		if (this->adresa == p.adresa)count++;
		if (this->prenume == p.prenume)count++;

		if (count == 5)
			return 1;
		else
			return 0;
	}
	~PersFizica(){
		if (adresa)
			delete adresa;
		if (prenume)
			delete prenume;
		}
	
	friend ostream& operator<<(ostream&, PersFizica);

	friend istream& operator>>(istream&, PersFizica&);

	friend ifstream& operator>>(ifstream&, PersFizica&);
};
ostream& operator<<(ostream& out, PersFizica p){
	out << "CUI:" << p.getCui() << endl
		<< "Nume:" << p.getNume() << endl
		<< "Prenume:" << p.prenume << endl
		<< "CNP:" << p.cnp << endl
		<< "Adresa:" << p.adresa << endl;
	return out;
}

istream& operator>>(istream& in, PersFizica& p){
	char text[256];
	double temp;
	cout << "Introduceti CUI:" << endl;
	in >> temp;
	p.setCui(temp);
	cout << "Introduceti Nume:" << endl;
	in >> text;
	p.setNume(text);
	cout << "Introduceti Prenume:" << endl;
	in >> text;
	p.prenume = new char[strlen(text) + 1];
	strcpy(p.prenume, text);
	cout << "Introduceti CNP:" << endl;
	in >> temp;
	p.cnp = temp;
	cout << "Introduceti adresa:" << endl;
	in >> text;
	p.adresa = new char[strlen(text) + 1];
	strcpy(p.adresa, text);
	return in;
}


class Firma :public Client{
private:
	char* adresa;
	double capital;
public:

	Firma(double cui=0, char* nume="nimic", char* adresa="nimic", double capital=0) :Client(cui, nume){
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->capital = capital;
	}

	Firma(Firma &f){
		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->capital = f.capital;
	}

	Firma& operator=(Firma& f){
		if (adresa)
			delete adresa;
		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->capital = f.capital;
		return *this;
	}

	~Firma(){
		if (adresa)
			delete adresa;
	}
	int operator==(Firma& p){
		int count = 0;
		if (this->getCui() == p.getCui())count++;
		if (this->getNume() == p.getNume())count++;
		if (this->adresa == p.adresa)count++;
		if (this->capital == p.capital)count++;

		if (count == 4)
			return 1;
		else
			return 0;
	}
	friend ostream& operator<<(ostream&, Firma);
	friend istream& operator>>(istream&, Firma&);
};

ostream& operator<<(ostream& out, Firma f)
		{
			out << "CUI:" << f.getCui() << endl
				<< "Nume:" << f.getNume() << endl
				<< "Adresa:" << f.adresa << endl
				<< "Capital" << f.capital << endl;
			return out;
		}

istream& operator>>(istream& in, Firma& f){
	char text[256];
	double temp;
	cout << "Introduceti CUI:" << endl;
	in >> temp;
	f.setCui(temp);
	cout << "Introduceti Nume:" << endl;
	in >> text;
	f.setNume(text);
	cout << "Introduceti adresa:" << endl;
	in >> text;
	f.adresa = new char[strlen(text) + 1];
	strcpy(f.adresa, text);
	cout << "Introduceti Capital:" << endl;
	in >> temp;
	f.capital = temp;
	return in;
}


class Credit{
private:
	double cui;
	double valoare;
	double dobanda;
	double durata;
public:

	Credit(double cui=0,double valoare=0, double dobanda=0, double durata=0){
		this->cui = cui;
		this->valoare = valoare;
		this->dobanda = dobanda;
		this->durata = durata;
	}

	Credit(Credit &c){
		this->cui = c.cui;
		this->valoare = c.valoare;
		this->dobanda = c.dobanda;
		this->durata = c.durata;
	}

	Credit& operator=(Credit &c){
		this->cui = c.cui;
		this->valoare = c.valoare;
		this->dobanda = c.dobanda;
		this->durata = c.durata;
		return *this;
	}

	~Credit(){};
	int operator==(Credit& p){
		int count = 0;
		if (this->cui == p.cui)count++;
		if (this->valoare == p.valoare)count++;
		if (this->dobanda == p.dobanda)count++;
		if (this->durata == p.durata)count++;

		if (count == 4)
			return 1;
		else
			return 0;
	}
	friend ostream& operator<<(ostream&, Credit);
	friend istream& operator>>(istream&, Credit&);
	friend ifstream& operator>>(ifstream&, Credit&);
};

ostream& operator<<(ostream& out, Credit c){
	out << "CUI:" << c.cui << endl
		<< "Valoare credit:" << c.valoare << endl
		<< "Dobanda:" << c.dobanda << endl
		<< "Durata:" << c.durata << " ani" << endl;
	return out;
}

istream& operator>>(istream& in, Credit& c){
	double temp;
	cout << "Introduceti CUI:" << endl;
	in >> temp;
	c.cui = temp;
	cout << "Introduceti Valoare credit:" << endl;
	in >> temp;
	c.valoare = temp;
	cout << "Dobanda:" << endl;
	in >> temp;
	c.dobanda = temp;
	cout << "Durata:" << endl;
	in >> temp;
	c.durata = temp;
	return in;
}

ifstream& operator>>(ifstream& in, Credit& c){
	in >> c.cui >> c.valoare >> c.dobanda >> c.durata;
	return in;
}

class Rate{
private:
	double cui;
	double numar_rate;
	double valoare_rata;
public:

	Rate(double cui=0,int numar_rate=0, double valoare_rata=0){
		this->cui = cui;
		this->numar_rate = numar_rate;
		this->valoare_rata = valoare_rata;
	}

	Rate(Rate &r){
		this->cui = r.cui;
		this->numar_rate = r.numar_rate;
		this->valoare_rata = r.valoare_rata;
	}

	Rate& operator=(Rate &r){
		this->cui = r.cui;
		this->numar_rate = r.numar_rate;
		this->valoare_rata = r.valoare_rata;
		return *this;
	}

	~Rate(){};
	int operator==(Rate& p){
		int count = 0;
		if (this->cui == p.cui)count++;
		if (this->numar_rate == p.numar_rate)count++;
		if (this->valoare_rata == p.valoare_rata)count++;

		if (count == 3)
			return 1;
		else
			return 0;
	}
	friend ostream& operator<<(ostream&, Rate);

	friend istream& operator>>(istream&, Rate&);


};
ostream& operator<<(ostream& out, Rate r){
	out << "CUI:" << r.cui << endl
		<< "Numar rate:" << r.numar_rate << endl
		<< "Valoare rata:" << r.valoare_rata << endl;
	return out;
}

istream& operator>>(istream& in, Rate &r){
	double temp;
	cout << "Introduceti CUI:" << endl;
	in >> temp;
	r.cui = temp;
	cout << "Introduceti Nr rate:" << endl;
	in >> temp;
	r.numar_rate = temp;
	cout << "Introduceti valoare rata:" << endl;
	in >> temp; 
	r.valoare_rata = temp;
	return in;
}

template <class T> class Colectie
{
public:
	T v[MAX_DIM];	//vector cu max n=1000 elem
	int n;		//dimensiunea multimii(vectorului)

	Colectie();    //constructor de initializare de la tastatura
	Colectie(int); //constructor implicit
	friend ostream& operator<< <>(ostream&, Colectie<T>&);	//supraincarcare operator <<
	friend istream& operator>> <>(istream&, Colectie<T>&);	//supraincarcare operator >>
	void operator +(T); //adaugare element nou
	void operator -(T); //extragere de element din multime
	void sortare();     //functie de sortare
};

template <class T> Colectie<T>::Colectie(int dim)
{
	n = dim;
	for (int i = 0; i < n; i++)
		v[i] = T();
	
}

template <class T> Colectie<T>::Colectie()
{
	int dim;
	cout << endl << "Nr.de elem pt multime: ";
	cin >> dim;
	n = dim;

	for (int i = 0; i<dim; i++) {
		cout << "Introduceti elementul " << i << "  ";
		cin >> v[i];
	}
}

//supraincarcarea operatorului <<
template <class T> ostream& operator<< <>(ostream& output, Colectie<T> &ob)
{
	output << endl;
	output << endl << "Indexul are " << ob.n << " elemente" << endl;
	for (int i = 0; i<ob.n; i++)
		output << "\n Elementul " << i << " " << ob.v[i];

	return output;
}

template <class T> ostream& operator<< <>(ostream& output, Colectie<T*> &ob)
{
	output << endl;
	output << endl << "Indexul are " << ob.n << " elemente" << endl;
	for (int i = 0; i<ob.n; i++)
		output << "\n Elementul " << i << " " << ob.v[i];

	return output;
}
//supraincarcarea operatorului >>
template<class T> istream &operator>> <>(istream& input, Colectie<T> &ob)
{
	int dim;
	cout << "Dimensiunea";
	input >> dim;
	n = dim;

	for (i = 0; i<n; i++) {
		cout << "Element";
		input >> ob.v[i];
	}

	return input;
}

//supraincarcarea operatorului + pentru adaugare de nou element
template<class T> void Colectie<T>::operator +(T nou)
{
	int i, exista;
	exista = 0;

	for (i = 0; i<n; i++)
		if (v[i] == nou) exista = 1;

	if (exista == 0) {
		n++;
		v[n - 1] = nou;
	}
	else
		cout << "Elementul pe care il inserati exista in multime"<<endl;
}

//supraincarea operatorului - pentru extragere de element
template<class T> void Colectie<T>::operator -(T extrag)
{
	int i, exista, j;
	exista = 0;
	i = 0;

	while ((i<n) && (exista == 0)) {
		if (v[i] == extrag)
			exista = 1;//iese din while cu extrag pe poz i-1
		i++;
	}

	if (exista == 1) {
		for (j = i - 1; j<n - 1; j++) v[j] = v[j + 1];//se suprascriu
		n--;
	}
	else
		cout << "Elementul nu se gaseste in multime";
}



void menu(){
	cout << "-------------------------------------------------------" << endl;
	cout << endl;
	cout << "1 - Vizualizare colectii" << endl;
	cout << "2 - Introducere element de adaugat" << endl;
	cout << "3 - Vizualizare element de adaugat" << endl;
	cout << "4 - Adaugare element" << endl;
	cout << "5 - Introducere element de sters" << endl;
	cout << "6 - Vizualizare element de sters" << endl;
	cout << "7 - Stergere element" << endl;
	cout << "0 - Terminare" << endl << endl;
	cout << "Introduceti optiunea: ";


}

void main(){
	int opt = 2;
	Colectie<Client*> ClientColectie(1);
	Colectie<Rate> ColectieRate(1);
	Colectie<Credit> ColectieCredit(1);
	PersFizica inserareP, stergereP;
	Firma inserareF, stergereF;
	Rate inserareR, stergereR;
	Credit inserareC, stergereC;
	ifstream in("credit.txt");
	Credit text;
	in >> text;
	do {
		do {
			menu();
			cin >> opt;
		} while (opt<0 || opt>8);

		switch (opt)
		{
		case 1:
			cout << endl;
			cout << ClientColectie;
			cout << endl;
			cout << ColectieCredit;
			cout << endl;
			cout << ColectieRate;
			cout << endl;
			break;
		case 2:
				cout << "1-Persoana Fizica" << endl;
				cout << "2-Firma" << endl;
				cout << "3-Credit" << endl;
				cout << "4-Rate" << endl;
				cin >> opt;
				switch (opt){
				case 1:
					cin >> inserareP;
					cout << endl;
					break;
				case 2:
					cin >> inserareF;
					cout << endl;
					break;
				case 3:
					cin >> inserareC;
					cout << endl;
					break;
				case 4:
					cin >> inserareR;
					cout << endl;
					break;
				}
			break;
		case 3:
			cout <<inserareP<<endl
				<<inserareF<<endl
				<<inserareC<<endl
				<<inserareR<<endl;
			cout << endl << endl;
			break;
		case 4:
			ClientColectie + &inserareP;
			ClientColectie + &inserareF;
			ColectieCredit + inserareC;
			ColectieRate + inserareR;
			break;
		case 5:
			cin >> opt;
			switch (opt){
		case 1:
			cin >> stergereP;
			cout << endl;
			break;
		case 2:
			cin >> stergereF;
			cout << endl;
			break;
		case 3:
			cin >> stergereC;
			cout << endl;
			break;
		case 4:
			cin >> stergereR;
			cout << endl;
			break;
		}
			break;
		case 6:
			cout << stergereP << endl
				<< stergereF << endl
				<< stergereC << endl
				<< stergereR << endl;
			cout << endl << endl;
			break;
		case 7:
			ClientColectie - &stergereP;
			ClientColectie - &stergereF;
			ColectieCredit - stergereC;
			ColectieRate - stergereR;
			break;
		case 0:
			break;
		}

	} while (opt);
}

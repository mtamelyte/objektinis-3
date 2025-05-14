#include "headers/antrastesBeTemplates.h"

// copy constructorius
Stud::Stud(const Stud &s) : Zmogus(s.vardas, s.pavarde), egzaminas(s.egzaminas), nd{s.nd}, galutinisSuVidurkiu(s.galutinisSuVidurkiu), galutinisSuMediana(s.galutinisSuMediana) {}

// copy assignment operator
Stud &Stud::operator=(const Stud &s)
{
    if (this != &s)
    {
        vardas = s.vardas;
        pavarde = s.pavarde;
        egzaminas = s.egzaminas;
        nd = s.nd; 
        galutinisSuVidurkiu = s.galutinisSuVidurkiu;
        galutinisSuMediana = s.galutinisSuMediana;
    }
    return *this;
}

// move konstruktorius
Stud::Stud(Stud &&s) : Zmogus(move(s)), egzaminas(s.egzaminas), nd{move(s.nd)}, galutinisSuVidurkiu(move(s.galutinisSuVidurkiu)), galutinisSuMediana(move(s.galutinisSuMediana)) {s.~Stud();}

// move assignment operatorius
Stud &Stud::operator=(Stud &&s)
{
    if (this != &s)
    {
        Zmogus::operator=(move(s));
        egzaminas = move(s.egzaminas);
        nd = move(s.nd);
        galutinisSuVidurkiu = move(s.galutinisSuVidurkiu);
        galutinisSuMediana = move(s.galutinisSuMediana);
    }
    s.~Stud();
    return *this;
}

//input operatorius
istream & operator>>(istream &is, Stud & s)
{
    int paz;
    is >> s.vardas >> s.pavarde;
    while (is >> paz)
    {
        s.nd.push_back(paz);
    }
    if (s.nd.empty()) {
        throw std::runtime_error("Nera pazymiu");
    }
    s.egzaminas = s.nd.back();
    s.nd.pop_back();
    s.galutinisSuVidurkiu = (vidurkis(s.nd) * 0.4) + (s.egzaminas * 0.6);
    s.galutinisSuMediana = (mediana(s.nd) * 0.4) + (s.egzaminas * 0.6);
    return is;
}

//output operatorius
ostream & operator << ( ostream & os, Stud & s ){
    os << setw(16) << s.vardas << setw(16) << s.pavarde << setw(20) << fixed << setprecision(2) << s.galutinisSuVidurkiu << endl;
    return os;
}

Zmogus::~Zmogus() { vardas=""; pavarde=""; }
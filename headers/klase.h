#include "vektorius.h"
double vidurkis(vector<int> nd);
double mediana(vector<int> nd);
class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() : vardas(""), pavarde("") {}                                       // konstruktorius
    Zmogus(const string &var, const string &pav) : vardas(var), pavarde(pav) {} // konstruktorius su inputu
    virtual ~Zmogus() = 0;
    // setteriai
    void setVardas(const string &var) { vardas = var; };
    void setPavarde(const string &pav) { pavarde = pav; };
    // getteriai
    const string getVardas() const { return vardas; };
    const string getPavarde() const { return pavarde; };

    Zmogus(Zmogus &&z) : vardas(move(z.vardas)), pavarde(move(z.pavarde)) {}
    Zmogus &operator=(Zmogus &&z)
    {
        if (this != &z)
        {
            vardas = move(z.vardas);
            pavarde = move(z.pavarde);
        }
        return *this;
    }
};
class Stud : public Zmogus
{
private:
    double egzaminas;
    vector<int> nd;
    double galutinisSuVidurkiu;
    double galutinisSuMediana;

public:
    Stud() : Zmogus("", ""), egzaminas(0), nd{}, galutinisSuVidurkiu(0), galutinisSuMediana(0) {}                                                                                                                                                       // konstruktorius
    Stud(const string &var, const string &pav, const int &egz, const vector<int> &nd_) : Zmogus(var, pav), egzaminas(egz), nd{nd_}, galutinisSuVidurkiu((vidurkis(nd_) * 0.4) + (egz * 0.6)), galutinisSuMediana((mediana(nd_) * 0.4) + (egz * 0.6)) {} // konstruktorius su inputu
    Stud(const string &var, const string &pav, const int &egz) : Zmogus(var, pav), egzaminas(egz), nd{}, galutinisSuVidurkiu((egz * 0.6)), galutinisSuMediana((egz * 0.6)) {}                                                                           // konstruktorius su inputu
    Stud(const Stud &s);
    Stud &operator=(const Stud &s);
    Stud(Stud &&s);
    Stud &operator=(Stud &&s);
    ~Stud()
    {
        nd.clear();
        egzaminas = 0;
        galutinisSuVidurkiu = 0;
        galutinisSuMediana = 0;
    }
    friend istream &operator>>(istream &is, Stud &s);
    friend ostream &operator<<(ostream &os, Stud &s);
    // setteriai
    void setEgzaminas(const double &egz) { egzaminas = egz; };
    void setND(const vector<int> &nd_) { nd = nd_; };
    void setPazymys(const int &paz) { nd.push_back(paz); };
    void setGalutinisSuVidurkiu(const double &vid) { galutinisSuVidurkiu = vid; };
    void setGalutinisSuMediana(const double &med) { galutinisSuMediana = med; };
    // getteriai
    const double getEgzaminas() const { return egzaminas; };
    vector<int> getND() const { return nd; };
    int getPazymys(int &i) const { return nd.at(i); };
    double getGalutinisSuVidurkiu() const { return galutinisSuVidurkiu; };
    double getGalutinisSuMediana() const { return galutinisSuMediana; };

    // papildomos funkcijos
    bool operator==(const Stud &s) const
    {
        if (vardas == s.vardas && pavarde == s.pavarde && egzaminas == s.egzaminas && nd == s.nd)
            return true;
        else
            return false;
    }
    bool operator!=(const Stud &s) const
    {
        if (vardas != s.vardas || pavarde != s.pavarde || egzaminas != s.egzaminas || nd != s.nd)
            return true;
        else
            return false;
    }
};
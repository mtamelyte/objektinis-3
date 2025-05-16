#include "mano_lib.h"
#include "antrastesBeTemplates.h"

template <typename Container>
void ivedimas(Container &studentai, int &meniuPasirinkimas)
{
    bool naujasStudentas = true;
    int pasirinkimas;
    while (naujasStudentas)
    {
        Stud laik;
        if (meniuPasirinkimas == 1 || meniuPasirinkimas == 2)
            vardoIvedimas(laik);
        if (meniuPasirinkimas == 1)
            pazymiuIvedimas(laik);
        else if (meniuPasirinkimas == 2)
            pazymiuGeneravimas(laik);
        else if (meniuPasirinkimas == 3)
        {
            vardoGeneravimas(laik);
            pazymiuGeneravimas(laik);
        }
        laik.setGalutinisSuVidurkiu((vidurkis(laik.getND()) * 0.4) + (laik.getEgzaminas() * 0.6));
        laik.setGalutinisSuMediana((mediana(laik.getND()) * 0.4) + (laik.getEgzaminas() * 0.6));
        studentai.push_back(laik);
        while (true)
        {
            try
            {
                cout << "Ar norite įvesti dar vieną studentą?" << endl;
                cout << "1 - taip" << endl;
                cout << "2 - ne" << endl;
                cin >> pasirinkimas;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw "Įvedėte ne skaičių!";
                }
                else if (pasirinkimas < 1 || pasirinkimas > 2)
                    throw "Įvedėte netinkamą skaičių!";
                else
                    break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                continue;
            }
        }
        if (pasirinkimas == 2)
            naujasStudentas = false;
    }
}

template <typename Container>
void nuskaitymasSuBuferiu(Container &studentai, string failoPavadinimas)
{
    vector<string> laik;
    string eilute;
    stringstream buferis;
    ifstream fin;
    while (true)
    {
        try
        {
            fin.open(failoPavadinimas);
            if (fin.fail())
            {
                throw "Nepavyko atidaryti failo.";
            }
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            failoPavadinimas = failoPasirinkimas("Pasirinkite kitą failą: ");
            continue;
        }
    }
    buferis << fin.rdbuf();
    fin.close();

    while (buferis)
    {
        if (!buferis.eof())
        {
            getline(buferis, eilute);
            laik.push_back(eilute);
        }
        else
            break;
    }
    studentai.clear();
    int skaicius;
    bool pirmaEilute = true;
    for (string a : laik)
    {
        string vardas, pavarde;
        istringstream is(a);
        Stud laikStudentas;
        if (pirmaEilute == true)
            pirmaEilute = false;
        else
        {
            is >> laikStudentas;
            studentai.push_back(move(laikStudentas));
        }
    }
}

template <typename Container>
void isvedimas(Container &studentai, int galutinioBaloPasirinkimas, ostream &isvedimoBudas)
{
    stringstream buferis;
    buferis << setw(16) << left << "Vardas" << setw(16) << "Pavarde";
    if (galutinioBaloPasirinkimas == 1)
        buferis << setw(20) << "Galutinis (Vid.)" << endl;
    else
        buferis << setw(20) << "Galutinis (Med.)" << endl;
    buferis << "--------------------------------------------------------------" << endl;
    for (Stud i : studentai)
    {
        buferis << i;
    }
    isvedimoBudas << buferis.rdbuf();
    studentai.clear();
}

template <typename Container>
void rusiavimas(Container &studentai, int pasirinkimas)
{
    if constexpr (std::is_same_v<Container, list<Stud>>)
    {
        if (pasirinkimas == 1)
            studentai.sort(pagalVarda);
        else if (pasirinkimas == 2)
            studentai.sort(pagalPavarde);
        else if (pasirinkimas == 3)
            studentai.sort(pagalVidurki);
        else if (pasirinkimas == 4)
            studentai.sort(pagalMediana);
    }
    else
    {
        if (pasirinkimas == 1)
            sort(studentai.begin(), studentai.end(), pagalVarda);
        if (pasirinkimas == 2)
            sort(studentai.begin(), studentai.end(), pagalPavarde);
        if (pasirinkimas == 3)
            sort(studentai.begin(), studentai.end(), pagalVidurki);
        if (pasirinkimas == 4)
            sort(studentai.begin(), studentai.end(), pagalMediana);
    }
}

template <typename Container>
void tyrimas(Container &studentai)
{
    int tyrimoPasirinkimas, rusPasirinkimas, kiekioPasirinkimas, galBaloPasirinkimas, skirstymoPasirinkimas;
    string sugeneruotasFailas;
    while (true)
    {
        try
        {
            cout << "Kuri tyrima nori atlikti?" << endl;
            cout << "1" << endl;
            cout << "2" << endl;
            cin >> tyrimoPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (tyrimoPasirinkimas < 1 || tyrimoPasirinkimas > 2)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    while (true)
    {
        try
        {
            cout << "Kuria rusiavimo strategija noretum naudoti?" << endl;
            cout << "1" << endl;
            cout << "2" << endl;
            cout << "3" << endl;
            cin >> skirstymoPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (skirstymoPasirinkimas < 1 || skirstymoPasirinkimas > 3)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    if (tyrimoPasirinkimas == 2)
    {
        rusPasirinkimas = rusiavimoPasirinkimas();
    }
    while (true)
    {
        try
        {
            cout << "Kiek kartu nori atlikti tyrima?" << endl;
            cin >> kiekioPasirinkimas;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw "Įvedėte ne skaičių!";
            }
            else if (kiekioPasirinkimas < 1)
                throw "Įvedėte netinkamą skaičių!";
            else
                break;
        }
        catch (const char *e)
        {
            cout << e << endl;
            continue;
        }
    }
    for (int dydzioPasirinkimas = 1000; dydzioPasirinkimas <= 10000000; dydzioPasirinkimas *= 10)
    {
        double vid = 0;
        for (int j = 0; j < kiekioPasirinkimas; j++)
        {
            auto pradzia = std::chrono::high_resolution_clock::now();
            if (tyrimoPasirinkimas == 1)
            {
                auto t1 = std::chrono::high_resolution_clock::now();
                failoGeneravimas(dydzioPasirinkimas);
                auto t2 = std::chrono::high_resolution_clock::now();
                cout << dydzioPasirinkimas << " studentu failo sugeneravimas truko " << (t2 - t1) / 1.0s << " " << endl;
            }
            if (tyrimoPasirinkimas == 2)
            {
                Container protingi;
                Container neprotingi;
                studentai.clear();
                auto t3 = std::chrono::high_resolution_clock::now();
                nuskaitymasSuBuferiu(studentai, "studentai" + to_string(dydzioPasirinkimas) + ".txt");
                auto t4 = std::chrono::high_resolution_clock::now();
                cout << "Failo nuskaitymas truko: " << (t4 - t3) / 1.0s << " s." << endl;
                rusiavimas(studentai, 3);
                if (skirstymoPasirinkimas == 1)
                    pirmaStrategija(studentai, protingi, neprotingi, 1);
                else if (skirstymoPasirinkimas == 2)
                    antraStrategija(studentai, neprotingi);
                else
                    treciaStrategija(studentai, neprotingi);
                auto t7 = std::chrono::high_resolution_clock::now();
                cout << "Isskaidymas pagal galutini bala truko: " << (t7 - t4) / 1.0s << " s." << endl;
                if (skirstymoPasirinkimas == 1)
                    rusiavimas(protingi, rusPasirinkimas);
                else
                    rusiavimas(studentai, rusPasirinkimas);
                rusiavimas(neprotingi, rusPasirinkimas);
                auto t5 = std::chrono::high_resolution_clock::now();
                cout << "Studentu konteinerio surusiavimas truko: " << (t5 - t7) / 1.0s << " s." << endl;
            }
            auto pabaiga = std::chrono::high_resolution_clock::now();
            vid += ((pabaiga - pradzia) / 1.0s);
        }
        cout << "Vidutiniskai tyrimas su " << dydzioPasirinkimas << " studentu uztruko " << vid / kiekioPasirinkimas << " s." << endl;
        cout << endl;
    }
}

template <typename Container>
void pirmaStrategija(Container &studentai, Container &protingi, Container &neprotingi, int galutinisBalas)
{
    for (Stud s : studentai)
    {
        if (galutinisBalas == 1)
        {
            if (s.getGalutinisSuVidurkiu() >= 5)
                protingi.push_back(s);
            else
                neprotingi.push_back(s);
        }
        else
        {
            if (s.getGalutinisSuMediana() >= 5)
                protingi.push_back(s);
            else
                neprotingi.push_back(s);
        }
    }
    if constexpr (std::is_same_v<Container, vector<Stud>>)
    {
        protingi.shrink_to_fit();
        neprotingi.shrink_to_fit();
    }
}

template <typename Container>
void antraStrategija(Container &studentai, Container &neprotingi)
{
    while (studentai.back().getGalutinisSuVidurkiu() < 5)
    {
        neprotingi.push_back(studentai.back());
        studentai.pop_back();
    }
    if constexpr (std::is_same_v<Container, vector<Stud>>)
    {
        neprotingi.shrink_to_fit();
        studentai.shrink_to_fit();
    }
}

template <typename Container>
void treciaStrategija(Container &studentai, Container &neprotingi)
{
    auto it = stable_partition(studentai.begin(), studentai.end(), [](Stud &a)
                            { return a.getGalutinisSuVidurkiu() >= 5; });
    neprotingi.assign(it, studentai.end());
    studentai.resize(std::distance(studentai.begin(), it));
    if constexpr (std::is_same_v<Container, vector<Stud>>)
    {
        neprotingi.shrink_to_fit();
        studentai.shrink_to_fit();
    }
}
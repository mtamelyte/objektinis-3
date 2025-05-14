#define CATCH_CONFIG_MAIN

#include "headers/vektorius.h"
#include "catch2/catch.hpp"

TEST_CASE()

/*
    // konstruktoriai destruktoriai
    Vector() = default;

    Vector(std::initializer_list<T> list) : talpa(list.size()), dydis(list.size())
    {
        duomenys = new T[talpa];
        std::copy(list.begin(), list.end(), duomenys);
    }

    Vector &operator=(std::initializer_list<T> list)
    {
        talpa = list.size();
        duomenys = new T[talpa];
        std::copy(list.begin(), list.end(), duomenys);
        dydis = talpa;
        return *this;
    }

    ~Vector()
    {
        delete[] duomenys;
        dydis = 0;
        talpa = 0;
    }

    // copy constructor
    Vector(const Vector &v) : dydis(v.dydis), talpa(v.talpa)
    {
        duomenys = new T[talpa];
        for (size_t i = 0; i < dydis; i++)
        {
            duomenys[i] = v.duomenys[i];
        }
    }

    // copy assignment operator
    Vector &operator=(const Vector &v)
    {
        if (this != &v)
        {
            delete[] duomenys;
            dydis = v.dydis;
            talpa = v.talpa;
            duomenys = new T[talpa];
            for (size_t i = 0; i < dydis; i++)
            {
                duomenys[i] = v.duomenys[i];
            }
        }
        return *this;
    }

    // move constructor
    Vector(Vector &&v) noexcept : duomenys(v.duomenys), talpa(v.talpa), dydis(v.dydis)
    {
        v.duomenys = nullptr;
        v.talpa = 0;
        v.dydis = 0;
    }

    // move assignment operator
    Vector &operator=(const Vector &&v)
    {
        if (this != &v)
        {
            delete[] duomenys;
            dydis = v.dydis;
            talpa = v.talpa;
            {
                duomenys = new T[talpa];
                for (size_t i = 0; i < dydis; i++)
                {
                    duomenys[i] = v.duomenys[i];
                }
            }
        }
        v.duomenys = nullptr;
        v.talpa = 0;
        v.dydis = 0;
        return *this;
    }

    // grazinamos reiksmes

    T *begin() { return duomenys; }
    const T *begin() const { return duomenys; }

    T *end() { return duomenys + dydis; }
    const T *end() const { return duomenys + dydis; }

    T *rbegin()
    {
        if (dydis == 0)
            return duomenys;
        else
            duomenys + dydis - 1;
    }

    T *rend()
    {
        if (dydis == 0)
            return duomenys;
        else
            duomenys - 1;
    }

    const T *cbegin() const { return duomenys; }
    const T *cend() const { return duomenys + dydis; }

    T &front()
    {
        return this->at(0);
    }

    T &back()
    {
        return this->at(dydis - 1);
    }

    T *data()
    {
        return duomenys;
    }

    T *data() const
    {
        return duomenys;
    }

    size_t size()
    {
        return dydis;
    }

    size_t capacity()
    {
        return talpa;
    }

    bool empty() const
    {
        if (dydis == 0)
            return true;
        else
            return false;
    }

    void push_back(const T &elementas)
    {
        if (dydis == talpa)
        {
            resize();
        }
        duomenys[dydis] = elementas;
        ++dydis;
    }

    void pop_back()
    {
        if (dydis > 0)
        {
            --dydis;
        }
    }

    void swap(Vector &v)
    {
        std::swap(duomenys, v.duomenys);
        std::swap(dydis, v.dydis);
        std::swap(talpa, v.talpa);
    }

    void clear()
    {
        dydis = 0;
        talpa = 0;
        delete[] duomenys;
        duomenys = nullptr;
    }

    void assign(size_t kiekis, const T &elementas)
    {
        if (kiekis > talpa)
            resize(kiekis);
        std::fill_n(duomenys, kiekis, elementas);
        dydis = kiekis;
    }

    void assign(T *begin, T *end)
    {
        size_t kiekis = std::distance(begin, end);
        if (kiekis > talpa)
            resize(kiekis);
        std::copy(begin, end, duomenys);
        dydis = kiekis;
    }

    void assign(std::initializer_list<T> list)
    {
        size_t kiekis = list.size();
        if (kiekis > talpa)
            resize(kiekis);
        std::copy(list.begin(), list.end(), duomenys);
        dydis = kiekis;
    }

    void resize(size_t naujaTalpa)
    {
        talpa = naujaTalpa;
        T *naujiDuomenys = new T[talpa];
        for (size_t i = 0; i < dydis; ++i)
        {
            naujiDuomenys[i] = duomenys[i];
        }
        delete[] duomenys;
        duomenys = naujiDuomenys;
    }

    void resize(size_t naujaTalpa, const T &elementas)
    {
        talpa = naujaTalpa;
        T *naujiDuomenys = new T[talpa];
        for (size_t i = 0; i < dydis; ++i)
        {
            naujiDuomenys[i] = duomenys[i];
        }
        for (size_t i = dydis; i < talpa; ++i)
        {
            naujiDuomenys[i] = elementas;
        }
        dydis = talpa;
        delete[] duomenys;
        duomenys = naujiDuomenys;
    }

    void reserve(size_t naujaTalpa)
    {
        resize(naujaTalpa);
    }

    void shrink_to_fit()
    {
        if (dydis < talpa)
            resize(dydis);
    }

    void erase(T *index)
    {
        size_t vieta = index - duomenys;
        if (index > duomenys + dydis || index < duomenys || vieta < 0)
        {
            throw std::out_of_range("Out of range: " + std::to_string(vieta) + " >= this->size: " + std::to_string(this->dydis));
        }
        for (size_t i = vieta; i + 1 < dydis; ++i)
        {
            duomenys[i] = duomenys[i + 1];
        }
        --dydis;
    }

    void erase(T *begin, T *end)
    {
        size_t kiekis = std::distance(begin, end);
        size_t vieta = begin - duomenys;
        for (size_t i = vieta; i + kiekis < dydis; ++i)
        {
            duomenys[i] = duomenys[i + kiekis];
        }
        dydis -= kiekis;
    }

    void insert(T *index, const T &elementas)
    {
        size_t vieta = index - duomenys;
        if (dydis == talpa)
            resize();
        for (size_t i = dydis; i > vieta + 1; i--)
        {
            duomenys[i] = duomenys[i - 1];
        }
        duomenys[vieta] = elementas;
        dydis++;
    }


    T &at(size_t index)
    {
        if (index >= dydis || index < 0)
        {
            throw std::out_of_range("Out of range: " + std::to_string(index) + " >= this->size: " + std::to_string(this->dydis));
        }
        return duomenys[index];
    }

    void append_range(std::initializer_list<T> list)
    {
        if (dydis + list.size() > talpa)
        {
            reserve(talpa + list.size());
        }
        for (auto &elementas : list)
        {
            duomenys[dydis++] = elementas;
        }
    }

    // operatoriu overloadai
    T &operator[](size_t index)
    {
        if (index >= dydis)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return duomenys[index];
    }

    bool operator==(const Vector&v){
        if(dydis != v.dydis) return false;
        for(int i=0; i<dydis; i++)
        {
            if (duomenys[i]!= v.duomenys[i]) return false;
        }
        return true;
    }
};*/



/*
int main(){
 /* Vector <int> vektorius;
    vektorius.push_back(2);
    cout << vektorius[0] << endl;

    Vector<int> vektorius2(vektorius);
    vektorius2.push_back(4);
    vektorius2.push_back(4);
    cout << vektorius2[1] << endl;

    Vector<int> vektorius3 =std::move(vektorius2);
    vektorius3.pop_back();
    cout << vektorius3[1]<< endl;

    Vector <int> antras;/*
    antras.push_back(6);
    cout << antras[0] << endl;
    antras.swap(vektorius3);
    cout << antras[0] << endl;

    antras.clear();

    antras.assign(4, 7);
    cout << antras[0] << antras[1] << antras[2] << endl;

    antras.clear();
    antras.assign(vektorius.begin(), vektorius.end());
    cout << antras[0] << endl;
    
    antras.reserve(25);
    antras.assign({1, 1, 1, 1, 1, 1});
    antras.shrink_to_fit();
    antras.push_back(34);
    antras.push_back(12);
    cout << antras[7];

    antras.clear();
    antras.assign({1,2,3,4,5,6,7,8,9});
    cout << antras[3] << endl;
    antras.erase(antras.begin(), antras.begin()+3);
    cout << antras[3] << endl;

    vector <int> vektorius;
    vektorius.clear();
    vektorius.assign({1,2,3,4,5,6,7,8,9});
    cout << vektorius[3] << endl;
    vektorius.erase(vektorius.begin(), vektorius.begin()+3);
    cout << vektorius[3] << endl;

    antras.insert(antras.begin(), 5);
    vektorius.insert(vektorius.begin(), 5);
    cout << antras[0] << endl;
    cout << vektorius[0] << endl;

    antras.assign({1,2,3,4,7,8,9});
    antras.insert_range(antras.begin()+4, {5, 6});
    for(int i=0; i<antras.size(); i++)
    {
        cout << antras[i] << endl;
    }
}*/
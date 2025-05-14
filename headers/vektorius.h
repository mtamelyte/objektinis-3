#include "mano_lib.h"
template <typename T>
class Vector
{
private:
    T *duomenys = nullptr;
    size_t dydis = 0;
    size_t talpa = 0;

    void resize()
    {
        talpa *= 2;
        T *naujiDuomenys = new T[talpa];
        for (size_t i = 0; i < dydis; ++i)
        {
            naujiDuomenys[i] = duomenys[i];
        }
        delete[] duomenys;
        duomenys = naujiDuomenys;
    }

    void resize(size_t dydis_){
        talpa = dydis_;
        T *naujiDuomenys = new T[talpa];
        for (size_t i = 0; i < dydis; ++i)
        {
            naujiDuomenys[i] = duomenys[i];
        }
        delete[] duomenys;
        duomenys = naujiDuomenys;
    }

public:
    // konstruktoriai destruktoriai
    Vector() = default;
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

    void push_back(const T &elementas)
    {
        if (dydis == talpa)
        {
            resize(talpa*2);
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

    void clear(){
        dydis = 0;
        talpa = 0;
        delete [] duomenys;
        duomenys = nullptr;
    }

    void assign(size_t kiekis, const T& elementas){
        if(kiekis>talpa) 
        {
            resize(kiekis); 
            dydis=kiekis;
        }
        std::fill_n(duomenys, kiekis, elementas);
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
};
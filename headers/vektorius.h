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

    Vector(std::initializer_list<T> list) : talpa(list.size()), dydis(list.size()) {
        duomenys = new T[talpa];
        std::copy(list.begin(), list.end(), duomenys);
    }

    Vector& operator=( std::initializer_list<value_type> list ){
        talpa=list.size();
        duomenys = new T[talpa];
        std::copy(list.begin(), list.end(), duomenys);
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

    //grazinamos reiksmes

    T* begin(){
        return duomenys;
    }

    T* end(){
        return duomenys+dydis;
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
        if(kiekis>talpa) resize(kiekis); 
        std::fill_n(duomenys, kiekis, elementas);
        dydis=kiekis;
    }

    void assign(T* begin, T* end)
    {
        size_t kiekis = std::distance(begin, end);
        if(kiekis>talpa) resize(kiekis);
        std::copy(begin, end, duomenys);
        dydis=kiekis;
    }

    void assign(std::initializer_list<T> ilist) {
        size_t kiekis = ilist.size();
        if (kiekis > talpa) resize(kiekis);
        std::copy(ilist.begin(), ilist.end(), duomenys);
        dydis = kiekis;
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
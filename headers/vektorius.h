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
        if (talpa == 0)
            talpa = 1;
        else
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
    }

public:
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

    T *begin()
    {
        return duomenys;
    }

    T *end()
    {
        return duomenys + dydis;
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

    void assign(std::initializer_list<T> ilist)
    {
        size_t kiekis = ilist.size();
        if (kiekis > talpa)
            resize(kiekis);
        std::copy(ilist.begin(), ilist.end(), duomenys);
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

    void resize(size_t naujaTalpa, const T& elementas)
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
        dydis=talpa;
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
        for (size_t i = dydis; i > vieta; i--)
        {
            duomenys[i] = duomenys[i - 1];
        }
        duomenys[vieta] = elementas;
        dydis++;
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
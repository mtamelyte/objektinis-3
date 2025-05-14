#include "headers/antrastesBeTemplates.h"

template <typename T>
Vector<T>::Vector(const Vector &v) : dydis(v.dydis), talpa(v.talpa){
    duomenys = new T[talpa];
    for(size_t i = 0; i < dydis; i++)
    {
        duomenys[i]=v.duomenys[i];
    }
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector &v);
{
    if(this!=&v){
        delete[] duomenys;
        dydis=v.dydis;
        talpa=v.talpa;
        duomenys = new T[talpa];
        for(size_t i=0; i<dydis; i++)
        {
            duomenys[i]=v.duomenys[i];
        }
    }
    return *this;
}

template <typename T>
Vector<T>::Vector(const Vector &&v) : dydis(v.dydis), talpa(v.talpa), duomenys(v.duomenys) {v.~Vector();}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector &&v)
{
    if(this!=&v){
        delete[] duomenys;
        dydis=v.dydis;
        talpa=v.talpa;
        duomenys = v.duomenys;
    }
    v.~Vector();
    return *this;
}
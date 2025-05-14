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

template <typename T>
void Vector<T>::resize() {
    talpa *= 2;
    T* naujiDuomenys = new T[talpa];
    for (size_t i = 0; i < dydis; ++i) {
        naujiDuomenys[i] = duomenys[i];
    }
    delete[] duomenys;
    duomenys = naujiDuomenys;
}

template <typename T>
void Vector<T>::push_back(const T& elementas) {
    if (dydis == talpa) {
        resize(); // Resize if we reach capacity
    }
    arr[dydis] = elementas;
    ++dydis;
}

template <typename T>
void Vector<T>::pop_back() {
    if (dydis > 0) {
        --dydis;
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= dydis) {
        throw std::out_of_range("Index out of bounds");
    }
    return duomenys[index];
}
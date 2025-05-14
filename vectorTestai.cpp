#include "headers/vektorius.h"

int main(){
    Vector <int> vektorius;
    vektorius.push_back(2);
    cout << vektorius[0] << endl;

    Vector<int> vektorius2(vektorius);
    vektorius2.push_back(4);
    vektorius2.push_back(4);
    cout << vektorius2[1] << endl;

    Vector<int> vektorius3 =std::move(vektorius2);
    vektorius3.pop_back();
    cout << vektorius3[1]<< endl;

    Vector <int> antras;
    antras.push_back(6);
    cout << antras[0] << endl;
    antras.swap(vektorius3);
    cout << antras[0] << endl;

   // antras.clear();

    antras.assign(2, 2);
    cout << antras[0] << antras[1] << antras[2] << endl;
}
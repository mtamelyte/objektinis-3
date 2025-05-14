#include "headers/vektorius.h"

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
*/
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
    cout << vektorius[0] << endl;*/

    antras.assign({1});
    antras.resize(5, 2);
    cout << antras[2] << endl;
}
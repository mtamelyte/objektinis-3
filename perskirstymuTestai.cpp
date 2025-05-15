#include "headers/antrastesSuTemplates.h"

int main()
{
    unsigned int sz = 100000000;

    vector<int> v1;
    int k1=0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= sz; ++i)
    {
        if(v1.size()==v1.capacity()) k1++;
        v1.push_back(i);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    Vector<int> v2;
    int k2=0;
    auto t3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= sz; ++i)
    {
        if(v2.size()==v2.capacity()) k2++;
        v2.push_back(i);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    cout << "std::vector: " << (t2-t1)/1.0s << " " << k1 << endl;
    cout << "Vector klase:" << (t4-t3)/1.0s << " " << k2 << endl;
}
#define CATCH_CONFIG_MAIN

#include "headers/vektorius.h"
#include "catch2/catch.hpp"

TEST_CASE("Konstruktorius", "[Constructor]")
{
    Vector<int> v1, v2;
    REQUIRE(v1.data() == nullptr);
    REQUIRE(v1 == v2);
}

TEST_CASE("Konstruktorius su sarasu", "[List][constructor]")
{
    Vector<int> v1{1, 2, 3};
    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    REQUIRE(v1 == v2);
}

TEST_CASE("Assignment su sarasu", "[List][assignment]")
{
    Vector<int> v1={1, 2, 3};
    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    REQUIRE(v1 == v2);
}

TEST_CASE("Copy constructor", "[Copy][constructor]")
{
    Vector <int> v1={1,2,3};
    Vector <int> v2(v1);
    REQUIRE(v1==v2);
}

TEST_CASE("Copy assignment", "[Copy][assignment]")
{
    Vector <int> v1={1,2,3};
    Vector <int> v2=v1;
    REQUIRE(v1==v2);
}

TEST_CASE("Move constructor", "[Move][constructor]"){
    Vector <int> v1={1,2,3};
    Vector <int> v2(std::move(v1));
    REQUIRE_FALSE(v1==v2);
    REQUIRE(v2==Vector <int>{1, 2, 3});
}

TEST_CASE("Move assignment", "[Move][assignment]"){
    Vector <int> v1={1,2,3};
    Vector <int> v2 = std::move(v1);
    REQUIRE_FALSE(v1==v2);
    REQUIRE(v2==Vector <int>{1, 2, 3});
}

TEST_CASE("Grazinamos reiksmes", "[return]"){
    Vector <int> v1{1, 2, 3};
    REQUIRE(*v1.begin()==1);
    REQUIRE(*(v1.end()-1)==3);
    REQUIRE(v1.front()==1);
    REQUIRE(v1.back()==3);
    REQUIRE(v1.at(1)==2);
}

TEST_CASE("Dydis ir talpa", "[capacity]"){
    Vector <int> v1{1,2,3};
    REQUIRE(v1.size()==3);
    v1.reserve(20);
    REQUIRE(v1.capacity()==20);
    v1.shrink_to_fit();
    REQUIRE(v1.capacity()==3);
    REQUIRE(v1.size()==3);
    v1.resize(4);
    REQUIRE(v1.capacity()==4);
    v1.resize(4,4);
    REQUIRE(v1.size()==4);
    REQUIRE(v1[3]==4);
}

TEST_CASE("Isvalymas"){
    Vector <int> v1{1,2,3};
    REQUIRE_FALSE(v1.empty());
    v1.clear();
    REQUIRE(v1.empty());
}

TEST_CASE("Naujas elementas", "[push][back]")
{
    Vector <int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    REQUIRE(v1.at(0)==1);
    REQUIRE(v1.at(1)==2);
    REQUIRE(v1.at(2)==3);
}

TEST_CASE("Paskutinio elemento isemimas", "[pop][back]"){
    Vector <int> v1{1,2,3};
    REQUIRE(v1.size()==3);
    v1.pop_back();
    REQUIRE(v1.size()==2);
}

TEST_CASE("Vektoriu sukeitimas", "[swap]")
{
    Vector <int> v1{1,2,3};
    Vector <int> v2{4,5};
    v1.swap(v2);
    REQUIRE(v1.size()==2);
    REQUIRE(v2.size()==3);
    REQUIRE(v1[0]==4);
    REQUIRE(v1[1]==5);
    REQUIRE(v2[0]==1);
    REQUIRE(v2[1]==2);
    REQUIRE(v2[2]==3);
}

TEST_CASE("Priskyrimas", "[assign]"){
    Vector <char> v1;
    v1.assign(5, 'a');
    REQUIRE(v1[0]=='a');
    REQUIRE(v1[4]=='a');
    Vector <char> v2;
    v2.assign(v1.begin(), v1.end());
    REQUIRE(v1==v2);
    REQUIRE(v2[0]=='a');
    Vector <char> v3;
    v3.assign({1,2,3});
    REQUIRE(v3[0]==1);
    REQUIRE(v3[1]==2);
    REQUIRE(v3[2]==3);
}

TEST_CASE("Elementu pasalinimas", "[erase]")
{
    Vector <int> v1{1,2,3,4,5};
    REQUIRE(v1[1]==2);
    v1.erase(v1.begin()+1);
    REQUIRE(v1[1]==3);
    REQUIRE(v1.size()==4);
    v1.erase(v1.begin()+1, v1.begin()+3);
    REQUIRE(v1[1]==5);
}

TEST_CASE("Elementu pridejimas", "[insert]"){
    Vector <int> v1{1,2,3};
    v1.insert(v1.begin()+1, 4);
    REQUIRE(v1[1]==4);
    REQUIRE(v1.size()==4);
}

TEST_CASE("Saraso prijungimas prie galo"){
    Vector <int> v1{1,2,3};
    v1.append_range({4,5});
    REQUIRE(v1[3]==4);
    REQUIRE(v1[4]==5);
    REQUIRE(v1.size()==5);
}

TEST_CASE("Palyginimo operatorius", "[comparison]"){
    Vector <int> v1{1,2,3};
    Vector <int> v2{1,2,3};
    Vector <int> v3{4,5,6};
    REQUIRE(v1==v2);
    REQUIRE_FALSE(v1==v3);
}
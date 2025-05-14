#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "headers/klase.h"
#include "headers/mano_lib.h"

TEST_CASE("Testuojamas konstruktorius", "[Constructor]"){
    Stud s1, s2;
    REQUIRE(s1==Stud("","",0, {}));
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas kopijavimo konstruktorius", "[Copy][constructor]"){
    Stud s1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud s2(s1);
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas kopijavimo priskyrimo operatorius", "[Copy][assignment][operator]"){
    Stud s1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud s2=s1;
    REQUIRE(s1==s2);
}

TEST_CASE("Testuojamas move konstruktorius", "[Move][constructor]"){
    Stud studentas1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud studentas2(move(studentas1));
    REQUIRE(studentas2==Stud("Monika", "Tamelyte", 10, {8, 9, 10}));
    REQUIRE(studentas1==Stud("", "", 0, {}));
}

TEST_CASE("Testuojamas move priskyrimo operatorius", "[Move][assignment][operator]"){
    Stud studentas1("Monika", "Tamelyte", 10, {8, 9, 10});
    Stud studentas2=move(studentas1);
    REQUIRE(studentas2==Stud("Monika", "Tamelyte", 10, {8, 9, 10}));
    REQUIRE(studentas1==Stud("", "", 0, {}));
}

TEST_CASE("Testuojamas ivedimo operatorius", "[Input][operator]"){
    istringstream ivestis("Monika Tamelyte 8 9 10 10");
    Stud studentas;
    ivestis >> studentas;
    REQUIRE(studentas==Stud("Monika","Tamelyte", 10, {8, 9, 10}));
}

TEST_CASE("Testuojamas isvedimo operatorius", "[Output][operator]"){
    ostringstream isvestis, isvestisTest;
    Stud studentas("Monika", "Tamelyte", 10, {8, 9, 10});
    isvestisTest << setw(16) << "Monika" << setw(16) << "Tamelyte" << setw(20) << fixed << setprecision(2) << ((vidurkis({8, 7, 10}) * 0.4) + (10 * 0.6)) << endl;
    isvestis << studentas;
    REQUIRE(isvestis.str()==isvestisTest.str());
}

TEST_CASE("Testuojamas destruktorius", "[Destructor]"){
    Stud *studentas= new Stud("Monika", "Tamelyte", 10, {8, 9, 10});
    studentas->~Stud();
    REQUIRE(studentas->getND().empty());
    operator delete(studentas);
}

TEST_CASE("Testuojami getteriai", "[Getter]"){
    Stud s;
    s.setVardas("Monika");
    s.setPavarde("Tamelyte");
    REQUIRE(s.getVardas()=="Monika");
    REQUIRE(s.getPavarde()=="Tamelyte");
}
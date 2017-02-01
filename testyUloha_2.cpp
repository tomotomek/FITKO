// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

using namespace ::testing;

#include "riesenie.h"

TEST_F(Test, VlozMenoTrenera) {
	ZAMESTNANEC zamestnanec("Meno Prizvisko", "joga", 20);
	string temp{ "Meno Prizvisko" };
	ASSERT_EQ(temp, zamestnanec.getMeno());
}
TEST_F(Test, typKurzu) {
	ZAMESTNANEC zamestnanec("Meno Prizvisko", "joga", 20);
	string temp{ "joga" };
	ASSERT_EQ(temp, zamestnanec.getDepartment());
}
TEST_F(Test, prijmiZamestnanca) {
	ZAMESTNANEC zamestnanec("Meno Prizvisko", "joga", 20);
	cout << zamestnanec.getVolneMiesta() << endl;
	zamestnanec.prijmiZakaznika("Jano", "2017-01-03", "2017-01-03");
	cout << zamestnanec.getVolneMiesta() << endl;
	string temp{ "joga" };
	ASSERT_EQ(temp, zamestnanec.getDepartment());
}

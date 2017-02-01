// Copyright 2005, Google Inc.
// All rights reserved.

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

#include "riesenie.h"

using namespace ::testing;

//Uloha 1.
TEST_F(Test, VlozMenoZakaznika) {
	ZAKAZNIK zakaznik("Meno Priezvisko", "2017-01-10", "2017-01-10");
	string temp{ "Meno Priezvisko" };
	ASSERT_EQ(temp, zakaznik.meno());
}
TEST_F(Test, VlozPredplatenieZakaznika) {
	ZAKAZNIK zakaznik("Meno Priezvisko", "2017-01-10", "2017-01-10");
	string temp{ "2017-01-10" };
	ASSERT_EQ(temp, zakaznik.predplatene());
}
TEST_F(Test, VlozRegistraciuZakaznika) {
	ZAKAZNIK zakaznik("Meno Priezvisko", "2017-01-10", "2017-01-10");
	string temp{ "2017-01-10" };
	ASSERT_EQ(temp, zakaznik.registracia());
}

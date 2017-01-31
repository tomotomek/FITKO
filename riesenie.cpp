#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//#include "riesenie.h"

#if !defined( _RIESENIE_H_ )
#define _RIESENIE_H_
//1.uloha
class ZAKAZNIK {
	string menoPriezvisko;
	string datumRegistracie;
	string predplateneOd;
public:
	ZAKAZNIK(const string meno, const string datumRegistracie, const string preplateneOd);
	void vlozMeno(const string meno);
	void vlozDatumReg(const string date);
	void vlozPlatnostOd(const string platnost);
	const string meno() const;
	const string predplatene() const;
	const string registracia() const;
};
//2.uloha
class ZAMESTNANEC {
	string menoPriezvisko;
	string department;
	int pocetNaKurz;
	vector<vector<ZAKAZNIK>> kurzy;
public:
	ZAMESTNANEC(const string meno, const string department, const int pocetLudiNaKurz);
	void vlozMeno(const string meno);
	void vlozDepartment(const string department);
	void vytvorKurzy(const int pocet);
	void prijmiZakaznika(const string meno, const string registracia, const string predplatenie);
	const string getMeno() const;
	const string getDepartment() const;
	const int getVolneMiesta() const;
	vector<vector<ZAKAZNIK>> getKurzy();
};
//3.uloha
class KURZ {
	ZAMESTNANEC pracovnik;
	int pocetVolnychMiest;
	string cas;
	enum nazovKurzu { posilnovna, joga, zumba };
	nazovKurzu typ;
public:
	KURZ(const int pocet);
	~KURZ();
	bool pridajTrenera(const string meno, const string typ, const int pocetLudiNaKurz);
	bool zrusTrenera();
	void setPocetVolnychMiest();
	void prihlasNaKurz(const string meno);
	const string getTrener();
	const string getPocetVolnychMiest();
	void nastavTypKurzu(const char *typ);
	const char *getTypKurzu() const;
};
//4.uloha
class FITNESSCENTRUM {
	int pocetKurzov;
	vector<KURZ> kurzy;
public:
	FITNESSCENTRUM(const int pocet);
	void pridajTreneraDoKurzu(const string meno, const string typ);
	void prihlasNaKurz(const string meno, const string typKurzu, const string datum);
	void odhlasZKurzu(const string meno, const string typKurzu, const string datum);
	int getPocetVsetkychKurzov() const;
	int getPocetVolnychMiestKurzu(const char *typ) const;
	//5.uloha
	int getPocetDniDoKoncaPlatnosti(const string meno, const string typ, const string datum);
	
};
#endif

const int pocetKurzovTrenera = 2;
const bool DUMMY_BOOL = false;
const string DUMMY_STRING = "";
const int DUMMY_INT = -1;

//1.uloha
ZAKAZNIK::ZAKAZNIK(const string meno="", const string datumRegistracie = "", const string preplatene = "") {
	vlozMeno(meno);
	vlozDatumReg(datumRegistracie);
	vlozPlatnostOd(preplatene);
}
void ZAKAZNIK::vlozMeno(const string meno) {
	menoPriezvisko = meno;
}
void ZAKAZNIK::vlozDatumReg(const string date) {
	datumRegistracie = date;
}

void ZAKAZNIK::vlozPlatnostOd(const string platnost) {
	predplateneOd = platnost;
}
const string ZAKAZNIK::meno() const {
	return menoPriezvisko;
}
const string ZAKAZNIK::predplatene() const {
	return predplateneOd;
}
const string ZAKAZNIK::registracia() const {
	return datumRegistracie;
}

//2.uloha
ZAMESTNANEC::ZAMESTNANEC(const string meno = "", const string departm = "", const int pocetLudiNaKurz = 0) {
	kurzy.resize(pocetKurzovTrenera);
	vlozMeno(meno);
	vlozDepartment(departm);
	vytvorKurzy(pocetLudiNaKurz);
	pocetNaKurz = pocetLudiNaKurz;
}
void ZAMESTNANEC::vlozMeno(const string meno) {
	menoPriezvisko = meno;
}
void ZAMESTNANEC::vlozDepartment(const string dep) {
	department = dep;
}
void ZAMESTNANEC::vytvorKurzy(const int pocet) {
	for (auto i = kurzy.begin(); i != kurzy.end(); i++) {
		for (int j = 0; j < pocet; j++) {
			ZAKAZNIK clovek;
			i->push_back(clovek);
		}
	}
}
void ZAMESTNANEC::prijmiZakaznika(const string meno, const string registracia, const string predplatenie) { //prerobyt tak, aby vstupom bol objekt typu ZAKAZNIK
	bool vlozil = false;
	for (auto i = kurzy.begin(); i != kurzy.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			if (j->meno() == "") {
				j->vlozMeno(meno);
				j->vlozDatumReg(registracia);
				j->vlozPlatnostOd(predplatenie);
				vlozil = true;
				break;
			}
		}
		if (vlozil) {
				break;
		}
	}
}
const string ZAMESTNANEC::getMeno() const {
	return menoPriezvisko;
}
const string ZAMESTNANEC::getDepartment() const {
	return department;
}
const int ZAMESTNANEC::getVolneMiesta() const {
	unsigned int pocet = 0;
	for (auto i = kurzy.begin(); i != kurzy.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			if (j->meno() == "") {
				pocet++;
			}
		}
	}
	return pocet;
}
vector<vector<ZAKAZNIK>> ZAMESTNANEC::getKurzy() {
	return kurzy;
}

//3.cvicenie
KURZ::KURZ(const int pocet) {

}
KURZ::~KURZ() {

}
bool KURZ::pridajTrenera(const string meno, const string typ, const int pocetLudiNaKurz) {
	return DUMMY_BOOL;
}
bool KURZ::zrusTrenera() {
	return DUMMY_BOOL;
}
void KURZ::setPocetVolnychMiest() {

}
void KURZ::prihlasNaKurz(const string meno) {

}
const string KURZ::getTrener() {
	return DUMMY_STRING;
}
const string KURZ::getPocetVolnychMiest() {
	return DUMMY_STRING;
}
void KURZ::nastavTypKurzu(const char *typ) {

}
const char *KURZ::getTypKurzu() const {
	return nullptr;
}

//4.uloha
FITNESSCENTRUM::FITNESSCENTRUM(const int pocet) {

}
void FITNESSCENTRUM::pridajTreneraDoKurzu(const string meno, const string typ) {

}
void FITNESSCENTRUM::prihlasNaKurz(const string meno, const string typKurzu, const string datum) {

}
void FITNESSCENTRUM::odhlasZKurzu(const string meno, const string typKurzu, const string datum) {

}
int FITNESSCENTRUM::getPocetVsetkychKurzov() const {
	return DUMMY_INT;
}
int FITNESSCENTRUM::getPocetVolnychMiestKurzu(const char *typ) const {
	return DUMMY_INT;
}
//5.uloha
int FITNESSCENTRUM::getPocetDniDoKoncaPlatnosti(const string meno, const string typ, const string datum) {
	return DUMMY_INT;
}




/*
//pomocna fcia
string zmenZaMedzeru(string cas) {
	int lenth = cas.size();
	for (unsigned int i = 0; i < lenth; i++) {
		if (cas[i] == ':') {
			cas[i] = ' ';
		}
	}
	return cas;
}
int indexDna(const int rok, const int mesiac, const int den) {
	int posun = 0;
	int index = den;
	if (mesiac > 2) {
		if (rok % 4 == 0) { posun = -1; }
		else { posun = -2; }
	}
	index += (mesiac - 1) * 30 + (mesiac / 2) + posun;
	return index;
}
double prepocetNaHodiny(double hod, double min, double sec) {
	return (hod + min / 60 + sec / 3600);
}

//1.uloha
AUTO::AUTO(const char *spzAuta, const char *casPrijazdu) {
	vlozSpz(spzAuta);
	vlozCas(casPrijazdu);
}
void AUTO::vlozSpz(const char *spz) {
	if (spz == nullptr) {
		spzAuta = nullptr;
	}
	else {
		char *vysl = new char[strlen(spz)+1];
		for (unsigned int i = 0; i < strlen(spz); i++) {
			vysl[i] = spz[i];
			vysl[i + 1] = '\0';
		}
		spzAuta = vysl;
	}
}
void AUTO::vlozCas(const char *cas) {
	if (cas == nullptr) {
		casPrijazdu = nullptr;
	}
	else {
		char *vysl = new char[strlen(cas)+1];
		for (unsigned int i = 0; i < strlen(cas); i++) {
			vysl[i] = cas[i];
			vysl[i + 1] = '\0';
		}
		casPrijazdu = vysl;
	}
}
const char *AUTO::cas() const {
	if (casPrijazdu == nullptr) {
		return "nezadane";
	}
	return casPrijazdu;
}
const char *AUTO::spz() const {
	if (spzAuta == nullptr) {
		return "nezadane";
	}
	return spzAuta;
}


PARKOVACIE_MIESTO::PARKOVACIE_MIESTO() : car(nullptr, nullptr) {
	obsadenost = false;
	typ = Vsetci;
}
PARKOVACIE_MIESTO::~PARKOVACIE_MIESTO() {
}
bool PARKOVACIE_MIESTO::zaparkujAuto(const char *spz, const char *cas) {
	car.vlozSpz(spz);
	car.vlozCas(cas);
	auto m = car.spz();
	if (!obsadenost && m != "nezadane") {
		obsadenost = true;
		return true;
	}
	return false;
}
const char *PARKOVACIE_MIESTO::spzAuta() const {
	if (car.spz() != "nezadane") {
		return car.spz();
	}
	return "";
}
const char *PARKOVACIE_MIESTO::casPrijazdu() const {
	if (car.cas() != "nezadane") {
		return car.cas();
	}
	return "";
}
bool PARKOVACIE_MIESTO::vyparkujAuto() {
	if (obsadenost) {
		car.vlozSpz(nullptr);
		car.vlozCas(nullptr);
		obsadenost = false;
		return true;
	}
	return false;
}
//2.uloha
const char *PARKOVACIE_MIESTO::getTypMiesta() const {
	if (typ == Vozickar) {
		return "Vozickar";
	}
	return "Vsetci";
}
void PARKOVACIE_MIESTO::nastavTypMiesta(const char *typMiesta) {
	if (typMiesta == "Vozickar") {
		typ = Vozickar;
	}
	else {
		typ = Vsetci;
	}
}
//3.uloha
PARKOVISKO::PARKOVISKO(int poschodia, int sirka, int dlzka) {
	if (poschodia < 1 || sirka < 1 || dlzka < 1) {
		pocetPoschodi = 0;
		pocetMiestNaPoschodi = 0;
	}
	else {
		pocetPoschodi = poschodia;
		pocetMiestNaPoschodi = sirka*dlzka;
		miesta = new PARKOVACIE_MIESTO*[poschodia];
		for (unsigned int i = 0; i < poschodia; i++) {
			miesta[i] = new PARKOVACIE_MIESTO[pocetMiestNaPoschodi];
		}
		for (unsigned int i = 0; i < poschodia; i++) {
			for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
				if (j < sirka) {
					miesta[i][j].nastavTypMiesta("Vozickar");
				}
			}
		}
	}
}
PARKOVISKO::~PARKOVISKO() {
	if (miesta == nullptr) {
		for (unsigned int i = 0; i < pocetPoschodi; i++) {
			delete[] miesta[i];
		}
		delete[] miesta;
	}
}
int PARKOVISKO::pocetVsetkychMiest() const {
	return pocetPoschodi * pocetMiestNaPoschodi;
}
int PARKOVISKO::pocetMiest(const char *typ) const {
	int pocet = 0;
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			if (miesta[i][j].getTypMiesta() == typ) {
				pocet++;
			}
		}
	}
	return pocet;
}
int PARKOVISKO::pocetVolnychMiest(const char *typ) const {
	int pocet = 0;
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			if (miesta[i][j].getTypMiesta() == typ && !miesta[i][j].getObsadeneMiesto()) {
				pocet++;
			}
		}
	}
	return pocet;
}
//4.uloha

bool PARKOVISKO::zparkujAuto(const char *spz, const char *cas, const char *typ) {
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			string tmp = { typ };
			if (miesta[i][j].getTypMiesta() == tmp && !miesta[i][j].getObsadeneMiesto()) {
				miesta[i][j].zaparkujAuto(spz, cas);
				return true;
			}
		}
	}
	
	return false;
}
char *PARKOVISKO::zoznamAut(char *spz) const {
	if (spz == nullptr) {
		return "";
	}
	spz[0] = '\0';
	int pocetObsadenych = 0, zaznacene = 0;
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			if (miesta[i][j].getObsadeneMiesto()) {
				pocetObsadenych++;
			}
		}
	}
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			if (miesta[i][j].getObsadeneMiesto()) {
				if (zaznacene == pocetObsadenych-1) {
					strcat(spz, miesta[i][j].spzAuta());
				}
				else {
					strcat(spz, miesta[i][j].spzAuta());
					strcat(spz, ", ");
					zaznacene++;
				}
			}
		}
	}
	return spz;
}
int PARKOVISKO::zaplat(const char *casVjazdu, const char *casVyjazdu){
	string in = zmenZaMedzeru(casVjazdu);
	string out = zmenZaMedzeru(casVyjazdu);
	stringstream vjazd(in);
	stringstream vyjazd(out);
	int rok, mesiac, den, hodina, minuta, sekunda;
	int r, m, d, h, min, s;
	int hodinyNavyse = 0;
	if (vjazd >> rok >> mesiac >> den >> hodina >> minuta >> sekunda && vyjazd >> r >> m >> d >> h >> min >> s) {
		int indexDnaVjazdu = indexDna(rok, mesiac, den);
		double casVjazduVHodinach = prepocetNaHodiny(hodina, minuta, sekunda);
		int indexDnaVyjazdu = indexDna(r, m, d);
		double casVyjazduVHodinach = prepocetNaHodiny(h, min, s);
		double casDoKoncaDna = 24 - casVjazduVHodinach;
		int rozdielPoctuDni = (indexDnaVyjazdu + ((r - rok) * indexDna(rok, 12, 31)) - indexDnaVjazdu);
		if (rozdielPoctuDni > 0) {
			hodinyNavyse = (rozdielPoctuDni - 1) * 24 + casVyjazduVHodinach + casDoKoncaDna - 2;
		}
		else if ((casVyjazduVHodinach - casVjazduVHodinach) >= 3){
			hodinyNavyse = rozdielPoctuDni * 24 + (casVyjazduVHodinach - casVjazduVHodinach) - 2;
		}
		return hodinyNavyse*3;
	}
	
	return 0;
}
int PARKOVISKO::vyparkujAuto(const char *spz, const char *cas) {
	int doplat = 0;
	for (unsigned int i = 0; i < pocetPoschodi; i++) {
		for (unsigned int j = 0; j < pocetMiestNaPoschodi; j++) {
			string tmp = { miesta[i][j].spzAuta() };
			if (tmp == spz) {
				doplat = zaplat(miesta[i][j].casPrijazdu(), cas);
				miesta[i][j].vyparkujAuto();
				return doplat;
			}
		}
	}
	return DUMMY_INT;
}
//5.uloha
bool PARKOVISKO::nacitajZoSuboru(const string &nazov) {
	ifstream inFile;
	string line;
	string spz, cas, typ;
	inFile.open(nazov);
	if (!inFile) {
		cout << "Nenasiel File" << endl;
		return false;
	}
	while (getline(inFile, line)) {
		if (line != "") {
			stringstream car(line);
			if (car >> spz >> cas >> typ) {
				zparkujAuto(spz.c_str(), cas.c_str(), typ.c_str());
			}
		}
	}
	inFile.close();
	return true;
}
*/
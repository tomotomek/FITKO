# FITKO
zakaznik:
--
meno, priezvisko

datum registracie

permanentka (datum zaciatku platnosti)

insert(menoPriezvisko)

insert(datumRegistracie)

insert(zaciatokPermanentky)

return menoPriezvisko

return datumRegistracie

return zaciatokPermanentky

trener:
--
meno, priezvisko

department (aky kurz vedie)

maximalny pocet ludi na kurz

pole, ktore obsahuje pocet kurzov, daneho trenera (2)
 
return volne miesta- pole bude obsahovat dve polia. Kazde pole bude mat maximalny pocet 
ludi objektov typu Zakaznik, ak nema meno, tak je to volne miesto

insert(menoPriezvisko)

insert(department)

insert(pocetLudiNaKurz)

return menoPriezvisko

return department

return pole

make() vytvori pole do dvojprvkoveho pola pocetLudiNaKurz objektov typu zakaznik - konstruktor

prijmiZakaznika(0/1) zada udaje o zakaznikovy do pola podla zvoleneho indexu

kurz:
--
typ kurzu

trener

pocetVolnychMiest

insert(trener)

insert(nazovKurzu)

insert(pocetVolnychMiest) - zisti obsadenost kurzu "prebehne polami trenera, a vrati pocet 
miest bez mena" a prida do clenskej premennej pocetVolnychMiest

prihlasNaKurz(menoPriezvisko, cisloKurzu) - trener.prijmiZakaznika(menoPriezvisko, cisloKurzu(0/1)) 

return pocetVolnychMiest

return typKurzu

return trener

fitko:
--
pocet kurzov

pole v pocte kruzov, kazdy prvok je objekt typu kurz

vytvori do pola pocet kurzov objektov kurz a nastavi typKruzu - konstruktor

pridajTreneraDoKurzu(menoPriezvisko, typKurzu) prejde polom kurzov, danemu typu kurzu 
prideli trenera

fitko.prihlasNaKurz(menoPriezvisko, typKurzu, datum) v poli kurzov najde typ kurzu, zisti, ci je volne miesto v kurze pocetVolnychMiest(), ak ano, kurz.prihlasNaKurz(menoPriezvisko, datum) 

odhlasZKurzu(menoPriezvisko, typKurzu, datum) prejde polom kurzov, najde dany typ kurzu. V 
kurze.trener najde menoPriezvisko. Ak datum > datumZaciatkuPlatnosti + 31, vyprazdni 
informacie o uzivatelovi 

return pocetDniDoKoncaPlatnosti(menoPriezvisko, typKurzu, datum) - prejde kurzami, najde 
typ. V kurze.trener najde menoPriezvisko a vrati hodnotu datum - datumZaciatkuPlatnosti

najdenie cloveka(menoPriezvisko, typKurzu):

for kurz in poleKurzov:

	if kurz.typKurzu == typKurzu

		for den in kurz.trener.pole

			for clovek in den

				if clovek.menoPriezvisko == menoPriezvisko

					...


#include <cassert>
#include <iostream>
#include <vector>
// TODO: doplťe co potřebujete

void print (std::vector<int> a){
    std::cout<<"[";
    for(std::size_t i=0; i< a.size(); i++){
        if((a.size()-i )== 1){
          std::cout<< a[i];   
        }
        else{
        std::cout<< a[i]; 
        std::cout<< "," ;  
        }
    }
    std::cout<<"]"<<std::endl;
}

int main(){
std::vector <int> pole={1,2,3};
print(pole);
//std::cout<<power_digit_sum(1234)<<std::endl;
//std::cout<<"biggest(-10, 10)"<<std::endl;
//std::cout<<biggest(-10, 10)<<std::endl;
//std::cout<<pocet_p_d(2023)<<std::endl;
}


// Implementujte funkci ‹power_digit_sum›, která vrátí „speciální“
// ciferný součet čísla ‹number›, který se od běžného ciferného
// součtu liší tím, že každou cifru před přičtením umocníme na číslo
// její pozice. Pozice číslujeme zleva, přičemž první má číslo 1.
// Vstupem funkce ‹power_digit_sum› bude libovolné nezáporné celé
// číslo, na výstupu se očekává celé číslo. Výpočet budeme provádět
// v číselné soustavě se základem 7.
//// Příklad: Číslo ⟦1234⟧ zapíšeme v sedmičkové soustavě jako
// ⟦(3412)₇⟧ – skutečně, ⟦3⋅7³ + 4⋅7² + 1⋅7¹ + 2⋅7⁰ = 1029 + 196 + 7
// + 2 = 1234⟧.  Proto ‹power_digit_sum(1234)› získáme jako ⟦3¹ + 4²
// + 1³ + 2⁴ = 36⟧.
int power_digit_sum(int number) {
    int soucet = 0;
    int position = 1; // Pozici začneme od 1 (první cifra zleva má pozici 1).
    int delka;
    int number_z= number;
    // Projdeme všechny cifry v sedmičkové soustavě, dokud je číslo větší než 0.
    while (number_z > 0) {
        number_z /= 7; 
        delka++;
    }
    std::vector<int> zbytky(delka, 0);
    while (number > 0) {
        zbytky[delka-position] = number % 7;
        number /= 7; 
        position++;
    }
    for (int i = 0; i < delka; i++) {
        std::cout << "zbytek[" << i << "] = " << zbytky[i] << std::endl;
    }
    ////////////////////////////
    int opak=1;
    for(int i=0; i < delka; i++){
            int cast=1;
            for(int f=0; f<opak; f++){
                cast = (cast * zbytky[i]);
            }
            std::cout<<"cast"<<std::endl;
            std::cout<<cast<<std::endl;
            soucet = (soucet+ cast);   
            opak++;
    } 
    return soucet;
}


// Napište funkci, která najde celé číslo ‹x›, které leží mezi
// hodnotami ‹low› a ‹high› (včetně), a pro které vrátí funkce ‹poly›
// maximální hodnotu (tzn. libovolné ⟦x⟧ takové, že pro všechny ⟦x'⟧
// platí ⟦f(x) ≥ f(x')⟧, kde ⟦f⟧ je funkce, kterou počítá podprogram
// ‹poly›).
int poly(int x) {
    return (10 + (30 * x) - (15 * x * x * x) + (x * x * x * x * x));
}
///////////////úúúúúúúúúúúúúúúúúú
int biggest(int low, int high){
    int hodnota=low;
    int minuly;
for(int i=low; i<= high ; i++){
    int vysledek= poly(hodnota);
    hodnota=(hodnota+1);
    if(i == 0){
        minuly=vysledek;
    }
    if((vysledek > minuly)&&(i >= 1)){
        minuly=vysledek;
    }
}
return minuly;
}



// Napište funkci, která zjistí, kolik bude pracovních dnů v roce
// ‹year›. Dny v týdnu mají hodnoty 0–6 počínaje pondělím s hodnotou 0.
// Předpokládejte, že ‹year› je větší než 1600.
// České státní svátky jsou:
//
// │  datum │ svátek                                         │
// ├┄┄┄┄┄┄┄▻┼◅┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄│
// │   1.1. │ Den obnovy samostatného českého státu          │
// │      — │ Velký pátek                                    │
// │      — │ Velikonoční pondělí                            │
// │   1.5. │ Svátek práce                                   │
// │   8.5. │ Den vítězství                                  │
// │   5.7. │ Den slovanských věrozvěstů Cyrila a Metoděje   │
// │   6.7. │ Den upálení mistra Jana Husa                   │
// │  28.9. │ Den české státnosti                            │
// │ 28.10. │ Den vzniku samostatného československého státu │
// │ 17.11. │ Den boje za svobodu a demokracii               │
// │ 24.12. │ Štědrý den                                     │
// │ 25.12. │ 1. svátek vánoční                              │
// │ 26.12. │ 2. svátek vánoční                              │
// Přestupné roky: v některých letech se na konec února přidává 29.
// den. Jsou to roky, které jsou dělitelné čtyřmi, s výjimkou těch,
// které jsou zároveň dělitelné 100 a nedělitelné 400.
// Čistou funkci ‹first_day› můžete použít k tomu, abyste zjistili,
// na který den v týdnu padne 1. leden daného roku. Např.
// ‹first_day(2001)› vrátí nulu, protože rok 2001 začínal pondělím.

int first_day(int year) {
    assert(year >= 1601);
    int years = year - 1601;
    int offset = years + years / 4 - years / 100 + years / 400;
    return offset % 7;
}

int pocet_p_d(int year){
    int zacatek = first_day(year);
    int pocet_dni= 365;
    if((year%4==0)){
        pocet_dni++;
    }
    if((year%100==0)&&(year%400 >0)){
        pocet_dni--;
    }
    int Den_obnovy= 0;
    int Svatek_prace= 124;
    int Den_vitezstvi= 127;
    int Den_slovanskych= 185;
    int Den_upaleni= 186;
    int Den_ceske= 270;
    int Den_vzniku=300;
    int Den_boje= 320;
    int Stedry_den= 357;
    int SV1= 358;
    int SV2= 359;
    int vysledek= (pocet_dni - 2);
    if(pocet_dni==366){
        Svatek_prace++;
        Den_vitezstvi++;
        Den_slovanskych++;
        Den_upaleni++;
        Den_ceske++;
        Den_vzniku++;
        Den_boje++;
        Stedry_den++;
        SV1++;
        SV2++;
    }
    int oo= zacatek;
    for(int den=0; den < pocet_dni; den++){
        
        if ((oo == 5 || oo == 6) || (den == Den_obnovy || den == Svatek_prace || den == Den_vitezstvi || 
            den == Den_slovanskych || den == Den_upaleni || den == Den_ceske || 
            den == Den_vzniku || den == Den_boje || den == Stedry_den || 
            den == SV1 || den == SV2)) {
            vysledek--;
            
        }
        if(oo==6){
            oo=0;
        }
        else{
          oo++;  
        }
    }
    return vysledek;
    
}

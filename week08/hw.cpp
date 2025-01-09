#include <iostream>
#include <vector>

void print_b(std::vector<bool> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}
void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}
void print2DVector(const std::vector<std::vector<int>>& vec) {
    std::cout << std::endl;
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}
/*
////////////////////////////moje///////////////////////
std::vector<int> serad_vzestupne(std::vector<int> a) {
    std::vector<int> vysledek;
    std::vector<int> mez= a;
    int nejmensi;
    int c;
    for(std::size_t b= 0; b< a.size(); b++){
        for(std::size_t i= 0; i< mez.size(); i++){
                if(nejmensi > mez[i]){
                    nejmensi= mez[i];
                    c= i;
                }
        }
        vysledek.push_back(nejmensi);
        int o = mez.size();
        for(int i= 0; i< o; i++){

            if(mez[i]== mez[c]){

            }
            else{
            mez[i]= (mez[i]);
            }
        }
    }
    return vysledek;
}*/
////////////////////////////moje///////////////////////

/*
 * Napište funkci merge, která vezme dvě vzestupně seřazená pole a spojí je do jednoho
 * vzestupně seřazeného seznamu
 * */
std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> vysledek;
    std::size_t aa = 0;
    std::size_t bb = 0;
    while((a.size()>aa) && (b.size()>bb)){
        if(a[aa]>= b[bb]){
            vysledek.push_back(b[bb]);
            bb++;
        }
        if(a[aa]< b[bb]){
            vysledek.push_back(a[aa]);
            aa++;
        }/*
        if(a[aa]== b[bb]){
            vysledek.push_back(a[aa]);
            aa++;
        }*/
        if(aa==a.size()){
            int zbytek= (b.size() - bb);
            for(int i= 0; i < zbytek; i++){
                vysledek.push_back(b[b.size()-(zbytek-i)]);
            }
        }
        if(bb==b.size()){
            int zbytek= (a.size() - aa);
            for(int i= 0; i < zbytek; i++){
                vysledek.push_back(a[a.size()-(zbytek-i)]);
            }
        }
        
    }
    return vysledek;
}


/* Napište funkci histogram, která dostane pole čísel z rozsahu [0-100), a vrátí nové pole takové, že
 * na i-té pozici nového seznamu bude uložen počet výskytů čísla i ve vstupním poli.
 *//*
std::vector<int> histogram(std::vector<int> data) {
    std::vector<int> vysledek;
    for(int i= 0; i< 100; i++){
        int pocet= 0;
        for(std::size_t a= 0; a< data.size(); a++){
            if(i == data[a]){
                pocet++;
            }
        } 
      vysledek.push_back(pocet);  
    }
    return vysledek;
}

*/

std::vector<int> histogram(std::vector<int> data) {
    std::vector<int> vysledek;
    vysledek.resize(100);
    for(std::size_t a= 0; a< data.size(); a++){
        int hodnota= data[a];
        vysledek[(hodnota)]++;
    } 
    return vysledek;
}

// Napište (čistou) funkci, která simuluje jeden krok výpočtu
// jednorozměrného buněčného automatu (cellular automaton). My se
// omezíme na «binární» (buňky nabývají hodnot 0 a 1) «jednorozměrný»
// automat s «konečným stavem»: stav takového automatu je seznam
// jedniček a nul, například:
//
//   ┌───┬───┬───┬───┬───┬───┬───┐
//   │ 0 │ 1 │ 1 │ 1 │ 0 │ 0 │ 1 │
//   └───┴───┴───┴───┴───┴───┴───┘
//
// Protože obecný automat tohoto typu je stále relativně složitý,
// budeme implementovat automat s fixní sadou pravidel:
//
// │‹old[i - 1]›│‹old[i]›│‹old[i + 1]›│‹new[i]›│
// ├┄┄┄┄┄┄┄┄┄┄┄┄┼┄┄┄┄┄┄┄┄┼┄┄┄┄┄┄┄┄┄┄┄┄│┄┄┄┄┄┄┄┄│
// │     0      │    0   │      1     │    1   │
// │     1      │    0   │      0     │    1   │
// │     1      │    0   │      1     │    1   │
// │     1      │    1   │      0     │    0   │
// │     1      │    1   │      1     │    0   │
//
// Pravidla určují, jakou hodnotu bude mít buňka v následujícím
// stavu, v závislosti na několika okolních buňkách stavu nynějšího
// (konkrétní indexy viz tabulka). Neexistuje-li pro danou vstupní
// kombinaci pravidlo, do nového stavu přepíšeme stávající hodnotu
// buňky. Na krajích stavu interpretujeme chybějící políčko vždy
// jako nulu.
//
// Výpočet s touto sadou pravidel tedy funguje takto:
//
//   ┌───┬───┬───┬───┬───┬───┐ 001 → 1 ┌───┬───┬───┬───┬───┬───┐
//   │░0░│░1░│ 1 │ 0 │ 0 │ 1 │────────▶│░1 │   │   │   │   │   │
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//   ┌───┬───┬───┬───┬───┬───┐ 011 → ? ┌───┬───┬───┬───┬───┬───┐
//   │░0░│░1░│░1░│ 0 │ 0 │ 1 │────────▶│ 1 │░1 │   │   │   │   │
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//   ┌───┬───┬───┬───┬───┬───┐ 110 → 0 ┌───┬───┬───┬───┬───┬───┐
//   │ 0 │░1░│░1░│░0░│ 0 │ 1 │────────▶│ 1 │ 1 │░0░│   │   │   │
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//   ┌───┬───┬───┬───┬───┬───┐ 100 → 1 ┌───┬───┬───┬───┬───┬───┐
//   │ 0 │ 1 │░1░│░0░│░0░│ 1 │────────▶│ 1 │ 1 │ 0 │░1░│   │   │
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//   ┌───┬───┬───┬───┬───┬───┐ 001 → 1 ┌───┬───┬───┬───┬───┬───┐
//   │ 0 │ 1 │ 1 │░0░│░0░│░1░│────────▶│ 1 │ 1 │ 0 │ 1 │░1░│   │
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//   ┌───┬───┬───┬───┬───┬───┐ 010 → ? ┌───┬───┬───┬───┬───┬───┐
//   │ 0 │ 1 │ 1 │ 0 │░0░│░1░│────────▶│ 1 │ 1 │ 0 │ 1 │ 1 │░1░│
//   └───┴───┴───┴───┴───┴───┘         └───┴───┴───┴───┴───┴───┘
//
// Na vstupu dostanete stav (konfiguraci) ‹state›, výstupem funkce je
// nový seznam, který obsahuje stav vzniklý aplikací výše uvedených
// pravidel na ‹state›.

std::vector<bool> cellular_step(std::vector<bool> input) {
    std::vector<bool> mez;
    std::vector<bool> vysledek;
    mez.push_back(0);
    mez= input;
    mez.push_back(0);
    for(std::size_t i=1 ; i <= input.size(); i++){
        bool minuly= mez[(i-1)];
        bool soucastny= mez[(i)];
        bool budouci= mez[(i+1)];
        bool novy;
        if(minuly==0 && soucastny== 0 && budouci==1){
            novy=1;
        }
        else if(minuly==1 && soucastny== 1 && budouci==0){
            novy=0;
        }
        else if(minuly==1 && soucastny== 0 && budouci==0){
            novy=1;
        }
        else{
            novy= mez[i];
        }
        vysledek.push_back(novy); 
    }
    return vysledek;
}




//////////////////////////////////////////////////ú
std::vector<int> vetsi_nez(std::vector<int> data, int min) {
    std::vector<int> vysledek;
    for(std::size_t i= 0; i < data.size(); i++){
        if(data[i] > min){
            vysledek.push_back(data[i]);
        }
    }
    return vysledek;
}


//////////////////////
std::vector<int> serad(std::vector<int> data, int min) {
    std::vector<int> vysledek;
    for(std::size_t i= 0; i< data.size(); i++){
        if(data[i] < min){
            vysledek.push_back(data[i]);
        }
    }
    vysledek.push_back(min);
    for(std::size_t i= 0; i< data.size(); i++){
        if(data[i] > min){
            vysledek.push_back(data[i]);
        }
    }
    
    return vysledek;
}




std::vector<int> serad2(std::vector<int> data, int min) {
    for(std::size_t s= 0; s< (data.size()); s++){
        for(std::size_t i= 0; i< (data.size()-1); i++){
            if(data[i] > data[i+1]){
                int a= data[i];
                int b= data[i+1];
                data[i]= b;
                data[i+1]= a;
            }
        }
    }
    for(std::size_t n= 0; n < (data.size()); n++){
        if(data[n] >= min){
            int last= min;
            data.resize(data.size()+ 1);
            for(std::size_t i= (n) ; i <= (data.size()+1); i++){
                int last_2= data[i];
                data[i]= last;
                last= last_2;
            }
            return data;
        }
    }
    return data;
}
/*

*///bez pushback a bez noveveho vektoru


///////////////////////////

bool nevim_nevim(std::vector<int> data) {
    for(std::size_t i=0; i < (data.size() /2); i++){
        if((data[i]) != ((data[data.size() - i-1]))){
            return false;
        }
    }
   return true; 
}///////////////////////////////////////////////////
std::vector<int> sum(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {1, 2, 0}
    std::vector<int> vysledek;
    for(std::size_t i= 0; i< vec.size(); i++){
        int soucet=0;
        for(std::size_t o= 0; o< vec[i].size(); o++){
            soucet += vec[i][o];
        }
        vysledek.push_back(soucet);
    }
    return vysledek;

}

std::vector<int> product(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 2, 1}
    std::vector<int> vysledek;
    for(std::size_t i=0; i<vec.size(); i++){
        int nasobek=1;
        for(std::size_t o= 0; o< vec[i].size() ;o++){
            nasobek *= vec[i][o];
        }
        vysledek.push_back(nasobek);
    }
    return vysledek;
}
 
std::vector<int> concat(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 1, 2}
    std::vector<int> vysledek;
    for(std::size_t i= 0; i< vec.size(); i++){
        for(std::size_t o = 0; o< vec[i].size(); o++){
            vysledek.push_back(vec[i][o]);
        }
    }
    return vysledek;
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> vec) {
    // {
    //   {0, 1, 2},
    //   {3, 4, 5},
    //   {6, 7, 8},
    // } -> {
    //   {0, 3, 6},
    //   {1, 4, 7},
    //   {2, 5, 8},
    // }
    std::vector<std::vector<int>> vysledek;
    vysledek.resize(vec.size()); // Nastav počet řádků
    for (auto& row : vysledek) {
        row.resize(vec[0].size()); // Nastav počet sloupců pro každý řádek
    }
    for(std::size_t i=0 ; i< vec.size(); i++){
        for(std::size_t o=0 ; o< vec[i].size(); o++){
            vysledek[o][i] = vec[i][o];
        }
    }
    return vysledek;
}

std::vector<std::vector<int>> cartesian_product(std::vector<int> a, std::vector<int> b) {
    // {0, 1} {2, 4} -> {{0, 2}, {0, 4}, {1, 2}, {1, 4}}
    // {0, 1} {} -> {} 
    std::vector<std::vector<int>> vysledek;
    for(std::size_t i=0; i< a.size(); i++){
        for(std::size_t o=0; o< b.size(); o++){
            vysledek.push_back({a[i],b[o]});
        }
    }
    return vysledek;
}

std::vector<std::vector<int>> sum_2(std::vector<std::vector<int>> vec_1, std::vector<std::vector<int>> vec_2) {
    std::vector<std::vector<int>> vysledek;
    for(std::size_t i=0; (i< vec_1.size()) || (i< vec_2.size()) ; i++){
        std::vector<int> mezi;
        if(vec_1[i].size() > vec_2[i].size()){
           for(std::size_t o=0;(o< vec_2[i].size()) ; o++){
                mezi.push_back((vec_1[i][o]) + (vec_2[i][o]));  
            }
           for(std::size_t p= vec_2[i].size();(p< vec_1[i].size()) ; p++){
                    mezi.push_back(vec_1[i][p]);
            }
            vysledek.push_back({mezi}); 
        }else{
            for(std::size_t o=0;(o< vec_1[i].size()) ; o++){
                mezi.push_back((vec_1[i][o]) + (vec_2[i][o]));
           }
           for(std::size_t p= vec_1[i].size(); (p< vec_2[i].size()) ; p++){
                mezi.push_back(vec_2[i][p]);
            }
            vysledek.push_back({mezi});
        }
    }
    return vysledek;
}
std::vector<std::vector<int>> split(std::vector<int> r, int n) {
    std::vector<std::vector<int>> vysledek;  
    int x= r.size()%n;
    std::size_t w= 0;
    for(std::size_t i= 0; i < (((r.size()-x)/n)+1) ; i++){
        std::vector<int> mezi;
        for(int o= 0; o < n ; o++){
            if(w >= r.size()){
                vysledek.push_back({mezi});
                return vysledek;
            }
            mezi.push_back(r[w]);
            w++;
        }
        vysledek.push_back({mezi});
    }
    return vysledek;
}

int main() {
    std::vector<std::vector<int>> vec8 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> vec9 = {
        {5, 1},
        {2},
        {3}
    };
    std::vector<bool> jednicky = { 0, 1, 1, 0, 0, 1};
    std::vector<int> zkouzka = {9,7};
    std::vector<int> vec7 = {0,1};
    std::vector<int> vec6 = {2,4};
    std::vector<int> ehm = { 1, 9, 4, 8, 2, 3, 5, 6, 7, 11, 2, 3, 9 };
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 6 };//////////////
    std::vector<int> asc1 = { 0, 2, 4, 7, 8,  20};
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9, 11, 12 };
    std::vector<int> vec2 = { 43, 93, 76, 49, 11,  7, 70, 20, 43, 36,
                              73, 47, 77, 48, 91, 46, 31, 78, 63, 61,
                               7, 88, 42, 62, 84, 29, 61, 28, 18, 41,
                              93, 90, 13, 27, 19, 50, 61, 73, 55, 64,
                              45, 75, 28, 64, 51, 49, 44, 64, 60, 29,
                              53, 86, 81, 50, 31, 14, 69, 92, 23, 88,
                              15, 21, 54, 33, 15, 31, 77, 43, 21, 13,
                              45, 95,  3, 13, 28, 44, 21, 27, 13, 55,
                               8, 13, 19, 95, 78, 43, 91, 89, 54, 73,
                              32, 81, 27, 94, 73, 73, 97, 70, 68, 27,
                              53, 61, 92, 24, 49, 66, 82, 55, 49, 13,
                              92, 64, 92, 88, 91, 32, 17, 71, 26, 61,
                              93, 59, 89, 87, 42, 77, 17, 60,  7, 49,
                              22, 36,  6, 51, 86, 35, 87, 37, 53, 77,
                               1,  7, 24, 93, 38, 40, 44, 75, 16,  6,
                              76, 20, 91, 89, 72, 94, 24, 95,  5, 26,
                              47, 88,  2, 40, 42, 72, 74, 33,  8,  6,
                              64,  2, 24, 64, 66,  8, 84, 68, 17, 91,
                              77, 10, 51, 84, 20, 55, 82,  4, 36, 32,
                               0, 36, 60, 98, 16, 83, 12, 72,  5, 45,
                               1, 27, 34, 67, 71, 98, 49, 46, 36, 79,
                              91, 10,  2, 34, 80, 80, 17, 98,  9, 42,
                              87, 62,  4,  3, 91, 22, 45, 60, 77, 63,
                              24, 61, 79, 27, 23, 51, 45, 20, 89, 64,
                               0, 40, 14, 81, 34, 44,  7, 25, 49, 79,
                              22, 50, 52,  2, 22, 58, 77, 62, 73, 19,
                              24, 74, 38, 32, 54, 74, 30, 27, 71, 52,
                              63, 28,  4, 64, 49, 12, 87, 41, 38, 15,
                               1, 98, 10, 67,  2, 76, 63, 48, 32, 20,
                               3, 23, 41, 14, 67, 98, 95, 66, 86, 90 };
   std::cout << "merge(asc1, asc2): ";
   print(merge(asc1, asc2));
   std::cout << std::endl;

   std::cout << "histogram(vec2): ";
   print(histogram(vec2));
   std::cout << std::endl;

    std::cout << "to posledni (jednicky):";
    print_b(cellular_step(jednicky));
    std::cout << std::endl;

   std::cout << "vetsi_nez(vec2): ";
   print(vetsi_nez(vec1, 4));
   std::cout << std::endl;
/*
   std::cout << "serad(vec1): ";
   print(serad(vec1, 5));
   std::cout << std::endl;
*/
   std::cout << "serad2(vec1): ";
   print(serad2(vec1, 5));
   std::cout << std::endl;

    std::cout << "nevimnevim ():";
    std::cout<<(nevim_nevim(zkouzka))<<std::endl;
    std::cout << std::endl;   
/*
  std::cout << "moje(ehm): ";
   print(serad_vzestupne(ehm));
   std::cout << std::endl;
*/

   std::cout << "sum(vec9): ";
   print(sum(vec9));
   std::cout << std::endl;
    

   std::cout << "product(vec9): ";
   print(product(vec9));
   std::cout << std::endl;

   std::cout << "concat(vec9): ";
   print(concat(vec9));
   std::cout << std::endl;

   std::cout << "transpoze(vec8): ";
   print2DVector(transpose(vec8));
   std::cout << std::endl; 

   std::cout << "cartesian_product(vec7): ";
   print2DVector(cartesian_product(vec7, vec6));
   std::cout << std::endl; 

   std::cout << "sum_2(?): ";
   print2DVector(sum_2(vec8, vec9));
   std::cout << std::endl; 

   std::cout << "split(?): ";
   print2DVector(split(ehm, 3));
   std::cout << std::endl; 
   }

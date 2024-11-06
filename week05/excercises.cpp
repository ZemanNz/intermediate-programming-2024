#include <iostream>
// TODO: Doplňte potřebné hlavičky

// Vypište obdélník o zadaných parametrech
// Vraťte 0 pokud vše v pořádku, -1 pokud nastala chyba
int hollow_rect(int x, int y, int thickness) {
    for(int i; i<thickness; i++){
            for(int i=0; i < x; i++){
            std::cout<<"*";
            } 
            std::cout<<" "<< std::endl;
    }
    for(int i; i < thickness; i++){
            for(int i=0;i<thickness ; i++){
            std::cout<<"*";
            } 
            for(int i=0;i< x-2*thickness ; i++){
            std::cout<<" ";
            } 
            for(int i=0;i<thickness ; i++){
            std::cout<<"*";
            } 
            std::cout<<" "<< std::endl;
    }
    for(int i; i<thickness; i++){
            for(int i=0; i < x; i++){
            std::cout<<"*";
            } 
            std::cout<<" "<< std::endl;
    }

    
    return 0;
}

// Vraťte a na n
int power(int a, int n) {
    int vysledek=1;
    for(int i=1; i<= n;i++){
        vysledek=(vysledek*a);
    }
    std::cout<<(vysledek)<< std::endl;
    return vysledek;
}

// Vraťte idx-té fibonacciho číslo
int fibonacci(int idx) {
    int a=0;
    int b=1;
    int c;
    if(idx==0){
        return a;
    } else if(idx==1){
        return b;
    } else {
    for(int i=0; i < (idx - 1); i++){
        c=(a+b);
        a=b;
        b=c;
    }
    return (c);
    }
}

int main() {
    std::cout<<hollow_rect(8, 8, 3)<< std::endl;
    std::cout<<power(3,4)<< std::endl;
    for(int x=0; x<=20;x++){
    std::cout<<fibonacci(x)<< std::endl; 
    }
}
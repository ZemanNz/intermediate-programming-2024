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

    for(int i=0; i < idx; i++){
        if(idx==0){
        return a;
        }
        else if(idx==1){
        return b;
        }
        else if(idx>1){
        c=a+b;
        a=b;
        b=c;
        return (c);
        }
    }

    /*
    i-zacatek-a=0,,,,b=1,,,,c==?,,,
    i-----1---a=1,,,,b=1,,,,c==1,,,
    i-----2---a=1,,,,b=2,,,,c==2,,,
    i-----3---a=2,,,,b=2,,,,c==3,,,
    i-----4---a=0,,,,b=1,,,,c==1,,,
    i-----5---a=0,,,,b=1,,,,c==1,,,*/
}

int main() {
   // std::cout<<hollow_rect(8, 8, 3)<< std::endl;
    //std::cout<<power(3,4)<< std::endl;
    std::cout<<fibonacci(3)<< std::endl; 
}
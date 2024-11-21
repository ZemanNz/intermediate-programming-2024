#include <iostream>
#include <vector>

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

int sum(std::vector<int> data) {
    int soucet=0;
    for(std::size_t i=0; i <= data.size() -1; i++){
        soucet = soucet + data[i];
    }

    return soucet;
}

float average(std::vector<int> data) {
    return (sum(data)+ 0.0)/data.size();
}

float median(std::vector<int> data) {
    if((data.size()) % 2 == 1){
        int pozice= (((data.size())/2));
        float a = data[pozice];
        return a;
    }
    else{
        int pozice1= ((data.size()/2)-1);
        int pozice2= ((data.size()/2));
        float media = (data[pozice1]+ data[pozice2])/2.0;
        return media;
    }
    
}

std::vector<int> range(int start, int end) {
    std::vector<int> o ;
    int rozdil=0;
    if(start<end){
        rozdil = end- start-1;
        o.push_back(start);
        int a= start;
        for(int i=0 ; i< rozdil; i++ ){
            a= a+1;
            o.push_back(a);
        }
        return o;
    }else if(start>end){
        rozdil = (start-end)-1;
        o.push_back(start);
        int a= start;
        for(int i=0 ; i< rozdil; i++ ){
            a= a-1;
            o.push_back(a);
        }
        return o;
    }
   return {}; 
}

std::vector<int> runningSum(std::vector<int> data) {
    std::vector<int> vysledek ;
    vysledek.push_back(data[0]);
    int a=0;
    for(std::size_t i=1 ; i< data.size(); i++){
        vysledek.push_back(data[i] + vysledek[a] );
        a++;  
    }
    return vysledek;
}

std::vector<int> rotateRight(std::vector<int> data, int count) {
    std::vector<int> vysledek;
    std::vector<int> mez;
    for(int i= 0; i<count; i++){
        mez.push_back(0);
    }
    for(std::size_t i= 0; i<data.size(); i++){
        mez.push_back(data[i]);
    }
    for(int i= 0; i<count; i++){
        mez[i] = mez[mez.size()-(count-i)];
    }
    mez.resize(mez.size()-count);

    
    return mez;
}

int main() {
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8,10 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7,9 };

    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(asc1) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;

    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;

    std::cout << "toposledni(vec1): ";
    print(rotateRight(asc2,2));
    std::cout << std::endl;
}

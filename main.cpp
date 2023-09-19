#include <iostream>
#include <vector>
long ludicNumbers(long*, long*, long, long, long);
long ludicNumbers(std::vector<long>&, std::vector<long>&, long, long, long);
void initializeArray(long*&, long);
int main(int argc, const char* argv[]){
    long N; //amount of elements
    std::cin >> N;
    long*a;
    long*b;
    long na;
    initializeArray(a, N);
    b = new long[N];
    na = N;
    
    std::vector<long> x(N);
    std::vector<long> y(N);
    /*
    for(long i = 1; i < N; i++){
        x[i] = i;
    }*/
    
    
    for(long i = 2; i < na && i+a[i]<na;i++){
        na = ludicNumbers(a, b, i, a[i], na);
    }
    /*
      for(long i = 2; i < na && i+x[i]<na;i++){
        na = ludicNumbers(x, y, i, x[i], na);
    }*/
    std::cout << na - 1 << '\n';

    if(a != nullptr){
        delete[]a;
    }
    if(b != nullptr){
        delete[]b;
    }

}
void initializeArray(long *&array, long N){
    array = new long[N];
    for(long i = 1; i < N; i++){
        array[i] = i;
    }
}
long ludicNumbers(long *items, long *outArr, long b, long n, long na){
    long nb = 1;

    for(long i = 1; i < na; i++){
        if(i != b && i%n == b%n){continue;}
        outArr[nb++] = items[i]; 
    }
    for(long i = 1; i < na; i++){
        items[i] = outArr[i];
    }
    return nb;
}
long ludicNumbers(std::vector<long> &vc, std::vector<long>&bc, long b, long n, long na){
    long nb = 1;

    for(long i = 1; i < na; i++){
        if(i != b && i%n == b%n){continue;}
        bc[nb++] = vc[i]; 
    }
    for(long i = 1; i < na; i++){
        vc[i] = bc[i];
    }
    return nb;
}

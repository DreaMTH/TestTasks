#include <iostream>

int findP(int);
int findP(int, int);
int main(int argc, const char* argv[]){
    int N;
    int K; 
    int P;
    std::cin >> N;
    std::cin >> K;
    P = findP(N);
    //std::cout << P;
    P = findP(4, K);
    std::cout << P;
    std::shared_ptr<int> ptr = std::make_shared<int>(N);
    std::cout << *ptr;
}

int findP(int N){
    return 0;
}

int findP(int N, int K){
    int koef = 1;
    int i;
    if (N - K > K)
      K = N - K;
    for (i = K + 1; i <= N; i++)
      koef = koef * i;
    for (i = 1; i < (N - K + 1); i++)
      koef = koef / i;
    return koef;
}

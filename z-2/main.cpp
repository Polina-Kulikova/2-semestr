#include <iostream>
int main() {
    const int N = 7;
    int mas_a [N] = {1,2,3,4,5};
    std::cout<<"То, что нужно скопировать: ";
   for (int i=0;i<N;i++)
        std::cout<<mas_a[i];
    std::cout<<std::endl;
    int mas_b[N] = {0};
    std::cout<<"До: ";
    for (int i = 0;i < N;i++)
       std::cout<<mas_b[i];
    std::cout<<std::endl;
    std::copy(std::begin(mas_a),std::end(mas_a),mas_b); //копирует машинные слова(т.е 4 или 8 байт)
    std::cout<<"После: ";
    for (int i=0;i<N;i++)
        std::cout<<mas_b[i];
    return 0;
}
/*
for(int i=0;i<N;++i)
    mas_b[i] = mas_a[i];
Таким образом, процессор копирует по 1 байту и придется выполнить N копирований
 */
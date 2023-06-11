#include "cipher.hpp"
int main()
{
    //вызываем функции из класса
    std::cout<<"Введите 5 чисел, кроме 0:"<<std::endl;
    cipher num;
    num.Encode();
    num.Decode();
    return 0;
}

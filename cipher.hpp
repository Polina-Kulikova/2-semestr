#include <iostream>
#include <fstream>
class cipher{
private:
    std::string words[30]; //массив слов
    int mas[30]; //числа Фибоначи
    int count; //счётчик
    void fibonacci() //числа Фибоначчи
    {
        mas[0] = 1;
        mas[1] = 2;
        for (int i = 2; i < 30; i++)
            mas[i] = mas[i-1] + mas[i-2];
    }
public:
    cipher()
    {
        fibonacci();
    }
    void Encode()
    {
        std::ifstream in("file.txt"); //читаем файл
        count = 0;
        if (!in)
            std::cout<<"ERROR"<<std::endl;
        std::string a;
        while (in >> a)
        {
            words[count] = a; //записываем полученные данные в массив
            count++;
        }
        in.close();
    }
    void Decode()
    {
        int kl[30]; // ключ
        for (int i = 0; i < count; i++)
        {
            std::cin>>kl[i];
        }
        std::cout<<std::endl;

        //расставляем цифры в порядке возрастания
        for (int j=0; j<count-1; j++)
        {
            for(int k=j+1; k<count; k++)
            {
                if (kl[j]>kl[k])
                {
                    std::swap(kl[k], kl[j]);
                }
            }
        }
        std::cout<<std::endl;
        //находим совпадение ключа с числами Фибоначчи и выводим слова
        for (int p = 0; p < count; p++)
            for(int l = 0; l < 30; l++)
                if (kl[p] == mas[l])
                    std::cout << words[l]<< " ";
    }
};




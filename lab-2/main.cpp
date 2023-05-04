#include <iostream>
class String
{
private:
    size_t m_size;
    char* m_str;
public:
    String(char s, size_t size):m_size(size), m_str(new char[size+1])
    {
        std::cout<<"Constructor #1"<<std::endl;
        std::fill(m_str, m_str+m_size, s);
        m_str[m_size] = 0;
    }

    String (int str, size_t size) = delete;

    String(char* str):m_size(strlen(str)), m_str(new char[m_size+1])
    {
        std::cout<<"Constructor #2"<<std::endl;
        std::copy(str, str+m_size,m_str);
        m_str[m_size]=0;
    }
    //Конструктор копирования + Делегирующий конструктор
    String (const String& other): String(other.m_str)
    {
        std::cout<<"Copy constructor"<<std::endl;
    }

    String& operator=(String temp)
    {
        std::cout<<"Copy assigment operator"<<std::endl;
        std::swap(m_size, temp.m_size);
        std::swap(m_str, temp.m_str);
        return *this;
    }
    friend std::istream& operator>>(std::istream& in, String& m_str);
    friend std::ostream& operator<<(std::ostream& out, const String& m_str);
    ~String ()
    {
        delete[] m_str;
        std::cout<<"Destructor"<<std::endl;
    }

    char& operator[](int index)
    {
        return m_str[index];
    }

    unsigned int lenght() const
    {
        return m_size;
    }
    int& at()
    {
        int index;
        std::cin>>index;
        if (index >= 0 && m_size > index)
            std::cout<<(m_str[index])<<std::endl;
        else
            std::cout<<"Error"<<std::endl;
       return index;
    }
    int find(char c)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (m_str[i] == c)
                return i;
        }
        return -1;
    }
    String& operator+= (const String& other)
    {
        char* s = new char[m_size + other.m_size];
        std::copy(m_str, m_str+m_size, s);
        std::copy(other.m_str, other.m_str + other.m_size, s+m_size);
        delete[] m_str;
        std::copy(s, s+m_size+other.m_size,m_str);
        m_size += other.m_size;
        delete[] s;
        return *this;
    }

    bool operator< ( const String& other)
    {
        return (strcmp(m_str, other.m_str)<0);
    }
    bool operator> (const String& other)
    {
        return (strcmp(m_str, other.m_str)>0);
    }
    bool operator==(const String& other)
    {
        return (strcmp(m_str, other.m_str)==0);
    }
    char* c_str() const
    {
        return m_str;
    }

};
String operator+(String& str1, String& str2)
{
    String temp = str1;
    temp += str2;
    return temp;
}
std::istream& operator>>(std::istream& in, String& s)
{
    char c;
    while (in.get(c))
    {
        if (c == '\n' || c ==' ')
            break;
        char* temp = new char[s.m_size+1];
        std::copy(s.m_str, s.m_str+s.m_size, temp);
        temp[s.m_size]=c;
        delete[] s.m_str;
        std::copy(temp, temp + s.m_size+1, s.m_str);
        s.m_size += 1;
        delete[] temp;
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const String& s)
{
    for(int i=0; i<s.m_size; i++)
        out<<s.m_str[i];
    std::cout<<std::endl;
    return out;
}


int main()
{
    String s1 ("Hello, world!");
    String s2("aoo");
    String s3("aoo");
    std::cout<<(s2 == s3)<<std::endl;
    //String s4=s3+s2;
    //std::cout<<s1.find('a')<<std::endl;
    //s1.Print();
    //s4.Print();
    //std::cout<<s1[1]<<std::endl;
    //s2[1]= 'w' ;
    //std::cin>>s2;
    //std::cout<<s2;
    //s1.at();
    //std::cout<<(s1==s3)<<std::endl;
    //std::cout<<s1.c_str()<<std::endl;
    //s2.Print();
    //std::cout<< s.lenght() <<std::endl;
    return 0;
}
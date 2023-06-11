#include <iostream>
class Complex{
private:
    double m_a;
    double m_b;
public:
    Complex (double  m_a = 0.0, double  m_b = 0.0) : m_a(m_a), m_b(m_b)
    {
        std::cout<<"Basic constructor"<<std::endl;
    }
    Complex(const Complex& z)
    {
        std::cout<<"Copy constructor"<<std::endl;
        m_a = z.m_a;
        m_b = z.m_b;
    }
    Complex& operator = (Complex z)
    {
        std::cout<<"Copy assigment operator"<<std::endl;
        std::swap(m_a,z.m_a);
        std::swap(m_b,z.m_b);
        return *this;
    }
    Complex& operator+= (const Complex& z)
    {
        (*this).m_a += z.m_a;
        (*this).m_b += z.m_b;
        return *this;
    }
    Complex& operator*= (const Complex& z)
    {
        double m = m_a;
        m_a = (m_a*z.m_a) - (m_b*z.m_b);
        m_b = (m*z.m_b) + (z.m_a*m_b);
        return *this;
    }
    //префиксный
    Complex& operator++ ()
    {
        this->m_a += 1;
        return *this;
    }
    //постфиксный
    Complex operator++(int)
    {
        Complex temp = *this;
        this->m_a +=1;
        return temp;
    }
    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);
    ~ Complex()
    {
        std::cout<<"Destructor work"<<std::endl;
    }
};
Complex operator+ (const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp += z2;
    return temp;
}
Complex operator* (const Complex& z1, const Complex& z2)
{
    Complex t = z1;
    t *= z2;
    return t;
}
std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    out<<z.m_a<<"+"<<z.m_b<<"i"<<"  ";
    return out;
}
std::istream& operator>>(std::istream& in, Complex& z)
{
    in>>z.m_a>>z.m_b;
    return in;
}
int main()
{
    Complex z1(5,4);
    Complex z2(3,2);
    std::cout<<z1<<" "<<z2<<std::endl;
    //std::cin>> z1;
    //std::cout<<std::endl;
    //std::cin>>z2;
    Complex z4 = z1 * z2;
    std::cout<<z4<<std::endl;
    Complex z3 = z1 + z2;
    std::cout<<z3<<std::endl;
    return 0;
}

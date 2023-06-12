#include <iostream>
#include <math.h>

const float PI = 3.1415926535;

class KinematicSolver
{
private:
    double m_alpha = 0; //угол поворота 1-го двигателя
    double m_beta = 0; //угол поворота 2-го двигателя
    double m_L1, m_L2;
    double m_x, m_y, m_b; //координаты точки М(x,y) и гипотенуза b
    double m_a1, m_a2, m_a3; //вспомогательные углы

    void linklengths()
    {
        std::cout<<"Введите длину звена L1: ";
        std::cin>>m_L1;
        std::cout<<std::endl;
        std::cout<<"Введите длину звена L2: ";
        std::cin>>m_L2;
        std::cout<<std::endl;
        std::cout<<"Введите координаты точки M: ";
        std::cin>>m_x >> m_y;
        std::cout<<std::endl;
    }

    void checking ()
    {
        if ((m_L1 == NULL) || (m_L2 == NULL))
            std::cout<<"length input error"<<std::endl;
        if (m_b > m_x + m_y)
            std::cout<<"a triangle cannot exist"<<std::endl;
    }

    void Solve()
    {
        m_b = sqrt(m_x*m_x + m_y*m_y);
        //std::cout<<"B: "<<m_b<<std::endl;

        m_a1 = acos((pow(m_L1,2) + pow(m_L2,2) - pow(m_b,2))/(2*m_L1*m_L2));
        //std::cout<<"a1: "<<m_a1<<std::endl;

        m_a2 =acos((pow(m_L1,2) + pow(m_b,2) -pow(m_L2,2))/(2*m_L1*m_b));
        //std::cout<<"a2: "<<m_a2<<std::endl;

        m_a3 = atan(m_y/m_x);
        //std::cout<<"a3: "<<m_a3<<std::endl;

        m_beta = 180 - (m_a1*180)/PI;
        m_alpha = (m_a2*180)/PI + (m_a3*180)/PI;
    }

public:

    void GetAngel() const
    {
        std::cout<<"alpha: "<< m_alpha<<"  beta: "<<m_beta<<std::endl;
    }

    KinematicSolver ()
    {
        linklengths();
        Solve();
        checking();
    }
};

int main()
{
    KinematicSolver a;
    a.GetAngel();
    return 0;
}
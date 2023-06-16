#include <iostream>
#include <vector>
#include <math.h>

class Figure
{

protected:
    std::string m_color; //цвет
    double m_area; //площадь
    std::vector <int> m_size; //длины сторон или радиуса
    int m_X, m_Y; //координаты центра
public:
    Figure( const std::string& color, std::vector<int>* v, int x, int y) :  m_color(color), m_size(*v), m_X(x), m_Y(y)
    {
        std::cout<<"Constructor Figure"<<std::endl;
    }
    virtual double Area()
    {
        return m_area ;
    }
    virtual ~Figure()
    {
        std::cout<<"Destructor Figure"<<std::endl;
    }
};
class Circle: public Figure
{
public:
    Circle(const std::string& color, std::vector<int>* size, int x, int y) : Figure(color, size, x,y)
    {
        std::cout<<"Constructor Circle"<<std::endl;
    }
    virtual ~Circle()
    {
        std::cout<<"Destructor Circle"<<std::endl;
    }
    double Area() override
    {
        m_area = acos(-1)*pow(m_size[0],2);
        return m_area;
    }
};
class Triangle: public Figure
{
public:
    Triangle(const std::string& color, std::vector<int>* size, int x, int y) : Figure(color, size, x,y)
    {
        std::cout<<"Constructor Triangle"<<std::endl;
    }
    virtual ~Triangle()
    {
        std::cout<<"Destructor Triangle"<<std::endl;
    }
    //Площадь по формуле Герона
    double Area() override
    {
        double p = (m_size[0]+m_size[1]+m_size[2])/2;
        m_area = sqrt(p*(p-m_size[0])*(p-m_size[1])*(p-m_size[2]));
        return m_area;
    }
};
class Rectangle: public Figure
{
public:
    Rectangle(const std::string& color, std::vector<int>* size, int x, int y) : Figure(color, size, x,y)
    {
        std::cout<<"Constructor Rectangle"<<std::endl;
    }
    virtual ~Rectangle()
    {
        std::cout<<"Destructor Rectangle"<<std::endl;
    }
    double Area() override
    {
        m_area = m_size[0]*m_size[1];
        return m_area;
    }
};
int main()
{
    std::vector <int> v ={3, 4, 5};
    Triangle f("Green", &v,12,13);
    std::cout<<f.Area()<<std::endl;
    std::vector <int> k ={3};
    Circle c("Blue", &k, 5, 4);
    std::cout<<c.Area()<<std::endl;
    return 0;
}

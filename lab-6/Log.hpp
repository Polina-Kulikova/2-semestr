#include <iostream>
#include <fstream>
#include <chrono>

//Различные уровни ведения журнала
enum class LogLevel
{
    DEBUG,
    RELEASE
};

class Log
{
private:
    static std::ofstream m_out;
    static LogLevel m_logLevel; //Уровень журнала
public:
    static void SetLogLevel(LogLevel logLevel)
    {
        m_logLevel = logLevel;
    }
    static void SetLogPath(const std::string& path)
    {
        m_out.open(path);
    }

    ///Статический метод
    //Метод вывода сообщения в файл, получающий на вход какое-либо сообщение
    static void Write(const std::string& str)
    {
        if (m_logLevel == LogLevel::DEBUG)
            std::cout << str << std::endl;
        m_out << str << std::endl;
        m_out.flush();
    }

    //Медод, выводящий информацию (работает как и Write)
    static void Info(const std::string& str)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::RELEASE)
            std::cerr<<dt<<str<<std::endl;
        m_out<<dt<<str<<std::endl;
        m_out.flush();
    }
    static void Error(const std::string& str)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<str<<std::endl;
        m_out<<dt<<str<<std::endl;
        m_out.flush();

    }
    static void Debug(const std::string& str)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<str<<std::endl;
        m_out<<dt<<str<<std::endl;
        m_out.flush();
    }
    ~Log()
    {
        std::cout << "Destructor" << std::endl;
    }
};
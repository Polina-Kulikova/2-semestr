#include "Log.hpp"

int main()
{
    Log::SetLogPath("log.txt");
    //Log::SetLogLevel(LogLevel::RELEASE);
    Log::Write("Hello, world!");
    Log::Info("Лабораторная работа");
    Log::Debug("Program is working!");
    Log::Error("ERROR");
    return 0;
}

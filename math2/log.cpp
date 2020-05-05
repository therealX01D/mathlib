#include "log.h"
#include "pch.h"
void log(const char* message, float num) {
    std::cout << message << " "<<std::to_string(num)<<"\n";
}
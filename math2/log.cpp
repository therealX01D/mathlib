#include "log.h"
void log(const char* message, int num) {
    cout << message << to_string(num) << endl;
    cin.get();
}
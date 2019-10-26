#include <iostream>

#include "src/ConfigReader.h"

ConfigReader cr("demo/demo.conf");

int main() {
    std::cout << cr["Address"]
    << cr.GetConfig("Author")
    << "\nFinished\n";
    return 0;
}
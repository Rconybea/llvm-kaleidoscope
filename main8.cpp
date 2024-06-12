#include <iostream>

extern "C" { double average(double, double); }

int main() {
    std::cout << "average(3,4): " << average(3.0, 4.0) << std::endl;
}

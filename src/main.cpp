#include <iostream>


int main() {
#ifdef __clang__
std::cout << "__clang__ is defined — Clang front-end detected\n";
#endif


#ifdef _MSC_VER
std::cout << "_MSC_VER is defined (MSVC compatibility macros present): " << _MSC_VER << "\n";
#endif


std::cout << "Hello from clang-cl on Windows!" << std::endl;
return 0;
}
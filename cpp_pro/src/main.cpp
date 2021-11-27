/* file:test.cpp */
#include "include/include_a.h"
#include "include/include_b.h"
#include "include_common.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << add_ten(1) << std::endl;
    std::cout << add_one(1) << std::endl;
    print(10);
    return 0;
}

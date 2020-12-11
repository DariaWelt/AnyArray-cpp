#include <iostream>
#include "AnyArray.h"
int main() {
    AnyArray array;
    int i = 10;
    double d = 3.14;
    std::pair<int, bool> p = {i, true};

    array.Push(i);
    array.Push(d);
    array.Push(p);

    int i2 = 0;
    array.Get(0, i2);
    if (i2 != 0)
        std::cout <<  "test1: i2 = " << i2 << std::endl;
    i2 = 0;

    array.Get(1, i2);
    if (i2 != 0)
        std::cout << "test2: i2 = " << i2 << std::endl;
    i2 = 0;

    AnyArray array2 = array;
    array2.Push(23);
    array2.Get(3, i2);
    if (i2 != 0)
        std::cout << "test3: i2 = " << i2 << std::endl;
    return 0;
}

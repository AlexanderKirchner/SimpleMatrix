#include <iostream>

#include "Matrix.h"

int main()
{
    mx::Matrix m1(mx::MatrixSize(3, 3));
    m1.fillRandom();
    mx::Matrix m2(mx::MatrixSize(3, 3));
    m2.fillRandom();
    mx::Matrix mr = m2.multiply(m1);

    m1.cout();
    m2.cout();
    mr.cout();

    return 0;
}
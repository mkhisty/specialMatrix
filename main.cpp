#include <iostream>
#include "specialMatrix.hpp"

int main() {
    std::cout << "Testing specialMatrix class functions:\n\n";

    // Test constructors
    std::cout << "1. Creating random 2x2 matrix:\n";
    specialMatrix sp1(2, 2, false);
    sp1.toNormal();
    std::cout << sp1 << std::endl;

    std::cout << "2. Creating identity 2x2 matrix:\n";
    specialMatrix identity(2, 2, true);
    std::cout << identity << std::endl;

    // Test scalar operations
    std::cout << "3. Matrix * 3:\n";
    std::cout << (sp1 * 3.0) << std::endl;

    std::cout << "4. Matrix / 2:\n";
    std::cout << (sp1 / 2.0) << std::endl;

    std::cout << "5. Matrix + 5:\n";
    std::cout << (sp1 + 5.0) << std::endl;

    std::cout << "6. Matrix - 1:\n";
    std::cout << (sp1 - 1.0) << std::endl;

    // Test matrix multiplication
    specialMatrix sp2(2, 2, false);
    std::cout << "7. Second matrix:\n";
    std::cout << sp2 << std::endl;

    std::cout << "8. Matrix multiplication (sp1 & sp2):\n";
    std::cout << (sp1 & sp2) << std::endl;

    // Test determinant
    std::cout << "9. Determinant of sp1: " << sp1.det() << std::endl;

    // Test powers
    std::cout << "\n10. sp1^0 (identity):\n";
    std::cout << (sp1 ^ 0) << std::endl;

    std::cout << "11. sp1^2:\n";
    std::cout << (sp1 ^ 2) << std::endl;

    std::cout << "12. sp1^(-1) (inverse):\n";
    std::cout << (sp1 ^ (-1)) << std::endl;

    std::cout << "All functions tested!\n";
    return 0;
}

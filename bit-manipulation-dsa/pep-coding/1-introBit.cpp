
#include <bits/stdc++.h>
 using namespace std;

int main() {
    // Bitwise AND (&)
    int a = 10; // Binary: 1010
    int b = 6;  // Binary: 0110
    int result = a & b;
    std::cout << result << std::endl; // Output: 2 (Binary: 0010)

    // Bitwise OR (|)
    a = 10;    // Binary: 1010
    b = 6;     // Binary: 0110
    result = a | b;
    std::cout << result << std::endl; // Output: 14 (Binary: 1110)

    // Bitwise XOR (^)
    a = 10;    // Binary: 1010
    b = 6;     // Binary: 0110
    result = a ^ b;
    std::cout << result << std::endl; // Output: 12 (Binary: 1100)

    // Bitwise NOT (~)
    a = 10;    // Binary: 00000000000000000000000000001010
    result = ~a;
    std::cout << result << std::endl; // Output: -11 (Binary: 11111111111111111111111111110101)

    // Left shift (<<)
    a = 5;     // Binary: 00000000000000000000000000000101
    int shiftAmount = 2;
    result = a << shiftAmount;
    std::cout << result << std::endl; // Output: 20 (Binary: 00000000000000000000000000010100)

    // Right shift (>>)
    a = 20;    // Binary: 00000000000000000000000000010100
    shiftAmount = 2;
    result = a >> shiftAmount;
    std::cout << result << std::endl; // Output: 5 (Binary: 00000000000000000000000000000101)

    // Setting a bit
    a = 10;    // Binary: 00000000000000000000000000001010
    int bitPosition = 3;
    result = a | (1 << bitPosition);
    std::cout << result << std::endl; // Output: 14 (Binary: 00000000000000000000000000001110)

    // Clearing a bit
    a = 14;    // Binary: 00000000000000000000000000001110
    bitPosition = 2;
   

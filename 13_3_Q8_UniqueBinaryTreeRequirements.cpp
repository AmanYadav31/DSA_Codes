#include <iostream>
/*
TC=O(1)
SC=O(1)
We can construct unique tree from (inorder + post/pre order)
Pre+post ke saath unique toh nahi kar paaenge, binary tree construct kar sakte hain.*/
bool isPossible(int a, int b) {
    if ((a == 1 && b == 2) || (a == 2 && b == 1) || (a == 2 && b == 3) || (a == 3 && b == 2))
        return true;
    return false;
}

int main() {
    // Example usage
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    if (isPossible(num1, num2))
        std::cout << "The condition is possible." << std::endl;
    else
        std::cout << "The condition is not possible." << std::endl;

    return 0;
}

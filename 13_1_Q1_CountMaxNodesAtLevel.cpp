#include <iostream>
#include <cmath>
/*Optimal Approach=>
TC=O(1)
SC=O(1)*/
int countNodes(int i) {
    int x = static_cast<int>(pow(2, i - 1));
    return x;
}

int main() {
    int i;
    std::cout << "Enter a value for i: ";
    std::cin >> i;

    int result = countNodes(i);
    std::cout << "The number of nodes is: " << result << std::endl;

    return 0;
}

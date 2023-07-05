#include <iostream>
#include <cmath>

/*Optimal Approach=>
TC=O(1)
SC=O(1)

Har edge ke paas do option honge, ya toh present or not. Humne pahle saare pairs nikale aur phir bas prsent
or not dekhte gaye.*/
long long count(int n) {
    long long nC2 = (n * (n - 1)) / 2;
    return std::pow(2, nC2);
}

int main() {
    int n;
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    long long numGraphs = count(n);
    std::cout << "The number of undirected graphs that can be constructed from " << n << " vertices is: " << numGraphs << std::endl;

    return 0;
}

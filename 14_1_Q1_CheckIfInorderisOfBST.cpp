#include <iostream>
#include <vector>

/*
TC=O(N)
SC=O(1)*/
bool isBSTTraversal(std::vector<int>& nums) {
    // your code here
    for (int i = 0; i < nums.size() - 1; i++) {
        if (!(nums[i] < nums[i + 1])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    bool isBST = isBSTTraversal(nums);
    
    if (isBST) {
        std::cout << "The given sequence is a valid BST traversal." << std::endl;
    } else {
        std::cout << "The given sequence is not a valid BST traversal." << std::endl;
    }
    
    return 0;
}

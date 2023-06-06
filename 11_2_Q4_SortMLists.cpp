#include <iostream>
#include <queue>
using namespace std;

// Definition of a node in a linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Function to merge K sorted linked lists.

    /*Optimal Approach=>
    TC=O(n*klog(n*k))
    SC=O(n*k)
    */
    Node* mergeKLists(Node* arr[], int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            while (arr[i] != nullptr) {
                pq.push(arr[i]->data);
                arr[i] = arr[i]->next;
            }
        }
        Node* ans = new Node(0);
        Node* temp = ans;
        while (!pq.empty()) {
            ans->next = new Node(pq.top());
            ans = ans->next;
            pq.pop();
        }
        return temp->next;
    }
};

int main() {
    // Creating example linked lists
    Node* arr[3];
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);
    arr[0] = list1;

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);
    arr[1] = list2;

    Node* list3 = new Node(2);
    list3->next = new Node(6);
    arr[2] = list3;

    // Merge the linked lists
    Solution solution;
    Node* mergedList = solution.mergeKLists(arr, 3);

    // Print the merged list
    while (mergedList != nullptr) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}

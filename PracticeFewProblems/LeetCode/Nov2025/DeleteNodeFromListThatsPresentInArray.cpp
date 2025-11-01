#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> us(nums.begin(), nums.end()); // Storing elements of nums in a set for O(1) access time

        // Case a : Starting nodes of the list are in nums. For example, head itself in
        // nums or the first few nodes starting from head are in nums array
        while(head && us.count(head->val)) {
            head = head -> next;
        }

        // Case b : If the node next to the current node is in nums array, we update the next
        // pointer to the curr->next->next node. The same is true for any number of nodes(>1).
        // Skip those nodes till we either reach the end of the list or the first node which is not
        // present in nums.
        
        ListNode* curr = head;
        while(curr && curr->next) {
            while(curr->next && us.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        return head;
    }

    /*
    Let m be the number of nodes in the linked list and n be the number of elements in the array nums.

    Building the unordered_set from the nums array takes O(n) time.

    Now, In the nested while loop, we traverse each node of the linked list at most once. The inner while loop
    skips nodes that are present in the unordered_set. Each node is processed only once, leading to a total of O(m) time for traversing the linked list.

    Therefore, the overall time complexity of the modifiedList function is O(m + n).

    */
};

ListNode* createAndGetTheList(ListNode*& head) {
    int m;
    cout << "Enter number of nodes in linked list: ";
    cin >> m;
    cout << "Enter elements of linked list: ";
    ListNode* tail = nullptr;
    for(int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {

    // Read Single linked list from input
    ListNode* head = nullptr;
    createAndGetTheList(head);

    // Print original linked list
    ListNode* temp = head;
    cout << "Original Linked List: ";
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << std::endl;

    // Read input array
    int n;
    std::cout << "Enter number of elements in array: ";
    std::cin >> n;
    std::vector<int> arr(n);
    std::cout << "Enter elements of array in sorted order: ";
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    Solution sol;
    ListNode* modifiedHead = sol.modifiedList(arr, head);
    // Print modified linked list
    ListNode* curr = modifiedHead;
    std::cout << "Modified Linked List: ";
    while(curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}
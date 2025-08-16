// Apprach 1: Check if a linked list is a palindrome - Not using Stack
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

// Node structure definition
struct Node {
    int data;
    std::shared_ptr<Node> next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a linked list from vector
std::shared_ptr<Node> createLinkedList(const std::vector<int>& input) {
    if (input.empty()) return nullptr;
    
    std::shared_ptr<Node> head = std::make_shared<Node>(input[0]);
    std::shared_ptr<Node> current = head;
    for (size_t i = 1; i < input.size(); ++i) {
        current->next = std::make_shared<Node>(input[i]);
        current = current->next;
    }
    return head;
}

// Function to check if linked list is palindrome
bool isPalindromeList(std::shared_ptr<Node> head) {
    if (!head || !head->next) return true; // Empty or single element list is a palindrome

    // Find middle of the linked list
    std::shared_ptr<Node> slow = head;
    std::shared_ptr<Node> fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    std::shared_ptr<Node> prev = nullptr;
    std::shared_ptr<Node> current = slow;
    while (current) {
        std::shared_ptr<Node> nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Compare first half with reversed second half
    std::shared_ptr<Node> firstHalf = head;
    std::shared_ptr<Node> secondHalf = prev;
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {
    // Get input from user
    std::vector<int> input;
    std::cout << "Enter elements of the linked list (end with -1): ";
    int value;
    while (std::cin >> value && value != -1) {
        input.push_back(value);
    }

    if (input.empty()) {
        std::cout << "The linked list is empty." << std::endl;
        return 0;
    }

    // Create linked list and check palindrome
    std::shared_ptr<Node> head = createLinkedList(input);
    bool isPalindrome = isPalindromeList(head);

    // Output result
    if (isPalindrome) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}

/*
Notes:
- This code defines a linked list and checks if it is a palindrome without using a stack.
- It uses a two-pointer technique to find the middle of the list, reverses the second half, and then compares the two halves.
*/
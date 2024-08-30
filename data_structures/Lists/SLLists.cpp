// Singly-linked list implementation
#include <iostream>

// SLList Class
class SLList {
    // Embed an IntNode class in SLList
public:
    class IntNode {
    public:
        int item;
        IntNode* next;

        IntNode(int i, IntNode* n) {
            item = i;
            next = n;
        }
    };

    // Constructor
    SLList(int x) {
        first = new IntNode(x, nullptr);
        // set size to 1
        size = 1;
    }

    // Default constructor
    SLList() {
        first = nullptr;
        size = 0;
    }

    // Helper methods
    void addFirst(int x) {
        first = new IntNode(x, first);
        // +1 to size
        size += 1;
    }

    int getFirst() {
        return first->item;
    }

    void addLast(int x) {
        // If the list is empty, directly add a node
        if(first == nullptr) {
            first = new IntNode(x, nullptr);
        }
        else {
        // Declare and initialize a pointer for iteration
        IntNode* p = first;

        // Iterate till the end of SLList
        while(p->next != nullptr){
            p = p->next;
        }
        // Create a new pointer at the end of the list
        p->next = new IntNode(x, nullptr);
        }
        
        // +1 to size
        size += 1;
    }

    int getSize() {
        return size;
    }

private:
    // first is a pointer to an IntNode
    IntNode* first;
    int size;
};

int main(){

    // Test the IntNode
    SLList::IntNode L1 {5, nullptr};
    std::cout << L1.item << std::endl; // 5

    L1 = SLList::IntNode{10, &L1};
    std::cout << L1.item << std::endl; // 10

    // Test SLList
    SLList SLL1 {5};
    // std::cout << SLL1.first->item << std::endl; // Error: first is private
    SLL1 = SLList{10};

    // addFirst & getFirst
    SLL1.addFirst(15);
    std::cout << SLL1.getFirst() << std::endl; // 15

    // addLast
    SLL1.addLast(0);

    // getSize
    std::cout << SLL1.getSize() << std::endl;
}

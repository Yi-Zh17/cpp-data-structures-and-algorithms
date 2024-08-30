// Create a generic doubly-linked list structure using template
#include <iostream>


template <typename T>
class DLList {
public:
    // The node class
    class Node {
    public:
        Node* prev;
        T item;
        Node* next;

        Node(const T& i, Node* prev, Node* next)
        {
            item = i;
            this.prev = prev;
            this.next = next;
        }
    };

    // Constructor
    DLList(const T& i)
    {
        first = new Node(i, first, first);
        sentinel = &first;
    }

    DLList()
    {
        first = nullptr;
        sentinel = &first;
    }

    // Methods
    void addFirst(const T& i)
    {
        if(sentinel != 0)
        {

        }
    }

private:
    Node* first;
    Node* sentinel;
    int size;
};

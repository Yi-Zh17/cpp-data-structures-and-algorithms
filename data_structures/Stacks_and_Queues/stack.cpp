#include <iostream>

template <class T>
class Stack
{
public:

    Stack(int size)
    {
        array = new T[size + 1]; // Assign an array pointer to array
        top = 0; // top points to first index in array
        capacity = size;
    }

    ~Stack()
    {
        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }
    }

    void push(T item)
    {
        if (top == capacity)
            std::cerr << "Error: Stack overflow" << std::endl;
        array[++top] = item;
    }

    T pop()
    {
        if (this->isEmpty())
        {
            std::cerr << "Error: Stack underflow" << std::endl;
        }
        else
        {
            T temp = array[top];
            top--;
            return temp;
        }
    }

    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }

private:
    int top;
    int capacity;
    T* array = nullptr;
};


int main()
{
    // Construction and isEmpty
    Stack<int>* stk = new Stack<int>(8);
    std::cout << std::boolalpha << "stack is empty: " << stk->isEmpty() << std::endl;

    // Push
    stk->push(1);
    stk->push(2);
    std::cout << std::boolalpha << "stack is empty: " << stk->isEmpty() << std::endl;

    // Pop
    std::cout << "Popped " << stk->pop() << " out" << std::endl;
    std::cout << "Popped " << stk->pop() << " out" << std::endl;
    std::cout << std::boolalpha << "stack is empty: " << stk->isEmpty() << std::endl;

    // Should give an error
    std::cout << stk->pop() << std::endl;

    stk->push(1);
    stk->push(2);
    stk->push(3);
    stk->push(4);
    stk->push(5);
    stk->push(6);
    stk->push(7);
    stk->push(8);

    // Should give an error
    stk->push(9);
    delete stk;
}
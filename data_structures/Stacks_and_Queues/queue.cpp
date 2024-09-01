#include <iostream>

template <class T>
class Queue
{
public:
    Queue(int size)
    {
        array = new T[size];
        capacity = size;
        head = int(size/2);
        tail = head + 1;
        this->size = 0;
    }

    ~Queue()
    {
        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }
    }

    void enqueue(T item)
    {
        // Error if full
        if (tail == head)
        {
            std::cerr << "Error: queue is full" << std::endl;
            return;
        }
        // If queue is empty
        if (this->size == 0) array[head] = item;
        else
        {
            array[tail] = item;
            if (tail == capacity - 1) tail = 0;
            else tail++;
        }
    }

    T dequeue()
    {
        if (size == 0)
            std::cerr << "Error: queue is empty" << std::endl;
        else
        {
            T temp = array[head];
            if (head == capacity - 1) head = 0;
            else head++;
            return temp;
        }
    }

private:
    int size;
    int head;
    int tail;
    int capacity;
    T* array;
};



int main()
{

}
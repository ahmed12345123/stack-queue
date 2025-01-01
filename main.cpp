#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* queue;
    int front, rear, size, capacity;

public:
    ArrayQueue(int capacity) : capacity(capacity), front(0), size(0), rear(capacity - 1) {
        queue = new int[capacity];
    }

    ~ArrayQueue() {
        delete[] queue;
    }

    void enQueue(int data) {
        if (size == capacity) {
            throw runtime_error("Queue is full!");
        }
        rear = (rear + 1 < capacity) ? rear + 1 : 0;
        queue[rear] = data;
        size++;
    }

    int deQueue() {
        if (size == 0) {
            throw runtime_error("Queue is empty!");
        }
        int value = queue[front];
        front = (front + 1 < capacity) ? front + 1 : 0;
        size--;
        return value;
    }

    int getFront() {
        if (size == 0) {
            throw runtime_error("Queue is empty!");
        }
        return queue[front];
    }

    int getRear() {
        if (size == 0) {
            throw runtime_error("Queue is empty!");
        }
        return queue[rear];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            int index = front + i;
            if (index >= capacity) {
                index -= capacity;
            }
            cout << queue[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue q(5);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.display();

    q.deQueue();
    q.display();

    q.enQueue(4);
    q.enQueue(5);
    q.display();

    q.deQueue();
    q.deQueue();
    q.display();

    return 0;
}

























#include <iostream>
using namespace std;

class LinkedListQueue {
private:
   struct Node {
       int data;
       Node* next;
       Node(int val) : data(val), next(nullptr) {}
   };
   Node* front;
   Node* rear;

public:
   LinkedListQueue() : front(nullptr), rear(nullptr) {}

   void enQueue(int data) {
       Node* newNode = new Node(data);
       if (!rear) {
           front = rear = newNode;
           return;
       }
       rear->next = newNode;
       rear = newNode;
   }

   int deQueue() {
       if (!front) {
           throw runtime_error("Queue is empty!");
       }
       int value = front->data;
       Node* temp = front;
       front = front->next;
       if (!front) {
           rear = nullptr;
       }
       delete temp;
       return value;
   }

   int getFront() {
       if (!front) {
           throw runtime_error("Queue is empty!");
       }
       return front->data;
   }

   int getRear() {
       if (!rear) {
           throw runtime_error("Queue is empty!");
       }
       return rear->data;
   }

   void display() {
       Node* current = front;
       while (current) {
           cout << current->data << " ";
           current = current->next;
       }
       cout << endl;
   }
};





int main() {
   LinkedListQueue queue;

   // Enqueue some elements
   queue.enQueue(10);
   queue.enQueue(20);
   queue.enQueue(30);

   cout << "Queue after enQueue operations: ";
   queue.display();

   // Get the front and rear elements
   cout << "Front: " << queue.getFront() << endl;
   cout << "Rear: " << queue.getRear() << endl;

   // Dequeue an element
   cout << "Dequeue: " << queue.deQueue() << endl;

   // Display the queue after dequeue
   cout << "Queue after deQueue: ";
   queue.display();

   // Dequeue remaining elements
   cout << "Dequeue: " << queue.deQueue() << endl;
   cout << "Dequeue: " << queue.deQueue() << endl;

   // Try to dequeue from an empty queue
   try {
       cout << "Dequeue from empty queue: " << queue.deQueue() << endl;
   } catch (const runtime_error& e) {
       cout << "Error: " << e.what() << endl;
   }

   return 0;
}

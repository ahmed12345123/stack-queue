//#include <iostream>
//using namespace std;
//
//class ArrayStack {
//private:
//    int* stack;
//    int top;
//    int capacity;
//
//public:
//    ArrayStack(int size) : capacity(size), top(-1) {
//        stack = new int[size];
//    }
//
//    ~ArrayStack() {
//        delete[] stack;
//    }
//
//    void push(int data) {
//        if (top == capacity - 1) {
//            throw runtime_error("Stack is full!");
//        }
//        stack[++top] = data;
//    }
//
//    int pop() {
//        if (top == -1) {
//            throw runtime_error("Stack is empty!");
//        }
//        return stack[top--];
//    }
//
//    int peek() {
//        if (top == -1) {
//            throw runtime_error("Stack is empty!");
//        }
//        return stack[top];
//    }
//
//    void display() {
//        for (int i = 0; i <= top; i++) {
//            cout << stack[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    ArrayStack stack(5);
//
//    stack.push(10);
//    stack.push(20);
//    stack.push(30);
//
//    stack.display();
//
//    cout << "Top element is: " << stack.peek() << endl;
//
//    cout << "Popped element: " << stack.pop() << endl;
//
//    cout << "Stack after popping: ";
//    stack.display();
//
//    stack.push(40);
//    stack.push(50);
//    stack.push(60);
//
//    stack.display();
//
//    stack.push(70);
//
//    return 0;
//}
//

























#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;

    Node(int _data) : data(_data), prev(nullptr) {}
};

class Stack {
private:
    Node* tail;

public:
    Stack() : tail(nullptr) {}

    void push(int _data) {
        Node* newNode = new Node(_data);
        if (tail == nullptr) {
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int pop() {
        if (tail == nullptr) {
            throw runtime_error("Stack is empty!");
        }
        int value = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        return value;
    }

    int peek() {
        if (tail == nullptr) {
            throw runtime_error("Stack is empty!");
        }
        return tail->data;
    }

    void display() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << "\t";
            current = current->prev;
        }
        cout << endl;
    }


    ~Stack() {
        while (tail != nullptr) {
            Node* temp = tail;
            tail = tail->prev;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack contents: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped: " << stack.pop() << endl;

    cout << "Stack contents after pop: ";
    stack.display();

    return 0;
}


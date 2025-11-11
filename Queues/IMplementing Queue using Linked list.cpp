#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;  // points to first element
    Node* rear;   // points to last element

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue (Insert element at rear)
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == nullptr) {  // empty queue
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue (Remove element from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // if queue becomes empty
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Peek front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // Queue elements: 10 20 30

    cout << "Front element: " << q.peek() << endl; // 10

    q.dequeue();
    q.display(); // Queue elements: 20 30

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Queue Underflow!

    return 0;
}

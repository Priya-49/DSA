#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    static const int MAX = 10;   // maximum capacity
    int arr[MAX];                // array to store elements
    int start = 0;               // index of front element
    int end = -1;                // index of last element
    int currSize = 0;            // current number of elements

public:
    // Add element at rear
    void enqueue(int val) {
        if(currSize == MAX) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        end = (end + 1) % MAX;
        arr[end] = val;
        currSize++;
    }

    // Remove element from front
    void dequeue() {
        if(currSize == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        start = (start + 1) % MAX;
        currSize--;
    }

    // Get front element
    int front() {
        if(currSize == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[start];
    }

    // Get current size
    int size() {
        return currSize;
    }

    // Check if queue is empty
    bool isEmpty() {
        return currSize == 0;
    }

    // Check if queue is full
    bool isFull() {
        return currSize == MAX;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    cout << "Front: " << q.front() << endl; // 10
    q.dequeue();
    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Yes

    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << endl; // 20

    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl; // 30

    // Fill queue completely
    for(int i=0; i<9; i++) q.enqueue(i+100); // now size = MAX
    cout << "Is full? " << (q.isFull() ? "Yes" : "No") << endl; // Yes

    return 0;
}

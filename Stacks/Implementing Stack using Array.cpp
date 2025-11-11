#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100; // maximum size of stack
    int arr[MAX];               // fixed-size array
    int topIndex;               // index of top element

public:
    // Constructor
    Stack() {
        topIndex = -1; // stack is empty
    }

    // Push element onto stack
    void push(int x) {
        if (topIndex == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    // Return top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Return current size of stack
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;  // 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 20
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Stack size: " << s.size() << endl; // 2

    return 0;
}

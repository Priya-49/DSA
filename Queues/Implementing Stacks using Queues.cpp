/*
Problem Statement:
------------------
Implement a queue using two stacks.

Implement the MyQueue class:
- void push(int x): Pushes element x to the back of the queue.
- int pop(): Removes the element from the front of the queue and returns it.
- int peek(): Returns the element at the front of the queue.
- bool empty(): Returns true if the queue is empty, false otherwise.

------------------------------------------------------------
Approach: Two-Stack Queue
-------------------------
- Maintain two stacks: `in` (for push operations) and `out` (for pop/peek).
- push(x): Always push into `in`.
- pop(): If `out` is empty, transfer all elements from `in` to `out`. Then pop from `out`.
- peek(): Same logic as pop but just return `out.top()`.
- empty(): Return true if both `in` and `out` are empty.

Why this works:
- The transfer (`shift()`) reverses order, so the oldest element ends up at the top of `out`.
- This simulates FIFO behavior of a queue.

Time Complexity:
- Push: O(1)
- Pop: Amortized O(1) (each element moves at most once between stacks)
- Peek: Amortized O(1)
- Empty: O(1)

Space Complexity: O(N)
- Elements are stored in two stacks.

*/

class MyQueue {
public:
    stack<int> in, out;

    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        shift();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        shift();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }

private:
    void shift() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
};

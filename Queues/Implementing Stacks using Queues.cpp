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
Approach 1: Two-Stack Queue
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

Approach 2:
- Use two stacks (s1, s2).
- For push(x):
    - Move all elements from s1 to s2.
    - Push x into s1.
    - Move back all elements from s2 to s1.
  This ensures that the front element of the queue is always on top of s1.
- For pop():
    - Simply pop the top of s1 (which is the queue front).
- For peek():
    - Return the top of s1.
- For empty():
    - Check if s1 is empty.

Time Complexity:
- push(x): O(n)  (because all elements are moved twice in worst case)
- pop():   O(1)
- peek():  O(1)
- empty(): O(1)

Space Complexity:
- O(n) for storing n elements across two stacks.
*/

//Aproach 1
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

//Approach 2

class MyQueue {
public:
    stack<int> s1, s2;

    void push(int x) {
        // Move everything from s1 -> s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push new element into s1
        s1.push(x);
        // Move everything back from s2 -> s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/*
Problem Statement:
------------------
Implement a stack (LIFO) using queues (FIFO). 
Provide operations: push(x), pop(), top(), and empty().

We need to simulate stack behavior using standard queue operations.

Approach 1: Costly Push (Two Queues)
------------------------------------
- Always push the new element into the empty queue (q1).
- Move all elements from q1 to q2, then swap queues.
- Ensures new element stays at the front, simulating stack order.
- Push: O(n), Pop: O(1), Top: O(1), Empty: O(1).
- Extra Space: O(n).

Approach 2: Costly Pop/Top (Two Queues)
---------------------------------------
- Push is cheap, directly into q1.
- For pop/top, shift n-1 elements into q2, leaving last in q1.
- For pop: remove it. For top: read it and move it to q2.
- Swap queues afterward.
- Push: O(1), Pop: O(n), Top: O(n), Empty: O(1).
- Extra Space: O(n).

Approach 3: Single Queue (Rotation)
-----------------------------------
- Push element to q.
- Rotate the queue (push front to back) until the new element is at front.
- This ensures LIFO order.
- Push: O(n), Pop: O(1), Top: O(1), Empty: O(1).
- Extra Space: O(n).

Time and Space Complexity Summary:
----------------------------------
Approach 1: Push O(n), Pop O(1), Top O(1), Space O(n).
Approach 2: Push O(1), Pop O(n), Top O(n), Space O(n).
Approach 3: Push O(n), Pop O(1), Top O(1), Space O(n).
*/

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------
// Approach 1: Costly Push (Two Queues)
//--------------------------------------------------
class MyStack1 {
public:
    queue<int> q1, q2;

    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

//--------------------------------------------------
// Approach 2: Costly Pop/Top (Two Queues)
//--------------------------------------------------
class MyStack2 {
public:
    queue<int> q1, q2;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        shift();
        int x = q1.front();
        q1.pop();
        swap(q1, q2);
        return x;
    }

    int top() {
        shift();
        int x = q1.front();
        q2.push(x);   // preserve top
        q1.pop();
        swap(q1, q2);
        return x;
    }

    bool empty() {
        return q1.empty();
    }

private:
    void shift() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }
};

//--------------------------------------------------
// Approach 3: Single Queue (Rotation)
//--------------------------------------------------
class MyStack3 {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);
        for(int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

/*
Problem Statement:
------------------
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- void push(int val) – Push element val onto the stack.
- void pop() – Remove the element on top of the stack.
- int top() – Get the top element.
- int getMin() – Retrieve the minimum element in the stack.

------------------------------------------------------------
Approach 1: Stack of Pairs (Standard)
-------------------------------------
- Use stack<pair<int,int>> where:
  first = actual value
  second = current minimum at the time of push.
- On push: store {val, min(val, currentMin)}.
- On pop: simply pop the pair.
- Top: return pair.first
- getMin: return pair.second
- Time Complexity: O(1) per operation
- Space Complexity (excluding stack memory): 
  For every push, we store a pair (2 values) → 'n' push operations → O(2*N)

-------------------------------------------  
Approach 2: Encoded Min Tracking (Optimized)
-------------------------------------------
- Use a single stack<long long> and track `minVal` (current minimum).
- When pushing a new element:
  - If val < minVal, push encoded value = 2*val - minVal, and update minVal = val.
  - Else push val normally.
- On pop, if top < minVal, decode previous min using minVal = 2*minVal - top.
- Top element:
  - If top < minVal, return minVal (encoded value present).
  - Else return top normally.

Time Complexity: O(1) for all operations
Space Complexity (excluding stack memory): O(1)
- Only one extra variable `minVal` is used.

*/

class MinStack {
public:
    stack<long long> s;
    long long minVal;

    MinStack() {
        // constructor
    }

    void push(int val) {
        if (s.empty()) {
            minVal = val;
            s.push(val);
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal); // encode previous min
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top(); // decode previous min
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            return minVal; // encoded value
        }
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

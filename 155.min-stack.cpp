/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (31.94%)
 * Total Accepted:    201.4K
 * Total Submissions: 625.2K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
class MinStack {
    vector<int> _data, _pre_min;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _data.push_back(x);
        _pre_min.push_back(x);
        if (_data.size() > 1)
            _pre_min[_data.size() - 1] = min(_pre_min[_data.size() - 1], _pre_min[_data.size() - 2]);
    }
    
    void pop() {
        if (!_data.empty()) {
            _data.pop_back();
            _pre_min.pop_back();
        }
    }
    
    int top() {
        if (!_data.empty()) {
            return _data.back();
        }
        return -1;
    }
    
    int getMin() {
        if (!_data.empty()) {
            return _pre_min.back();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

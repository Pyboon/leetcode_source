/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (29.95%)
 * Total Accepted:    160.6K
 * Total Submissions: 536.3K
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
public:
    /** initialize your data structure here. */

    stack<int> sta;
    vector<int> minvec;
    MinStack() {
    }

    void push(int x) {
        (this->sta).push(x);
        // if(x<min)min = x;
        if((this->minvec).size()==0){
            (this->minvec).push_back(x);
        }
        else{
            int right = (this->minvec).size()-1;
            int left = 0;
            int mid = (left+right)/2;
            //binary insert
            while(left<mid || right>mid){
                if(x<(this->minvec).at(mid)){
                    left = mid+1;
                }
                else if(x>(this->minvec).at(mid)){
                    right = mid-1;
                }
                else break;
                mid = (left+right)/2;
            }
            if(x<(this->minvec).at(mid)){
                (this->minvec).insert((this->minvec).begin()+mid+1,x);
            }
            else {
                (this->minvec).insert((this->minvec).begin()+mid,x);
            }
        }

    }

    void pop() {
        int x = this->top();
        int right = (this->minvec).size()-1;
        int left = 0;
        int mid = (left+right)/2;
        //binary insert
        while(left<mid || right>mid){
            if(x<(this->minvec).at(mid)){
                left = mid+1;
            }
            else if(x>(this->minvec).at(mid)){
                right = mid-1;
            }
            else break;
            mid = (left+right)/2;
        }
        (this->minvec).erase((this->minvec).begin()+mid);
        (this->sta).pop();
    }

    int top() {
        return (this->sta).top();
    }

    int getMin() {
        return (this->minvec).back();
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

/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (37.54%)
 * Total Accepted:    96.7K
 * Total Submissions: 257.3K
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 *
 * Implement the following operations of a queue using stacks.
 *
 *
 * push(x) -- Push element x to the back of queue.
 *
 *
 * pop() -- Removes the element from in front of queue.
 *
 *
 * peek() -- Get the front element.
 *
 *
 * empty() -- Return whether the queue is empty.
 *
 *
 * Notes:
 *
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> squeue;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        this->squeue.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp;
        while(!(this->squeue.empty())){
            temp.push(this->squeue.top());
            this->squeue.pop();
        }
        int tempint = temp.top();
        temp.pop();
        while(!(temp.empty())){
            this->squeue.push(temp.top());
            temp.pop();
        }
        return tempint;
    }

    /** Get the front element. */
    int peek() {
        stack<int> temp(this->squeue);
        while(!(temp.empty())){
            if(temp.size()==1)return temp.top();
            temp.pop();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return this->squeue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

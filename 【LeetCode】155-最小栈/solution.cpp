class MinStack {
/*
思路：和一般的栈就多了一个找最小值的函数，所以可以利用两个栈来实现，
s1实现puh,pop,top，s2实现获取最小值功能，s2栈顶汇总放置最小值，在进栈的时候判断进栈的值是否比s2的栈顶小，若小则进s2
*/
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(s2.empty()||x<=s2.top())s2.push(x);
        s1.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top())s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1,s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

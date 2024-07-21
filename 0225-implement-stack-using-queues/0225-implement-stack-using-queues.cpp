class MyStack {
private:
    vector<int> v;

public:
    MyStack() {}

    void push(int x) { v.push_back(x); }

    int pop() {
        int val = v.back();
        v.pop_back();
        return val;
    }

    int top() { return v.back(); }

    bool empty() { return v.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// 一个队列就够了
// 注意：这种实现方式即使连续pop也没关系，每次push的操作已经使得队列中的所有元素反向
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size() - 1; ++i){
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = que.front();
        que.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};


// 两个队列的版本
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que2.push(x);
        while(que1.size()) que2.push(que1.front()), que1.pop();
        swap(que1, que2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = que1.front();
        que1.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return que1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }

private:
    queue<int> que1, que2;
};
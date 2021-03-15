// solution1
// slots 容易扩展到线程安全的写法-> 深入理解计算机系统12.5 producer-consumer problem

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        vec.resize(k);
        front = rear = 0;
        slots = sz = k;
    }
    
    bool enQueue(int value) {
        if(slots == 0) return false;
        vec[rear] = value;
        rear = (rear + 1) % sz;
        --slots;
        return true;
    }
    
    bool deQueue() {
        if(slots == sz) return false;
        front = (front + 1) % sz;
        ++slots;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return vec[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return vec[(rear - 1 + sz) % sz];
    }
    
    bool isEmpty() {
        return slots == sz;
    }
    
    bool isFull() {
        return slots == 0;
    }

private:
    int front, rear;
    int slots;
    int sz;
    vector<int> vec;
};

// solution2
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        vec.resize(k);
        front = len = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        int end = (front + len) % sz;
        vec[end] = value;
        ++len;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % sz;
        --len;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return vec[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        int rear = (front + len - 1) % sz;
        return vec[rear];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == sz;
    }

private:
    int front, len;
    int sz;
    vector<int> vec;
};
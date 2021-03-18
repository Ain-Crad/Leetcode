// in 只负责 push, out 只负责pop, 只有在out为空的情况下才把in中所有元素转移到out中
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(out.empty()){
            if(in.empty()) return -1;
            while(in.size()) out.push(in.top()), in.pop();
        }
        int v = out.top();
        out.pop();
        return v;
    }

private:
    stack<int> in, out;
};
// leetcode-146

class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(key2it_.find(key) == key2it_.end()){
            return -1;
        }
        
        auto it = key2it_[key];
        int val = it->second;
        data_.erase(it);
        data_.push_front({key, val});
        key2it_[key] = data_.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(get(key) == -1){
            if(data_.size() == capacity_){
                auto p = data_.back();
                key2it_.erase(p.first);
                data_.pop_back();
            }
            data_.push_front({key, value});
            key2it_[key] = data_.begin(); 
        }else{
            data_.front().second = value;
        }
        
    }
    int capacity_;
    list<pair<int, int>> data_;
    unordered_map<int, list<pair<int, int>>::iterator> key2it_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
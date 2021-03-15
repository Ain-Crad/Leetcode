// solution1
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> vals;
        split(preorder, vals);

        int idx = 0;
        return isValid(vals, idx) && idx == vals.size();
    }

private:
    void split(string& str, vector<string>& vals){
        int n = str.size(), l = 0, r = 0;
        while(l < n){
            while(r < n && str[r] != ',') ++r;
            vals.push_back(str.substr(l, r - l));
            l = ++r;
        }
    }

    bool isValid(vector<string>& vals, int& idx){
        if(idx >= vals.size()) return false;
        
        string val = vals[idx++];
        if(val == "#") return true;
        return isValid(vals, idx) && isValid(vals, idx);

    }
};

// solution2
// 检查入度是否和出度相等
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> vals;
        split(preorder, vals);
        
        int diff = 1;
        for(auto val : vals){
            diff -= 1;
            if(diff < 0) return false;
            if(val != "#") diff += 2;
        }
        return diff == 0;
    }

private:
    void split(string& str, vector<string>& vals){
        int n = str.size(), l = 0, r = 0;
        while(l < n){
            while(r < n && str[r] != ',') ++r;
            vals.push_back(str.substr(l, r - l));
            l = ++r;
        }
    }
};
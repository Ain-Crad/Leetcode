// leetcode-151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        // reverse whole string
        reverse(s, 0, s.size() - 1);

        // reverse each word
        int l = 0, r = 0;
        while(l < s.size()){
            while(l < s.size() && s[l] == ' ') ++l, ++r;
            while(r < s.size() && s[r] != ' ') ++r;
            reverse(s, l, r - 1);
            l = r;
        }
        
        // clean space
        l = r = 0;
        while(r < s.size()){
            while(r < s.size() && s[r] == ' ') ++r;
            while(r < s.size() && s[r] != ' ') s[l++] = s[r++];
            while(r < s.size() && s[r] == ' ') ++r;
            if(r < s.size()) s[l++] = ' ';
        }
        
        int cnt = s.size() - l;
        while(cnt--) s.pop_back();
        return s;
        
    }
    
private:
    void reverse(string &s, int l, int r){
        while(l < r){
            swap(s[l++], s[r--]);
        }
    }
};
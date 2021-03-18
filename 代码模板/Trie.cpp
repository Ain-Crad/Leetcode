// template
struct Node{
    Node *next[26] = {nullptr};
    bool is_word = false;
};

class Trie{
public:    
    void put(const string &s){
        Node *node = &root;
        for(char c : s){
            int p = c - 'a';
            if(node->next[p] == nullptr) node->next[p] = new Node();
            node = node->next[p];
        }
        node->is_word = true;
    }
    
        
    string shortestPrefixOf(const string &s){
        Node *node = &root;
        for(int i = 0; i < s.size(); ++i){
            int p = s[i] - 'a';
            if(node->next[p] == nullptr) return s;
            node = node->next[p];
            if(node->is_word) return s.substr(0, i + 1);
        }
        return s;
    }
    
private:
    Node root;
};


// leetcode-421. Maximum XOR of Two Numbers in an Array
struct TrieNode{
    TrieNode *next[2];
    TrieNode(){
        next[0] = next[1] = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = buildTrie(nums);
        
        int ans = 0;
        for(int v : nums){
            ans = max(ans, solve(root, v));
        }
        return ans;
    }
    
private:
    TrieNode *buildTrie(vector<int> &nums){
        TrieNode *root = new TrieNode();
        for(int v : nums) updateNode(root, v);
        return root;
    }
    
    void updateNode(TrieNode *root, int v){
        for(int i = 31; i >= 0; --i){
            if(v & (1 << i)){
                if(root->next[1] == nullptr) root->next[1] = new TrieNode();
                root = root->next[1];
            }else{
                if(root->next[0] == nullptr) root->next[0] = new TrieNode();
                root = root->next[0];
            }
        }
    }
    
    int solve(TrieNode *root, int v){
        int res = 0;
        for(int i = 31; i >= 0; --i){
            int idx = (v >> i) & 1;
            if(root->next[1 - idx]){
                res |= (1 << i);
                root = root->next[1 - idx];
            }else{
                root = root->next[idx];
            }
        }
        return res;
    }
};
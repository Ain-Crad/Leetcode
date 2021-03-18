// solution1--dfs
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "X";

        string left_sub = serialize(root->left);
        string right_sub = serialize(root->right);
        return to_string(root->val) + "," + left_sub + "," + right_sub;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        split(data, vals);
        int idx = 0;
        return buildTree(vals, idx);
    }

private:
    void split(string& data, vector<string>& vals){
        int n = data.size(), l = 0, r = 0;
        while(l < n){
            while(r < n && data[r] != ',') ++r;
            vals.push_back(data.substr(l, r - l));
            l = ++r;
        }
    }

    TreeNode* buildTree(vector<string>& vals, int& idx){
        if(idx >= vals.size()) return nullptr;

        string val = vals[idx++];
        if(val == "X") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(vals, idx);
        node->right = buildTree(vals, idx);
        return node;
    }
};

// solution2--bfs
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            auto node = que.front();
            que.pop();
            if(node == nullptr) res += "X,";
            else res += to_string(node->val) + ",";
            if(node) que.push(node->left);
            if(node) que.push(node->right);
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "X") return nullptr;

        vector<string> vals;
        split(data, vals);
        
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> que;
        que.push(root);
        int cur = 1;
        while(que.size()){
            auto node = que.front();
            que.pop();
            if(vals[cur] != "X"){
                TreeNode* left = new TreeNode(stoi(vals[cur]));
                node->left = left;
                que.push(left);
            }

            if(vals[cur + 1] != "X"){
                TreeNode* right = new TreeNode(stoi(vals[cur + 1]));
                node->right = right;
                que.push(right);
            }
            cur += 2;
        }
        return root;
    }

private:
     void split(string& data, vector<string>& vals){
        int n = data.size(), l = 0, r = 0;
        while(l < n){
            while(r < n && data[r] != ',') ++r;
            vals.push_back(data.substr(l, r - l));
            l = ++r;
        }
    }
};
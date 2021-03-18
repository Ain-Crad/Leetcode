class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        if(!root->left && !root->right) return to_string(root->val);

        string res = to_string(root->val);
        if(root->left) res += "," + serialize(root->left);
        if(root->right) res += "," + serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vals;
        split(data, vals);
        return buildTree(vals, 0, vals.size() - 1);
    }

private:
    void split(string& data, vector<int>& vals){
        int n = data.size(), l = 0, r = 0;
        while(l < n){
            while(r < n && data[r] != ',') ++r;
            vals.push_back(stoi(data.substr(l, r - l)));
            l = ++r;
        }
    }

    TreeNode* buildTree(vector<int>& vals, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(vals[l]);

        TreeNode* node = new TreeNode(vals[l]);
        int mid = upper_bound(vals.begin() + l + 1, vals.begin() + r + 1, vals[l]) - vals.begin();
        node->left = buildTree(vals, l + 1, mid - 1);
        node->right = buildTree(vals, mid, r);
        return node;

    }
};
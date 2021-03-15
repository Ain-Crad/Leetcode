class UnionFind{
public:
    UnionFind(int n) : par(n), rank(n, 0), size(n, 1){
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            par[x] = y;
            size[y] += size[x];
        }else{
            par[y] = x;
            size[x] += size[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    vector<int> &getSize(){
        return size;
    }
    
private:
    vector<int> par, rank, size;
};

// leetcode-128. Longest Consecutive 
class UnionFind{
public:
    UnionFind(int n) : par(n), rank(n, 0), size(n, 1){
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            par[x] = y;
            size[y] += size[x];
        }else{
            par[y] = x;
            size[x] += size[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
    
    vector<int> &getSize(){
        return size;
    }
    
private:
    vector<int> par, rank, size;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        UnionFind u(nums.size());
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            if(mp.find(num) != mp.end()) continue;
            mp[num] = i;
            if(mp.find(num - 1) != mp.end()) u.unite(i, mp[num - 1]);
            if(mp.find(num + 1) != mp.end()) u.unite(i, mp[num + 1]);
        }
        
        return *max_element(u.getSize().begin(), u.getSize().end());
    }
};

// 721. Accounts Merge
// 字符串并查集用unordered_map<string, string>
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        for(int i = 0; i < acts.size(); ++i){
            for(int j = 1; j < acts[i].size(); ++j){
                owner[acts[i][j]] = acts[i][0];
                par[acts[i][j]] = acts[i][j];
                rank[acts[i][j]] = 0;
            }
        }

        for(int i = 0; i < acts.size(); ++i){
            for(int j = 1; j < acts[i].size(); ++j){
                unite(acts[i][j], acts[i][1]);
            }
        }

        for(int i = 0; i < acts.size(); ++i){
            for(int j = 1; j < acts[i].size(); ++j){
                string par_str = find(acts[i][j]);
                unions[par_str].insert(acts[i][j]);
            }
        }
        
        vector<vector<string>> ans;
        int cnt = 0;
        for(auto p : unions){
            ans.push_back({});
            ans[cnt].push_back(owner[p.first]);
            for(string s : p.second){
                ans[cnt].push_back(s);
            }
            ++cnt;
        }
        return ans;
    }
    
private:
    unordered_map<string, string> owner;
    unordered_map<string, string> par;
    unordered_map<string, int> rank;
    unordered_map<string, set<string>> unions;
    
    string find(string s){
        if(par[s] == s) return s;
        else return par[s] = find(par[s]);
    }
    
    void unite(string x, string y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};
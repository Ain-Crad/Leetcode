// leetcode-207. Course Schedule

// bfs using queue
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        queue<int> topo;
        
        for(auto &e : prerequisites){
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        for(int i = 0; i < n; ++i){
            if(degree[i] == 0){
                topo.push(i);
            }
        }
        int len = 0;
        while(topo.size()){
            int x = topo.front();
            topo.pop();
            for(int j : graph[x]){
                if(--degree[j] == 0) topo.push(j); 
            }
            len++;
        }
        return len == n;
    }
};

// bfs
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0), topo;
        
        for(auto &e : prerequisites){
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
        }
        for(int i = 0; i < n; ++i){
            if(degree[i] == 0){
                topo.push_back(i);
            }
        }
        for(int i = 0; i < topo.size(); ++i){
            for(int j : graph[topo[i]]){
                if(--degree[j] == 0){
                    topo.push_back(j);
                }
            }
        }
        return topo.size() == n;
    }
};

// dfs
class Solution {
    vector<int> state; // -1 unvisited, 0 visiting, 1 visited
    bool dfs(vector<vector<int>> &G, int u) {
        if (state[u] != -1) return state[u];
        state[u] = 0;
        for (int v : G[u]) {
            if (!dfs(G, v)) return false;
        }
        return state[u] = 1;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        vector<vector<int>> G(N);
        state.assign(N, -1);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (!dfs(G, i)) return false;
        }
        return true;
    }
};

// dfs--save topo result
class Solution {
    vector<vector<int>> G;
    vector<int> ans, state; // -1 unvisited, 0 visiting, 1 visited
    bool dfs(int u) {
        if (state[u] != -1) return state[u];
        state[u] = 0;
        for (int v : G[u]) {
            if (!dfs(v)) return false;
        }
        ans.push_back(u);
        return state[u] = 1;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& E) {
        G.assign(n, {});
        state.assign(n, -1);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
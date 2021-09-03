
bool check(vector<bool>&, vis, vector<vector<int>>& graph){
    int n = graph.size();
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            bool res = dfs(graph, 0, 0);
            if(dfs) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<int>>& graph, int v, int u){
    vis[v] = true;
    for(int w : graph[v]){
        if(!vis[w]){
            bool res = dfs(graph, w, v);
            if(res) return true;
        } else if(w != u){
            // w 已经访问过，而且 w 不是 v 的上一个节点 u
            return true;
        }
    }
    return false;
}
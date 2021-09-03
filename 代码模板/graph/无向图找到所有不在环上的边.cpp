// leetcode-1192

// 最后返回的是所有不在环上的边
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(auto& p : connections){
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ranks.resize(n, -2);

        vector<vector<int>> res;

        dfs(0, 0, res);

        return res;
    }

private:
    vector<vector<int>> graph;
    vector<int> ranks; // rank的目的是在递归返回的时候可以方便的判断当前节点是不是环的一部分

    int dfs(int u, int rank, vector<vector<int>>& res){
        // 找到了环
        if(ranks[u] >= 0) return ranks[u];

        ranks[u] = rank;
        int min_rank = rank;

        for(int v : graph[u]){
            // ranks[v] == rank - 1，表示v是u的父节点
            // ranks[v] < rank，表示有环
            // ranks[v] >= rank，表示该节点之前已经处理过
            if(ranks[v] == rank - 1 || ranks[v] >= rank) continue;

            int neighbor_rank = dfs(v, rank + 1, res);
            min_rank = min(min_rank, neighbor_rank);
            if(neighbor_rank > rank) res.push_back({u, v});
        }

        return min_rank;
    }
};
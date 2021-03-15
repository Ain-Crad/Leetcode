// leetcode-886. Possible Bipartition

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N);
        vector<int> rec(N, 0);
        for(auto edge : dislikes){
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        for(int i = 0; i < N; ++i){
            if(rec[i] == 0 && !dfs(graph, rec, i, 1)) return false;
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &rec, int idx, int color){
        rec[idx] = color;
        for(int i : graph[idx]){
            if(rec[i] == color) return false;
            if(rec[i] == 0 && !dfs(graph, rec, i, -color)) return false;
        }
        return true;
    }
};
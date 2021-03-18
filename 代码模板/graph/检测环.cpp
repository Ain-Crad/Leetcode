// leetcode-802. Find Eventual Safe States
// 检测环，0表示未访问，-1表示节点在环上，1表示正常节点
// 和拓扑排序的写法很像

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.resize(n, 0);
        for(int i = 0; i < n; ++i){
            if(dfs(graph, i)) ans.push_back(i);
        }
        return ans;
    }
    
private:
    vector<int> ans, state;
    bool dfs(vector<vector<int>> &graph, int idx){
        if(state[idx] != 0) return state[idx] == 1;
        state[idx] = -1;
        for(int i : graph[idx]){
            if(!dfs(graph, i)) return false;
        }
        state[idx] = 1;
        return true;
    }
};
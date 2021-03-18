// leetcode-399. Evaluate Division

struct Edge{
    int to;
    double cost;
    Edge(int n_to, double n_cost): to(n_to), cost(n_cost){}
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            string a = equations[i][0], b = equations[i][1];
            if(!encode.count(a)) encode[a] = cnt, ++cnt;
            if(!encode.count(b)) encode[b] = cnt, ++cnt;
        }

        vector<Edge> graph[cnt];
        for(int i = 0; i < n; ++i){
            string a = equations[i][0], b = equations[i][1];
            int id1 = encode[a], id2 = encode[b];
            graph[id1].push_back(Edge(id2, values[i]));
            graph[id2].push_back(Edge(id1, 1.0 / values[i]));
        }

        vis.resize(cnt, false);

        int q_len = queries.size();
        vector<double> ans(q_len);
        for(int i = 0; i < q_len; ++i){
            string a = queries[i][0], b = queries[i][1];
            if(!encode.count(a) || !encode.count(b)){
                ans[i] = -1.0;
                continue;
            }
            int id1 = encode[a], id2 = encode[b];
            vis[id1] = true;
            ans[i] = dfs(graph, id1, id2);
            vis[id1] = false;
        }
        return ans;
    }

private:
    vector<bool> vis;
    unordered_map<string, int> encode;
    double dfs(vector<Edge>* graph, int id1, int id2){
        if(id1 == id2) return 1.0;
        for(Edge& e : graph[id1]){
            if(!vis[e.to]){
                vis[e.to] = true;
                double res = dfs(graph, e.to, id2);
                vis[e.to] = false;
                if(res != -1.0) return e.cost * res;
            }
        }
        return -1.0;
    }
};
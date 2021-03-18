struct Edge{
    int to, cost;
    Edge(int n_to, int n_cost):to(n_to), cost(n_cost){}
};
typedef pair<int, int> P;

vector<vector<Edge>> graph(N);
vector<int> d(N, INT_MAX);

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        auto p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;    //v点的距离已被更新为更小的值，队列中的值丢弃
        for(Edge e : graph[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}


// 787. Cheapest Flights Within K Stops
// 求路径长度不大于 K 的最短路
struct Edge{
    int to, cost;
    Edge(int n_to, int n_cost)
        : to(n_to), cost(n_cost){}
};

struct Node{
    int v, cost, step;
    Node(int n_v, int n_cost, int n_step)
        : v(n_v), cost(n_cost), step(n_step){}
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<Edge> graph[n];
        for(auto &e : flights){
            graph[e[0]].push_back(Edge(e[1], e[2]));
        }
        
        vector<int> d(n, INT_MAX);
        d[src] = 0;
        auto cmp = [](Node &lhs, Node &rhs){return lhs.cost < rhs.cost;};
        priority_queue<Node, vector<Node>, decltype(cmp)> que(cmp);
        que.push(Node(src, 0, 0));
        while(que.size()){
            Node cur = que.top();
            que.pop();
            if(cur.step > K) continue;
            
            for(Edge e : graph[cur.v]){
                if(d[e.to] > d[cur.v] + e.cost){
                    d[e.to] = d[cur.v] + e.cost;
                    que.push(Node(e.to, d[e.to], cur.step + 1));
                }
            }
        }
        
        return d[dst] == INT_MAX ? -1 : d[dst];
    }
};
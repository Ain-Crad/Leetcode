class UnionFind{
public:
    vector<int> par, rank;
    UnionFind(int n):par(n), rank(n, 0){
        for(int i = 0; i < n; ++i){
            par[i] = i;
        }
    }
    
    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y]){
            par[y] = x;
        }else{
            par[x] = y;
            if(rank[x] == rank[y]) ++rank[y];
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

struct Edge{
    int u, v, cost;
};

vector<Edge> edges;
int kruskal(){
    // !!!图里的双向边只需要添加一条，表示连接关系
    int n = edges.size();
    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2){return e1.cost < e2.cost;});
    UnionFind uf(n);
    int cost_sum = 0;
    for(int i = 0; i < n; ++i){
        const Edge &e = edges[i];
        if(!uf.same(e.u, e.v)){
            unite(e.u, e.v);
            cost_sum += e.cost;
        }
    }
    return cost_sum;
}
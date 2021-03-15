// leetcode-332. Reconstruct Itinerary
// 模板为有向图模板
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &e : tickets) graph[e[0]].insert(e[1]);
        
        euler("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
    
private:
    vector<string> path;
    unordered_map<string, multiset<string>> graph; // multiset一方面考虑可能有重边，另一方面可以对元素自动排序，不考虑排序可以使用unordered_multiset
    void euler(string u){
        while(graph[u].size()){
            string v = *graph[u].begin();
            graph[u].erase(graph[u].begin());
            euler(v);
        }
        path.push_back(u);
    }
};
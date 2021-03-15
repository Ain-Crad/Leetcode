// leetcode-71. Simplify Path

// solution1
// using while to split
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int i = 0;
        string dir;
        while(i < path.size()){
            while(i < path.size() && path[i] == '/') ++i;
            while(i < path.size() && path[i] != '/') dir += path[i++];
            if(dir.size() && dir != "." && dir != "..") vec.push_back(dir);
            else if(dir == ".." && !vec.empty()) vec.pop_back();
            dir.clear();
        }
        string ans;
        for(const auto &str : vec){
            ans += "/";
            ans += str;
        }
        return ans.empty() ? "/" : ans;
    }
};

// soluton2
// using getline and stringstream to split
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        istringstream ssr(path);
        string s;
        while(getline(ssr, s, '/')){
            if(s.size() && s != ".." && s != ".") vec.push_back(s);
            else if(s == ".." && vec.size()) vec.pop_back();
        }
        string ans;
        for(const auto & str : vec){
            ans += "/";
            ans += str;
        }
        return ans.empty() ? "/" : ans;
    }
};
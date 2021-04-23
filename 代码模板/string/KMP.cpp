// reference--https://ruanx.net/kmp/
// 阮行止

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// next[i] 表示 P[0] ~ P[i] 这一个子串，使得前 k 个字符恰等于后 k 个字符 的最大的 k. 
// 特别地，k 不能取 i+1（因为这个子串一共才 i+1 个字符，自己肯定与自己相等，就没有意义了）。
void buildNext(string &p, vector<int> &next){
    next[0] = 0;
    int p_idx = 1, pre_match_len = 0;
    while(p_idx < p.size()){
        if(p[p_idx] == p[pre_match_len]){
            ++pre_match_len;
            next[p_idx] = pre_match_len;
            ++p_idx;
        }else if(pre_match_len > 0){
            pre_match_len = next[pre_match_len - 1];
        }else{
            next[p_idx] = 0;
            ++p_idx;
        }
    }
}

// s: 主串
// p: 模式串
void search(string &s, string &p, vector<int> &next){
    bool match = false;
    int s_idx = 0, p_idx = 0;       // s_idx 表示当前 s下标，p_idx 表示当前 p 下标 
    while(s_idx < s.size()){
        if(s[s_idx] == p[p_idx]) ++s_idx, ++p_idx;      //当前匹配相等，各前进一步
        else if(p_idx > 0) p_idx = next[p_idx - 1];     //失配，若失配位置 p_idx > 0, 则依据next数组移动标尺
        else ++s_idx;       // p[0]失配，直接把标尺右移一位

        if(p_idx == p.size()){      // 匹配成功
            match = true;
            cout << s_idx - p_idx << endl;
            p_idx = next[p_idx - 1];
        }
    }
    if(!match) cout << -1 << endl;     // 无匹配
}

int main(){
    string s = "aabaabb", p = "aabb";
    vector<int> next(p.size(), 0);
    buildNext(p, next);
    search(s, p, next);

    return -1;
}
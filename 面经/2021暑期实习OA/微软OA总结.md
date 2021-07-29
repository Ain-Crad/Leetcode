### 微软OA总结

1. 二叉搜索树的最近公共祖先

   ```c++
   // 1.当前节点的val大于p->val和q->val，去左子树
   // 2.当前节点的val小于p->val和q->val，去右子树
   // 3.返回当前节点
   class Solution {
   public:
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           // edge case
           if(root == nullptr) return nullptr;
           
           // normal case
           int v = root->val;
           if(v > max(p->val, q->val)){
               return lowestCommonAncestor(root->left, p, q);
           }else if(v < min(p->val, q->val)){
               return lowestCommonAncestor(root->right, p, q);
           }else{
               return root;
           }
       }
   };
   // time: O(N)
   // space: O(N) for recursion
   ```

2. 二叉树的最近公共祖先

   ```c++
   //solution1
   // key point: 分别递归的寻找p 和 q
   // 1. left, right同时存在， 当前节点就是最近公共祖先，向上返回
   // 2. left, right存在一个，即子树中找到了p 或 q，向上返回 p 或者 q
   // 3. left, right都不存在， 返回 nullptr, 表示子树不包含p 和 q
   class Solution {
   public:
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           // edge case
           if(root == nullptr) return nullptr;
           if(root == p || root == q) return root;
   		
           // normal case
           TreeNode* left = lowestCommonAncestor(root->left, p, q);
           TreeNode* right = lowestCommonAncestor(root->right, p, q);
   
           if(left == nullptr) return right;
           if(right == nullptr) return left;
           return root;
       }
   };
   // time: O(N)
   // space: O(N) for recursion
   
   // solution2
   // 分别保存p 和 q在树中的路径，然后返回最后的公共部分
   class Solution {
   public:
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           vector<TreeNode*> path_p, path_q;
           getPath(root, p, path_p);
           getPath(root, q, path_q);
           
           int cur = 0;
           while(cur < path_p.size() && cur < path_q.size()){
               if(path_p[cur] == path_q[cur]) ++cur;
               else break;
           }
           
           return path_p[cur - 1];
       }
   private:
       bool getPath(TreeNode* node, TreeNode* tar, vector<TreeNode*>& path){
           // edge case
           if(node == nullptr) return false;
           if(node == tar){
               path.push_back(node);
               return true;
           }
           
           // normal case
           path.push_back(node);
           
           if(getPath(node->left, tar, path)) return true;
           if(getPath(node->right, tar, path)) return true;
           
           path.pop_back();
           return false;
           
       }
   };
   // time: O(N)
   // space: O(N)
   ```



3. Minimum Deletions to Make Character Frequencies Unique 

   求使得字符串S中不存在频次相同的字符的最小删除次数

   ```c++
   // 对于只涉及'a'-'z'字符的字符串来说，用大小为26的vector保存次数比hash要方便
   class Solution {
   public:
       int minDeletions(string s) {
           vector<int> cnt(26, 0);
           for(char c : s) cnt[c - 'a']++;
           
           sort(cnt.begin(), cnt.end(), greater<int>());
           int keep = cnt[0];
           for(int i = 1; i < 26; ++i){
               if(cnt[i - 1] == 0 || cnt[i] == 0) break;
               int cur = min(cnt[i], cnt[i - 1] - 1);
               keep += cur;
               cnt[i] = cur;
           }
           return s.size() - keep;
       }
   };
   // time: O(N)
   // space: O(1)
   ```



4. 给定一个数组，每次可以移除其中一个元素或者移除一个回文子数组，求全部移除需要的最少次数

   ```c++
   // 整体思路是暴力 + 记忆化数组dp
   // 对于每个区间[i, j]
   // 1.一方面考虑分割[i, k], [k, j]
   // 2.另一方面考虑不分割，如果arr[i] == arr[j]，则可以直接考虑区间[i + 1, j - 1]，因为可以作为回文的一部分和后面的元素整体删除，如果arr[i] != arr[j],考虑区间[i, j - 1]和[i + 1, j]
   class Solution {
   public:
       int minimumMoves(vector<int>& arr) {
           int n = arr.size();
   
           dp.resize(n, vector<int>(n, -1));
           return getMoves(arr, 0, n - 1);
       }
   
   private:
       vector<vector<int>> dp;
       int getMoves(vector<int>& arr, int l, int r){
           // edge case
           if(l >= r) return 1;
           if(dp[l][r] != -1) return dp[l][r];
           
           // normal case
           // 1. split interval
           int ans = r - l + 1;
           for(int i = l; i < r; ++i){
               ans = min(ans, getMoves(arr, l, i) + getMoves(arr, i + 1, r));
           }
           // 2. take the interval as a whole
           if(arr[l] == arr[r]){
               ans = min(ans, getMoves(arr, l + 1, r - 1));
           }else{
               int moves = 1 + min(getMoves(arr, l + 1, r), getMoves(arr, l, r - 1));
               ans = min(ans, moves);
           }
   
           return dp[l][r] = ans;
       }
   };
   // time: O(N^3)
   // space: O(N^2)
   ```



5. 给定一个数组，每次可以从中取出最大的一个元素然后把它变成次大的元素，求需要多少步才能使数组中所有元素相等。

   ```c++
   // [4, 4, 3, 3, 3, 2, 2, 2, 1] -->(2 steps to transform the 4's) 
   // [3, 3, 3, 3, 3, 2, 2, 2, 1] -->(5 steps to transform the 3's)
   // [2, 2, 2, 2, 2, 2, 2, 2, 1] -->(8 steps to transform the 2's)
   // [1, 1, 1, 1, 1, 1, 1, 1, 1]
   
   int minStepsBalance(vector<int> arr){
       sort(arr.begin(), arr.end(), greater<int>());
       int n = arr.size(), ans = 0;
       for(int i = 1; i < n; ++i){
           if(arr[i] != arr[i - 1]) ans += i;
       }
       return ans;
   }
   // time: O(NlogN)
   // space: O(1)
   ```

   

6. 给定一个数组，返回数组中最大的一个数K，满足K和-K同时在数组中，要求K > 0，如果不存在返回0

   ```c++
   // Two sums的特例，即tar = 0的 two sums问题
   // solution1
   int largestNumber(vector<int> arr){
       int ans = 0;
       unordered_set<int> rec;
       for(int x : arr){
           if(rec.count(-x)) ans = max(ans, abs(x));
           rec.insert(x);
       }
       return ans;
   }
   // time: O(N)
   // space: O(N)
   
   // solution2
   int largestNumber(vector<int> arr){
       sort(arr.begin(), arr.end());
       int l = 0, r = arr.size() - 1;
       while(l < r){
           int sum = arr[l] + arr[r];
           
           if(sum == 0) return arr[r];
           else if(sum < 0) ++l;
           else --r;
       }
       return 0;
   }
   // time: O(NlogN)
   // space: O(1)
   ```

   

7. Maximum Length of a Concatenated String with Unique Characters

   给定一个字符串数组，求一个子序列，满足这个子序列组合成的新字符串不包含重复字符，返回这样一个子序列的最大长度

   ```c++
   class Solution {
   public:
       int maxLength(vector<string>& arr) {
           vector<bool> vis(26, false);
           int ans = 0;
           dfs(arr, 0, vis, ans);
           return ans;
       }
       
   private:
       void dfs(vector<string>& arr, int start, vector<bool>& vis, int& ans){
           // if(start >= arr.size()) return; --> bug! 这句代码不要加...
           
           int len = 0;
           for(int i = 0; i < 26; ++i){
               if(vis[i]) ++len;
           }
           ans = max(ans, len);
           
           for(int i = start; i < arr.size(); ++i){
               string& s = arr[i];
               if(!unique(s, vis)) continue;
               for(char c : s) vis[c - 'a'] = true;
               dfs(arr, i + 1, vis, ans);
               for(char c : s) vis[c - 'a'] = false;
           }
       }
       
       bool unique(string& s, vector<bool>& vis){
           vector<int> cnt(26, 0);
           for(char c : s){
               if(vis[c - 'a']) return false;
               cnt[c - 'a']++;
               if(cnt[c - 'a'] > 1) return false;
           }
           return true;
       }
   };
   
   // time: O(2^n)
   // space: O(n)
   ```



8. 给定数n，返回任意一个包含n个数且和为0的数组

   ```c++
   class Solution {
   public:
       vector<int> sumZero(int n) {
           vector<int> ans;
           if(n % 2) {
               ans.push_back(0);
               --n;
           }
           
           int base = 1;
           while(n){
               ans.push_back(base);
               ans.push_back(-base);
               ++base;
               n -= 2;
           }
           return ans;
           
       }
   };
   // time: O(N)
   // space: O(N)
   ```



9. 给定一个包含非负元素的数组，以及一个起始位置``start``。当位于位置 ``i ``时可以选择跳向左侧 ``i - arr[i]`` 或者右侧 ``i + arr[i]``处，问是否可以跳到某个元素为0的位置。

   ```c++
   class Solution {
   public:
       bool canReach(vector<int>& arr, int start) {
           int n = arr.size();
           vector<bool> vis(n, false);
   
           return dfs(arr, start, vis);
       }
       
   private:
       bool dfs(vector<int>& arr, int idx, vector<bool>& vis){
           if(idx < 0 || idx >= arr.size() || vis[idx]) return false;
           
           vis[idx] = true;
           if(arr[idx] == 0) return true;
           return dfs(arr, idx + arr[idx], vis) || dfs(arr, idx - arr[idx], vis);
       }
   };
   // time: O(N)
   // space: O(N)
   ```

   

10. 给定包含多端区间的数组，每个区间``[start, end]``代表会议时间段，计算至少需要多少间会议室才能满足这些会议的安排。

    ```c++
    // 模拟。
    // 对于一个新的会议来说，需要知道前面是否有已经结束的会议，这样就可以复用房间。所以用min heap维护会议的结束时间，每次插入新的会议前先pop出所有在此之前已经结束的会议。
    
    class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), cmp);
            int n = intervals.size(), ans = 0;
            priority_queue<int, vector<int>, greater<int>> que;
            for(int i = 0; i < n; ++i){
                while(que.size() && que.top() <= intervals[i][0]) que.pop();
                que.push(intervals[i][1]);
                int sz = que.size();
                ans = max(ans, sz);
            }
            return ans;
        }
    
    private:
        static bool cmp(const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        }
    };
    // time: O(NlogN)
    // space: O(N)
    ```



11. Count Good Nodes in Binary Tree

    Good Node的定义为满足从根节点到该节点的路径上的所有节点的值都小于等于该节点的值。

    ```c++
    class Solution {
    public:
        int goodNodes(TreeNode* root) {
            if(root == nullptr) return 0;
            
            int ans = 0;
            dfs(root, root->val, ans);
            return ans;
        }
        
    private:
        void dfs(TreeNode* node, int max_val, int& ans){
            if(node == nullptr) return;
            if(node->val >= max_val) ++ans;
            
            max_val = max(max_val, node->val);
            dfs(node->left, max_val, ans);
            dfs(node->right, max_val, ans);
        }
    };
    //time: O(N)
    // space: O(N) for recursion
    ```

    

12. 找到字符串中最大的字符，满足它的大小写形式均在字符串中

    ```c++
    char largestCharacter(string& str){
        vector<bool> uppercase(26, false);
        vector<bool> lowercase(26, false);
    
        for(char c : str){
            if(isupper(c)) uppercase[c - 'A'] = true;
            else lowercase[c - 'a'] = true;
        }
    
        for(int i = 25; i >= 0; --i){
            if(uppercase[i] && lowercase[i]) return i + 'A';
        }
        return -1;
    
    }
    // time: O(N)
// space: O(1)
    ```
    
    
    
13. [**03.2021**] 给定一个数组，求最大不相交的子数组的数目(长度固定为2)，满足这些子数组的各自元素的和相等

    例如 ``[10,1,3,1,2,2,1,0,4]``，包含三个子数组，``[1,3], [2,2], [0,4]``，满足和相等，所以返回  ``3``

    ```c++
    // 1. 求出所有长度为2的子数组的和
    // 2. 维护两个hash，一个记录相同和的子数组的个数，另一个记录构成该和的上一个子数组的位置
    int solve(const vector<int>& A){
        vector<int> sum;
        int n = A.size();
        for(int i = 0; i < n - 1; ++i){
            sum.push_back(A[i] + A[i + 1]);
        }
    
        unordered_map<int, int> sum2cnt, sum2idx;
        for(int i = 0; i < sum.size(); ++i){
            int v = sum[i];
            if(!sum2cnt.count(v) || sum2idx[v] < i - 1){
                sum2cnt[v]++;
                sum2idx[v] = i;
            }
        }
    
        int ans = 0;
        for(auto& p : sum2cnt){
            ans = max(ans, p.second);
        }
        return ans;
    }
    // time: O(N)
    // space: O(N)
    ```

    

14. [**03.2021**] 有 N 个工厂，工厂 ``i`` 排放的污染为 $P_i$ ，对工厂每加装一个净化器可以使得其污染减半，求要使得所有工厂的污染综合减少一般，至少需要加装多少净化器

    ```C++
    // 贪心，每次选取污染最大的工厂加装净化器
    int solve(const vector<int>& factories){
        priority_queue<double> que;
        for(int x : factories) que.push(x);
        
        double sum = accumulate(factories.begin(), factories.end(), 0.0);
        double tar = sum / 2.0, reduce_sum = 0.0, ans = 0;
        while(que.size() && reduce_sum < tar){
            int v = que.top();
            que.pop();
            reduce_sum += v / 2.0;
            que.push(v / 2.0);
            ++ans;
        }
        return ans;
    }
    // time: O(NlogN)
    // space: O(N)
    ```
    
    

15. [**03.2021**] 假定某车有 M 个特性，其中特性用 0 1 字符串表示，例如 “110”，表示该车具有特定0 和 1，但是不具有特征 2 。给定 N 辆车的特性，对于每辆车求和它相似的车的个数，相似定义为特性的差异不大于 1 。例如，“100” 和 “110” 相似，但是 “110” 和 “011” 不相似

    ```C++
    // solution1
    // 1.将字符串转换成数字
    // 2.异或判断是否相似
    vector<int> solve(const vector<string>& cars){
        int n = cars.size();
        vector<int> ans(n, 0), features(n, 0);
        for(int i = 0; i < n; ++i){
            int v = 0;
            for(char c : cars[i]) v = v * 2 + c - '0';
            features[i] = v;
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int v = features[i] ^ features[j];
                int diff = 0;
                while(v){
                    if(v & 1) ++diff;
                    v >>= 1;
                }
                if(diff <= 1) ++ans[i], ++ans[j];
            }
        }
        return ans;
    }
    // time: O(N^2*M)
    // space: O(N)
    
    // solution2
    // 1.对每个车的特征，添加其可以产生的其它相似车型，例如 "101" -> "#01", "1#1", "10#"
    // 2.hash统计，注意排重
    vector<int> solve(const vector<string>& cars){
        int n = cars.size();
        unordered_map<string, int> str2cnt;
        for(string s : cars){
            for(char &c : s){
                char rec = c;
                c = '#';
                str2cnt[s]++;
                c = rec;
            }
        }
    
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            string str = cars[i];
            for(char &c : str){
                char rec = c;
                c = '#';
                cnt += str2cnt[str];
                c = rec;
            }
            ans[i] = cnt - 3;
        }
        return ans;
    }
    // time: O(N * M)
    // space: O(N * M)
    ```

    
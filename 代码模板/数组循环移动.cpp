// leetcode-189. Rotate Array

// in-place solution1
// Beautiful!!!
/*
reference: https://leetcode.com/problems/rotate-array/discuss/54250/Easy-to-read-Java-solution

nums = "----->-->"; k =3
result = "-->----->";

reverse "----->-->" we can get "<--<-----"
reverse "<--" we can get "--><-----"
reverse "<-----" we can get "-->----->"
this visualization help me figure it out :)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0 || nums.size() <= 1) return;

        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// in-place solution2
// 证明++start是安全的：假设以start开始的循环路径中包含start + 1, 
// 那么同样的，以start + 1为起始的路径也一定包含start + 2，那么所有的元素就都在同一个循环路径上了，也就是只会遍历一次。
// 也就说如果会出现多条路径，那么start和start + 1一定不在同一条路径上。

// 注意cur_idx和cur_val的使用方法可以总结成前向替换的模板方法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0 || nums.size() <= 1) return;

        int start = 0, cur_idx = 0, cur_val = nums[0];
        int cnt = 0;
        k %= n;
        
        while(cnt < n){
            do{
                ++cnt;
                int dst_idx = (cur_idx + k) % n;
                int tmp = nums[dst_idx];
                nums[dst_idx] = cur_val;
                
                cur_val = tmp;
                cur_idx = dst_idx;
            }while(cur_idx != start);
            
            ++start;
            cur_idx = start;
            cur_val = nums[start];
        }
    }
};
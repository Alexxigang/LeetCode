### 题目描述  
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

 #### 思路：  
 首先一种迭代的解法，对于重复项的处理，最偷懒的方法是使用set，利用其自动去处重复项的机制，然后最后返回时再转回vector即可。由于是找递增序列
 ，所以我们需要对递归函数做一些修改，首先题目中说明了递归序列数字至少两个，所以只有当当前子序列个数大于等于2时，
 才加入结果。然后就是要递增，如果之前的数字大于当前的数字，那么跳过这种情况，继续循环，参见代码如下：  
 
          class Solution {
      public:
          vector<vector<int>> findSubsequences(vector<int>& nums) {
              vector<int> out;
              set<vector<int> > res;
              helper(nums,0,out,res);
              return vector<vector<int> >(res.begin(),res.end());
          }

          void helper(vector<int> &nums,int start,vector<int> &out,set<vector<int> > &res){
              if(out.size()>=2)res.insert(out);
              for(int i=start;i<nums.size();i++){
                  if(!out.empty()&&out.back()>nums[i]) continue;
                  out.push_back(nums[i]);
                  helper(nums,i+1,out,res);
                  out.pop_back();
              }
          }
      };
      
      

class Solution {
//空间复杂度为n的解法：利用hash_set存储出现过的数字，然后从1开始如果hash_set中没有该数，则返回该值，否则返回最大值+1
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0)continue;
            s.insert(nums[i]);
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(!s.count(i+1))return i+1;
        }
        return mx+1;
    }
};

class Solution {
//空间复杂度为O(1)的方法：尽量将数组索引的的值对应为索引+1，把1放在数组第一个位置nums[0]，2放在第二个位置nums[1]，即需要把nums[i]放在
nums[nums[i] - 1]上，那么我们遍历整个数组，如果nums[i] != i + 1, 而nums[i]为整数且不大于n，另外nums[i]不等于nums[nums[i] - 1]的话，我们将两者位置
调换，如果不满足上述条件直接跳过，最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};

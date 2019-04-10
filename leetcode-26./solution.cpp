class Solution {
//解题思路：
//类似于27，利用一堆快慢指针，慢指针i从0开始，快指针j从1开始，如果快指针指向值与慢指针值相等，则快指针后移，知道与慢指针所指不等，然后将快指针所指的值赋值
//给慢指针i的下一个位置，然后再比较i和j所指位置的值，知道j到达末尾为止

public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]==nums[i]){
                continue;
            }
            nums[++i]=nums[j];
        }
        return i+1;
    }
};

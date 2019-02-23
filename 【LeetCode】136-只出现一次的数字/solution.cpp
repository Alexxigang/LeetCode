class Solution {
/*
方法：把数组中所有的数字都异或起来，则每对相同的数字都会得0，然后最后剩下来的数字就是那个只有1次的数字。
*/
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};

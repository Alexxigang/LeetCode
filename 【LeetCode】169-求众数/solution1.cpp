class Solution {
/*
方法：遍历数组，将数组的每一个元素从第一位到第32位也一次遍历，每一位为1的个数如果多余为0的个数，则res的对应为为1否则为0
*/
public:
    int majorityElement(vector<int>& nums) {
       int res=0,len=nums.size();
        for(int i=0;i<32;i++){
            int ones=0,zeros=0;
            for(int num:nums){
                if((ones>len/2)||(zeros>len/2)){
                    break;
                }
                if((num&(1<<i))!=0)ones++;
                else zeros++;
            }
            if(ones>zeros)res|=(1<<i);
        }
        return res;
    }
};

class Solution {
/*
思路：利用两个数组，一个数组计算某一索引对应的前面的乘积，一个数组计算其后面的乘积，最后两者相乘
*/
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> before(n,1),after(n,1),res(n);
        for(int i=0;i<n-1;++i){
            before[i+1]=before[i]*nums[i];
        }
        for(int i=n-1;i>0;--i){
            after[i-1]=after[i]*nums[i];
        }
        for(int i=0;i<n;i++){
            res[i]=before[i]*after[i];
        }
        return res;
    }
};

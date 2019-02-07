class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN;
        int maxSub=0;
        for(int i=0;i<nums.size();i++){
            maxSub+=nums[i];
            if(maxSub>res){
                res=maxSub;
            }
            if(maxSub<0){
                maxSub=0;
            }
        }
        return res;
    }
};

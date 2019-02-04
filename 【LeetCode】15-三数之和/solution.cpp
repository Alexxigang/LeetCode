class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        if(nums.empty()||nums.back()<0||nums.front()>0)return result;
        for(int i=0;i<len;i++){
            if(nums[i]>0)break;
            if(i>0&&nums[i]==nums[i-1])continue;
            int target=0-nums[i];
            int l=i+1,r=len-1;
            while(l<r){
                vector<int> temp;
                if(nums[l]+nums[r]==target){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    
                    result.push_back(temp);
                    while(l<r&&nums[l]==nums[l+1])l++;
                    while(l<r&&nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }else if(nums[l]+nums[r]<target){
                    l++;
                }else{r--;}
            }
        }
        return result;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closest=nums[0]+nums[1]+nums[2];
        int diff=abs(closest-target);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                int newdiff=abs(sum-target);
                if(diff>newdiff){
                    diff=newdiff;
                    closest=sum;
                }
                if(sum<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return closest;
    }
};

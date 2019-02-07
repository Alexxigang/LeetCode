class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int start=0;
        vector<vector<int> >result;
        permuteCore(nums,start,result);
        return result;
    }
    
private:
    void permuteCore(vector<int>& nums,int start,vector<vector<int> >& result){
        if(start>=nums.size())result.push_back(nums);
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            permuteCore(nums,start+1,result);
            swap(nums[start],nums[i]);
        }
    }
};

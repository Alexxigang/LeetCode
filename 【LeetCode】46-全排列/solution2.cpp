class Solution {
//这里是每次交换num里面的两个数字，经过递归可以生成所有的排列情况。
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int> > res;
        permuteCore(nums,0,res);
        return res;
    }
    
private:
    void permuteCore(vector<int> &nums,int start,vector<vector<int>> &res){
        if(start>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            permuteCore(nums,start+1,res);
            swap(nums[start],nums[i]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len=nums.size();
        int n=1<<len;//求出子集数，2的n次方
        vector<vector<int>> result;
        for(int index=0;index<n;index++){
            vector<int> temp=convertIntToSet(nums,index);
            result.push_back(temp);
        }
        return result;
    }
    
private:
    vector<int> convertIntToSet(vector<int> &nums, int k) {
            int index=0;
            vector<int> temp;
            for(int i=k;i>0;i>>=1){
                if(i&1==1){
                    temp.push_back(nums[index]);
                }
                index++;
            }
        return temp;
    }
};

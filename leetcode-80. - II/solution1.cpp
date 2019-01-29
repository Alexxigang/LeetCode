class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int time=1;
        int k=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]==nums[j-1]){
                if(time<2){//记录出现相同次数
                    nums[k++]=nums[j];
                    time++;
                }
            }else{
                time=1;
                nums[k++]=nums[j];
            }
        }
        return k;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        //保证k指针指向的始终是正确的符合要求的数字
        int k=0,i=0;
        for(int i=0;i<nums.size();i++){
            if(k<2||nums[i]!=nums[k-2]){
                if(i!=k){
                    nums[k++]=nums[i];
                }else{
                    k++;
                }
            }
        }
        return k;
    }
};

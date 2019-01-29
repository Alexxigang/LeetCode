class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==val){
                nums[i]=nums[n-1];//将n-1的位置的元素赋值给当前元素
                n--;//n往前移动
                //如果n-1的位置的元素也等于val，因为i此时没有增一，所以下次循环还是会发现，再接着讲向前移动之后的n-1位置的元素赋值给当前元素
            }else{
                i++;
            }
        }
        return n;
    }
};

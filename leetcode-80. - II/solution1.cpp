class Solution {
//题解思路：利用两个指针从索引1开始遍历，判断j位置和前面一个位置的值是否相同，再判断相同次数是否超过2，如果未超过2，则将j上的值赋值给k上，k++后移，time
//也+1，如果超过2，则k不动，j++后移；如果j位置和前面一个位置的值不相同，则将time赋值为1，并且将j上的值赋值给k上，k++后移
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

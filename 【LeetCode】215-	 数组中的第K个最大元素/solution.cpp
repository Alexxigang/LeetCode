class Solution {
/*
方法：利用快排方法，取最左边的为基准，将大于该基准的排在该基准前面，小于该基准的排在后面，如果最后改基准的位置刚好在第k个，
则返回该基准，如果该基准位置大于k，则在更新右边界，在基准前面中快排，知道寻找到结果
快速排序Quick Sort的思想，这里排序的方向是从大往小排。对快排不熟悉的童鞋们随意上网搜些帖子看下吧，多如牛毛啊，总有一款适合你。核心思想是每次都要先找
一个中枢点Pivot，然后遍历其他所有的数字，像这道题从大往小排的话，就把大于中枢点的数字放到左半边，把小于中枢点的放在右半边，这样中枢点是整个数组中第几
大的数字就确定了，虽然左右两部分各自不一定是完全有序的，但是并不影响本题要求的结果，因为左半部分的所有值都大于右半部分的任意值，所以我们求出中枢点的位
置，如果正好是k-1，那么直接返回该位置上的数字；如果大于k-1，说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；反之则更新右半部分，求中枢点的
位置
*/
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        if(len==1){
            return nums[0];
        }
        int left=0,right=len-1;
        while(true){
            int pos=partition(nums,left,right);
            if(pos==k-1){
                return nums[pos];
            }
            if(pos>k-1){
                right=pos-1;
                
            }
            else{
                left=pos+1;
            }
        }

    }
    
private:
    int partition(vector<int> & nums,int left,int right){
        int privot=nums[left],l=left+1,r=right;
        while(l<=r){
            if(nums[l]<privot&&nums[r]>privot){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]>=privot){
                l++;
            }
            if(nums[r]<=privot){
                r--;
            }
        }
        swap(nums[left],nums[r]);
        return r;
    }
};

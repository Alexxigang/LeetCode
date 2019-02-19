class Solution {
/*
因为是数组，所以合并先从后往前遍历，较大的放在nums1数组末尾，然后更新末尾索引k和对应大的数组的索引
*/
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1;
        int i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums2[j];
                j--;k--;
            }
            else{
                nums1[k]=nums1[i];
                i--;k--;
            }
        }
            while(j>=0){
                nums1[k]=nums2[j];
                j--;k--;
        }
    }
};

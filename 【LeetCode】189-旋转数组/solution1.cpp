class Solution {
//思路：先把数组前n-k个元素翻转，然后把后面的元素翻转，最后整体再翻转一次
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0)
            return;
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

class Solution {
//利用STL的push_back和erase方法，但是超时了
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0)
            return;
        int n=nums.size();
        k=k%n;
        for(int i=0;i<n-k;i++){
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

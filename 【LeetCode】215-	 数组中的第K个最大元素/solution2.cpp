/*方法一：
给数组排序，然后求可以得到第k大的数字。先看一种利用c++的STL中的集成的排序方法，不用我们自己实现
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

/*
方法二：利用了priority_queue的自动排序的特性，跟上面的解法思路上没有什么区别，当然我们也可以换成multiset来做
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};

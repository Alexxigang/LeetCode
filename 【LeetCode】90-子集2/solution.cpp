class Solution {
/*
非递归的解法,对于题目中给的例子[1,2,3]来说，最开始是空集，那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，下面我们来处理2，我们在
之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], 
[1, 2, 3], 再加上之前的子集就是所有的子集合了
*/
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()) return {};
        int len=nums.size();
        vector<vector<int> > res(1);
        sort(nums.begin(),nums.end());
        int last=nums[0];int size=1;
        for(int i=0;i<len;i++){
            if(last!=nums[i]){
                last=nums[i];
                size=res.size();
                
            }
            int newSize=res.size();
            for(int j=newSize-size;j<newSize;j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
            
        }
        return res;
    }
};

class Solution {
/*
方法：利用哈希表，遍历数组，如果某元素不在哈希表中，则将其放在哈希表中，如果发现已经存在哈希表中，则返回false
*/
public:
    bool containsDuplicate(vector<int>& nums) {
        int len =nums.size();
        if(len<2){
            return false;
        }
        if(len==2){
            if(nums[0]==nums[1]){
                return true;
            }else return false;
        }
        unordered_map<int,int> map;
        for(int i=0;i<len;i++){
            if(map.find(nums[i])!=map.end())return true;
            map[nums[i]]++;
        }
        return false;
    }
};

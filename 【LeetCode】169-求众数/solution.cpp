class Solution {
/*
思路：
先将第一个元素置为res,然后往后遍历数组，如果遇到相同的则计数器加一，否则减一，如果计数器为0，则将下一个与元素置为res，最终遍历结束时的res即为要求的结果，
因为数组中必定存在一个出现次数超过一半的元素，所以该方法一定有效
为啥遇到不同的要计数器减1呢，为啥减到0了又要更换候选者呢？首先是有那个强大的前提存在，一定会有一个出现超过半数的数字存在，那么如果计数器减到0了话，说明目
前不是候选者数字的个数已经跟候选者的出现个数相同了，那么这个候选者已经很weak，不一定能出现超过半数，我们选择更换当前的候选者。那有可能
你会有疑问，那万一后面又大量的出现了之前的候选者怎么办，不需要担心，如果之前的候选者在后面大量出现的话，其又会重新变为候选者，直到最终验证成为正确的众数
*/
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};

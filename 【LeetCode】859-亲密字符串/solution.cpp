class Solution {
//先判断两个长度如果不同直接返回false，然后如果两个字符串相等并且有重复的则返回true，其他情况，利用diff数组存储A，B不相等的字符，如果只有两个不相等的字符并且是
//相邻的，则返回true
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())return false;
        if(A==B&&unordered_set<char>(A.begin(),A.end()).size()<A.size())return true;
        vector<int> diff;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i])diff.push_back(i);
        }
        return diff.size()==2&&A[diff[0]]==B[diff[1]]&&A[diff[1]]==B[diff[0]];
    }
};

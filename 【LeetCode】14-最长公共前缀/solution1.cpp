class Solution {
//水平扫描。 我们从前往后枚举字符串的每一列，先比较每个字符串相同列上的字符（即不同字符串相同下标的字符）然后再进行对下一列的比较。
//执行用时: 4 ms, 在Longest Common Prefix的C++提交中击败了99.97% 的用户
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];//从第一个字符串的第一个字符开始判断
            for(int j=1;j<strs.size();j++){
                if(i==strs[j].size()||strs[j][i]!=c){//循环结束条件：判断到达了某一字符串的最长长度或者某一字符串的对应字符与第一个字符串对应字符不相等
                    return strs[j].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

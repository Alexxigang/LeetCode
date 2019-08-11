用递归 Recursion 来解，我们需要建立一个字典，用来保存每个数字所代表的字符串，然后我们还需要一个变量 level，记录当前生成的字符串的字符个数。在递归函数中
我们首先判断 level，如果跟 digits 中数字的个数相等了，我们将当前的组合加入结果 res 中，然后返回。
否则我们通过 digits 中的数字到 dict 中取出字符串，然后遍历这个取出的字符串，将每个字符都加到当前的组合后面，并调用递归函数即可，参见代码如下：


```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return{};
        vector<string> res;
        vector<string> dict={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits,dict,0,"",res);
        return res;
    }
    
    void letterCombinationsDFS(string &digits,vector<string> &dict,int level,string out,vector<string> &res){
        if(level==digits.size()){
            res.push_back(out);
            return ;
        }
        string str=dict[digits[level]-'0'];
        for(int i=0;i<str.size();i++){
            letterCombinationsDFS(digits,dict,level+1,out+str[i],res);
        }
    }
};

```

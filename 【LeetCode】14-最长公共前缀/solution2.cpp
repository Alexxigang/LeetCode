class Solution {
    /*
    分治
思路

这个算法的思路来自于LCP操作的结合律。 我们可以发现：LCP（s1....sn）=LCP(LCP(s1....sk),LCP(sk-1....sn)),将原问题LCP（si...sj）转换为
LCP(Si...Smid)
,LCP(Smid+1,Sj)两个子问题从头到尾挨个比较 lcpLeft 与 lcpRight 中的字符，直到不能再匹配为止。 计算所得的 lcpLeft 与 lcpRight 最长
公共前缀就是原问题的解 LCP

    */
//速度比较慢....
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        return longestCommonPrefixFromLeftToRight(strs,0,strs.size()-1);
    }
    
    string longestCommonPrefixFromLeftToRight(vector<string> strs,int left,int right){
        if(left==right){
            return strs[left];
        }
        else{
            int mid=(left+right)/2;
            string longestLeftStr=longestCommonPrefixFromLeftToRight(strs,left,mid);
            string longestRightStr=longestCommonPrefixFromLeftToRight(strs,mid+1,right);
            return commonPrefix(longestLeftStr,longestRightStr);
        }
        }
private:
    string commonPrefix(string str1,string str2){
        int len=min(str1.size(),str2.size());
        for(int i=0;i<len;i++){
            if(str1[i]!=str2[i]){
                return str1.substr(0,i);
            }
        }
        return str1.substr(0,len);
    }
    
};

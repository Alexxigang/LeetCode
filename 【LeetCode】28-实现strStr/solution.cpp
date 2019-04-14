class Solution {
//这里就是普通的遍历，为了节省不必要的时间，母字符串遍历到m-n即后边剩余的长度和子字符串相等的时候停止遍历
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(m==0)return 0;
        for(int i=0;i<=n-m;i++){
            if(needle[0]==haystack[i]){
                int j=0,k=0;
                for(j=i+1,k=1;k<m;j++,k++){
                    if(haystack[j]!=needle[k]){
                        break;
                    }
                }
                if(k==m){
                    return i;
                }
            }
        }
        return -1;
    }
};

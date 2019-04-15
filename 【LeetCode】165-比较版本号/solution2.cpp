class Solution {
//思路和方法一一样，不过是自己实现字符串转化为数字的方法
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0,p=0,q=0;
        string v1,v2;
        while(i<n||j<m){
            while(i<n&&version1[i]!='.'){
                p=p*10+(version1[i++]-'0');
            }
            while(j<m&&version2[j]!='.'){
                q=q*10+(version2[j++]-'0');
            }
            
            if(p<q)return -1;
            if(p>q)return 1;
            //v1.clear();v2.clear();
            p=0,q=0;
            i++,j++;
        }
        return 0;
    }
};

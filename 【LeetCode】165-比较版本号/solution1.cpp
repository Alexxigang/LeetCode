class Solution {
//在遇到小数点之前把前面的字符串转化成数字然后进行比较，利用函数atoi()将字符串转换为数字
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0,p=0,q=0;
        string v1,v2;
        while(i<n||j<m){
            while(i<n&&version1[i]!='.'){
                v1.push_back(version1[i++]);
            }
            while(j<m&&version2[j]!='.')v2.push_back(version2[j++]);
            p=atoi(v1.c_str());
            q=atoi(v2.c_str());
            if(p<q)return -1;
            if(p>q)return 1;
            v1.clear();v2.clear();
            i++,j++;
        }
        return 0;
    }
};

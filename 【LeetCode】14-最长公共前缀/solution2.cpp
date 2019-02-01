class Solution {
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

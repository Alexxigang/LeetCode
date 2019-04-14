class Solution {
//先去掉头尾的空格，然后用count计数，遇到空格就清零
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int left=0,right=len-1;
        while(s[left]==' ')left++;
        while(s[right]==' ')right--;
        int count=0;
        for(int i=left;i<=right;i++){
            if(s[i]==' ')count=0;
            else{
                count++;
            }
        }
        return count;
    }
};

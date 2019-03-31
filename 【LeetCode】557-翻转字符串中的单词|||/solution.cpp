class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            while(s[j]!=' '&&j<n){
                j++;
            }
            int k=j-1;
            while(i<k){
                char temp=s[i];
                s[i]=s[k];
                s[k]=temp;
                i++;k--;
            }
            i=j+1;
            j++;
        }
        return s;
    }
};

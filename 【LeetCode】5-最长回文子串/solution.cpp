class Solution {
/*
中心扩展算法
事实上，只需使用恒定的空间，我们就可以在 O(n^2)O(n2) 的时间内解决这个问题。

我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 1 个这样的中心。

你可能会问，为什么会是 2n - 1 个，而不是 nn 个中心？原因在于所含字母数为偶数的回文的中心可以处于
两字母之间（例如 'abba' 的中心在两个‘b’ 之间）。
*/
public:
    string longestPalindrome(string s) {
        if(s.size()<=0){
            return "";
        }
        if(s.size()==1){
            return s;
        }
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            int Len1=expandAroundCenter(s,i,i);//以i为中心向外扩展判断是否为子串
            int Len2=expandAroundCenter(s,i,i+1);//以i,i+1位置的数值为中心向外扩展判断是否为子串
            int Len=max(Len1,Len2);
            if(Len>end-start){
                start=i-(Len-1)/2;
                end=i+Len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
    
private:
    int  expandAroundCenter(string s,int left,int right){
        int L=left,R=right;
        while(L>=0&&R<s.size()&&s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
};

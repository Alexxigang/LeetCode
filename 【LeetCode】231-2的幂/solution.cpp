//方法一
class Solution {
public:
    bool isPowerOfTwo(int n) {
        //int sum=0;
        //int m=n-1;
        return(n>0)&&(!(n&(n-1)));
    }
};

//方法二
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int sum=0;
        while(n>0){
            if(n&1==1){
                sum++;
            }
            n=n>>1;
        }
        if(sum==1){
            return true;
        }else
            return false;
    }
};

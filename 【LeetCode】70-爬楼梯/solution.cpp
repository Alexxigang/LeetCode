class Solution {
/*
非递归形式
*/
public:
    int climbStairs(int n) {
        if(n<3)return n;
        int first=1,second=2,third=3;
        for(int i=2;i<n-1;i++){
            first=second;
            second=third;
            third=first+second;
        }
        return third;
    }
};

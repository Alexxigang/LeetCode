class Solution {
/*
思路二：利用组合数，这个问题背后的数学模型，其实就是机器人总共走m+n-2步，
其中m-1步往下走，n-1步往右走，本质上就是一个组合问题，也就是从m+n-2个不同元素中每次取出m-1个元素的组合数。根据组合的计算公式，我们可以写代码来求解即可，
相当于C(small-1)/m+n-2
*/
public:
    int uniquePaths(int m, int n) {
        int small=m<n?m:n;
        double dom=1,dedom=1;
        for(int i=1;i<=small-1;i++){
            dedom*=i;
            dom*=m+n-1-i;
        }
        return (int)(dom/dedom);
    }
};

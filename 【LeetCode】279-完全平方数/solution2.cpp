class Solution {
/*
利用动态规划：我们建立一个长度为n+1的一维dp数组，将第一个值初始化为0，其余值都初始化为INT_MAX, i从0循环到n，j从1循环到i+j*j <= n的位置，然后每次更新
dp[i+j*j]的值，动态更新dp数组，其中dp[i]表示正整数i能少能由多个完全平方数组成，那么我们求n，就是返回dp[n]即可，也就是dp数组的最后一个数字。需要注意的
是这里的写法，i必须从0开始，j必须从1开始
*/
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
            //dp[i+j*j]就表示i+j*j这个数包含的最小完全平方数的个数，因为j*j也是一个完全平方数，所以dp[i+j*j]的值就是dp[i]的值加一
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

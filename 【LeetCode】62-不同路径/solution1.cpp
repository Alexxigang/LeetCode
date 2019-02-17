class Solution {
/*
思路：利用动态规划
*/
public:
    int uniquePaths(int m, int n) {
       vector<int> path(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                path[j]+=path[j-1];
            }
        }
        return path[n-1];
    }
};

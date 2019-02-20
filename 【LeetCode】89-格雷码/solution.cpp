class Solution {
/*
利用镜像原理：0  0  00  00  000
             1  1  01  01  001
                1  11  11  011
                0  10  10  010
                       10  110
                       11  111
                       01  101
                       00  100
*/
public:
    vector<int> grayCode(int n) {
        vector<int> res={0};
        for(int i=0;i<n;i++){
            int size=res.size();
            for(int j=size-1;j>=0;j--){
                res.push_back(res[j]|(1<<i));
            }
        }
        return res;
    }
};

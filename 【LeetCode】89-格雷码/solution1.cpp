class Solution {
    /*
    Int    Grey Code    Binary
 　　  000        000
 　　  001        001
  　 　011        010
  　 　010        011
  　 　110        100
  　 　111        101
  　 　101        110
  　　 100        111
    */
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0;i<pow(2,n);i++){
            res.push_back((i>>1)^i);
        }
        return res;
    }
};

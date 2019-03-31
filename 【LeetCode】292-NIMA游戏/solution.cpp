class Solution {
/*
经举例总结规律得4的倍数会输
*/
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n%4==0)
            return false;
        return true;
    }
};

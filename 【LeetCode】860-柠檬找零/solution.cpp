class Solution {
//定义两个变量：five，ten,初始为0，然后遍历bills，如果为5，则five++，如果是10，则five--(因为要用5找零），如果是20，且有10块的，则用一张10块的和一张5块的
//所以，ten--,five--，否则直接用3张5块的找零
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int bill :bills){
            if(bill==5){
                ++five;
            }else if(bill==10){
                --five;
                ++ten;
            }else if(ten>0){
                ten--;five--;
            }else{
                five-=3;
            }
            if(five<0)return false;
        }
        return true;
    }
};

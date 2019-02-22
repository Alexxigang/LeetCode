class Solution {
/*
连续的峰和谷
*/
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0){
            return 0;
        }
        int maxprofit=0,valley=prices[0],peak=prices[0];
        int i=0;
        while(i<len-1){
            while(i<len-1&&prices[i]>=prices[i+1]){
                i++;
            }
            valley=prices[i];
            while(i<len-1&&prices[i]<=prices[i+1]){
                i++;
            }
            peak=prices[i];
            maxprofit+=peak-valley;
        }
        return maxprofit;
    }
};

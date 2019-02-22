class Solution {
/*
遵循 方法二 的本身使用的逻辑，但有一些轻微的变化。在这种情况下，我们可以简单地继续在斜坡上爬升并持续增加从连续交易中获得的利润，而不是在谷之后寻找每个峰
值。最后，我们将有效地使用峰值和谷值，但我们不需要跟踪峰值和谷值对应的成本以及最大利润，但我们可以直接继续增加加数组的连续数字之间的差值，如果第二个数字
大于第一个数字，我们获得的总和将是最大利润
*/
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0){
            return 0;
        }
        int maxprofit=0,valley=prices[0],peak=prices[0];
        int i=0;
        for(int i=1;i<len;i++){
            if(prices[i]>prices[i-1]){
                maxprofit+=prices[i]-prices[i-1];
            }
        }
        return maxprofit;
    }
};

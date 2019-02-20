class Solution {
/*
最简单的是暴力二次遍历，本次代码使用效率比较高的方法：
找到最小的谷之后的最大的峰。 我们可以维持两个变量——minprice 和 maxprofit，它们分别对应迄今为止所得到的最小的谷值和最大的利润
（卖出价格与最低价格之间的最大差值）。
*/
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            else if((prices[i]-minPrice)>maxProfit){
                maxProfit=prices[i]-minPrice;
            }
        }
        return maxProfit;
    }
};

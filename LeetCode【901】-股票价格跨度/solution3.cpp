class StockSpanner {
/*
思路：

动态规划。我们用数组stock代表每天股票的价格，直接遍历不是最好的方法，在第i次调用函数next的时候，我们考虑第i-1天的股票价格：若第i-1天股票价格大于第i天
，我们应该返回答案1；若第i-1天的股票价格小于等于第i天，那么第i-1天左边连续小于等于i-1天的股票价格显然也小于等于第i天的股票价格，如果我们用spanner数组
表示每次next函数输出的结果，那么我们只需要从第i-1天开始，跳过spanner[i-1]天，再继续检查第i-spanner[i-1]天的股票价格即可。

这个过程也可以用单调栈实现，这道题的本质是寻找每个数左边第一个比它严格大的数字，故可以采用单调栈的思想，维护一个单调递减的栈，栈中存放数字的下标，每次
新加入一个数字时，若栈顶小于等于当前数字，则出栈直到栈空或者栈顶严格大于当前数字，最终栈顶距离新插入数字的下标的距离就是答案，然后将新数字压栈。

代码还可以进一步优化，当第i次调用next函数的时候，前i-1天小于第i天的股票价格就没必要保存了，我们直接在单调栈中，既保存股票价格又保存股票价格的时间跨度
即可。

时间复杂度O(N)O(N)

空间复杂度O(N)O(N)

*/
public:
    vector<int> prices;
    vector<int> res;
    StockSpanner() {
        prices.clear();
        res.clear();
    }
    
    int next(int price) {
        int tail=prices.size()-1;
        int ans=1;
        while(tail>=0&&price>=prices[tail]){
            int tmp=res[tail];
            ans+=tmp;
            tail=tail-tmp;
        }
        prices.push_back(price);
        res.push_back(ans);
        return ans;
    }
    

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

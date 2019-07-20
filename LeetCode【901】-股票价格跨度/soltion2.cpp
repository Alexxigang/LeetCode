//超出时间限制
class StockSpanner {
public:
    int idx;
    vector<int> dp;
    stack<pair<int,int>> sk;
    StockSpanner() {
        idx=0;
        dp.clear();
        while(!sk.empty())sk.pop();
    }
    
    int next(int price) {
        int result=0;
        if(sk.empty()||(!sk.empty()&&sk.top().second>price))dp.push_back(1);
        else{
            pair<int,int> p=sk.top(),pre;
            while(p.second<=price){
                pre=p;
                sk.pop();
                if(sk.empty())break;
                p=sk.top();
            }
            dp.push_back(idx-pre.first+dp[pre.first]);
            
        }
        sk.push(make_pair(idx,price));
        idx++;
        return dp[idx-1];
    }
    

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

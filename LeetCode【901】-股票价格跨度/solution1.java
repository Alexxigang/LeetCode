class StockSpanner {
    //思路：记载2个ArrayList，一个是输入参数price；另一个是next的结果；这两个组合起来相当于一个跳表
    //每个都是结果对应的范围内的最大数，如果比上个数少，那就是1，如果比上个数大，分2种情况，比如前一个小，那就是+1，如果大，进一步纳入范围
    List<Integer> prices;
    List<Integer> results;

    public StockSpanner() {
        prices = new ArrayList<>();
        results = new ArrayList<>();
    }
    
    public int next(int price) {
        int tail = prices.size()-1;
        int ret = 1;
        while (tail >= 0 && price >= prices.get(tail)) {
            int rt = results.get(tail);
            ret += rt;
            tail = tail - rt;
        }
        prices.add(price);
        results.add(ret);
        return ret;
    }
}

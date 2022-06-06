int maximumProfit(vector<int> &prices){
   // At worst we can have 0 profit. So lets think we have 0 profit in starting
        int n = prices.size();
        int profit = 0;
        int buy = prices[0];
        for(int i = 1 ; i <n ; i++){
            int currentPrice = prices[i];
            int curProfit = currentPrice - buy;
            if(profit < curProfit){
                profit = curProfit;
            }
            buy  = min(buy, currentPrice);
        }
        return profit;
}
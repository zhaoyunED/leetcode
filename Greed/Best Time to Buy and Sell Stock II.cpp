Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


//典型的贪心算法题目

int maxProfit(vector<int>& prices)
{
        int result =0;
        int n =prices.size();
        if(n<=0)
            return result;
        int min =prices[0];    
            
        for(int i=1;i<n;i++)
        {
            if(prices[i]>min)
                result += prices[i]-min; //只要涨了就卖掉
            min = prices[i]; //重新设置低价
        }
        return result;
}


//或者更简单粗暴的代码
//直接把相邻的正差值  全部加起来 就行
public int maxProfit(int[] prices)
{
        int total = 0;
		for (int i=0; i< prices.length-1; i++) {
			if (prices[i+1]>prices[i]) total += prices[i+1]-prices[i];
		}

		return total;
}

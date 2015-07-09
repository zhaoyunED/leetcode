Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).





//方法1  动规
//space complexity can be O(n) because this DP only uses the result from last step.
int maxProfit(vector<int> &prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; // number of max transation allowed
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
}


// 类似 single number 2 题目
public int maxProfit(int[] prices)
{
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
}



//从两边 分别遍历一次
int maxProfit(vector<int> &prices)
{
         int maxPro = 0;
        int num = prices.size();
        
        if(1 >= num)
          return 0;
        if(2 == num)
        {
            if(prices[1]>prices[0])
                return prices[1]-prices[0];
            else
                return 0;
        }
        
        vector<int> pros(num,0);
        vector<int> futurepros(num,0);
        
        int lowprice =prices[0];
        
        for(int i=1 ;i<=num-1 ;i++)
        {
            
           if(prices[i]<lowprice)
           {
                lowprice = prices[i];
                pros[i] = pros[i-1];
           }else
           {
                if(prices[i] - lowprice >pros[i-1])
                {
                    pros[i] = prices[i] - lowprice;
                }else
                    pros[i] = pros[i-1];
                   
           }
        }
        
        int highprice =prices[num-1];
        
        
            
            for(int j=num-2; j>=0; j--)
            {
                if(prices[j]>highprice)
                {
                    highprice = prices[j];
                    futurepros[j] = futurepros[j+1];
                }else
                {
                    if(highprice-prices[j] >futurepros[j+1])
                    {
                         futurepros[j] = highprice - prices[j] ;
                    }else
                         futurepros[j] = futurepros[j+1];
                }
				
				if(futurepros[j] +pros[j] >maxPro)
					 maxPro = futurepros[j] +pros[j];
				                
            }
        
        return maxPro;        
}
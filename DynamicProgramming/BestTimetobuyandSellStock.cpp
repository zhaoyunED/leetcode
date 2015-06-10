Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.





//����1
int maxProfit(vector<int> &prices) 
{
    if(prices.size() <=0) return 0;
        int min=prices[0];
        int maxPro=0;
        for(int i=1 ;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min = prices[i];
                continue;
            }
            maxPro = (prices[i]-min) >maxPro ? (prices[i]-min) :maxPro;
        }
    return maxPro;
}

//����2 ����maxSumArray ������һ����  
//�����Ĳ�ֵ���� ��ת�����˺���maxSumArrayһ����������
int maxProfit(vector<int> &prices) 
{
        if(prices.size() <=0) return 0;
        
        int sum =0;
        int result=0;
        for(int i=1;i<prices.size();i++)
        {
            sum+=prices[i]-prices[i-1];
            if(sum<0) sum=0;
            result = max(sum,result);
        }
        
        return result;
}



There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

//方法1
int candy(vector<int>& ratings) {
        int nCandyCnt = 0;///Total candies
    int nSeqLen = 0;  /// Continuous ratings descending sequence length
    int nPreCanCnt = 1; /// Previous child's candy count
    int nMaxCntInSeq = nPreCanCnt;
    if(ratings.begin() != ratings.end())
    {
        nCandyCnt++;//Counting the first child's candy.
        for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            // if r[k]>r[k+1]>r[k+2]...>r[k+n],r[k+n]<=r[k+n+1],
            // r[i] needs n-(i-k)+(Pre's) candies(k<i<k+n)
            // But if possible, we can allocate one candy to the child,
            // and with the sequence extends, add the child's candy by one
            // until the child's candy reaches that of the prev's.
            // Then increase the pre's candy as well.

            // if r[k] < r[k+1], r[k+1] needs one more candy than r[k]
            // 
            if(*i < *(i-1))
            {
                //Now we are in a sequence
                nSeqLen++;
                if(nMaxCntInSeq == nSeqLen)
                {
                    //The first child in the sequence has the same candy as the prev
                    //The prev should be included in the sequence.
                    nSeqLen++;
                }
                nCandyCnt+= nSeqLen;
                nPreCanCnt = 1;
            }
            else
            {
                if(*i > *(i-1))
                { 
                    nPreCanCnt++;
                }
                else
                {
                    nPreCanCnt = 1;
                }
                nCandyCnt += nPreCanCnt;
                nSeqLen = 0;
                nMaxCntInSeq = nPreCanCnt;
            }   
        }
    }
    return nCandyCnt;
}

//方法2
int candy(vector<int> &ratings) {
        
    int size=ratings.size();
     if(size<=1)
         return size;
     vector<int> num(size,1);
     for (int i = 1; i < size; i++)
     {
         if(ratings[i]>ratings[i-1])
             num[i]=num[i-1]+1;
     }
     for (int i= size-1; i>0 ; i--)
     {
         if(ratings[i-1]>ratings[i])
             num[i-1]=max(num[i]+1,num[i-1]);
     }
     int result=0;
     for (int i = 0; i < size; i++)
     {
         result+=num[i];
        // cout<<num[i]<<" ";
     }
     return result;
    }
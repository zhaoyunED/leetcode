Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 


//方法1

int trap(vector<int>& height) 
{
        int left =0;
        int right = height.size()-1;
        int maxleft=0,maxright=0;
        int result=0;
        while(left<right)
        {
            maxleft = max(maxleft,height[left]);
            maxright = max(maxright,height[right]);
            if(height[left]<height[right])
            {
                result += maxleft-height[left];
                left++;
            }else
            {
                result += maxright-height[right];
                right--;
            }
        }
        return result;
}



//方法二
int trap(int A[], int n) 
{
        if(A==NULL || n<1)return 0;  
          
        int maxheight = 0;  
        vector<int> leftMostHeight(n);  
        for(int i =0; i<n;i++)  
        {  
            leftMostHeight[i]=maxheight;  
            maxheight = maxheight > A[i] ? maxheight : A[i];  
        }  
  
        maxheight = 0;  
        vector<int> rightMostHeight(n);  
        for(int i =n-1;i>=0;i--)  
        {  
            rightMostHeight[i] = maxheight;  
            maxheight = maxheight > A[i] ? maxheight : A[i];  
        }  
  
        int water = 0;  
        for(int i =0; i < n; i++)  
        {  
            int high = min(leftMostHeight[i],rightMostHeight[i])-A[i];  
            if(high>0)  
                water += high;  
        }  
        return water;
}

//方法3

 struct Node  
 {  
        int h, len;  
        Node(int _h = 0, int _len = 0):h(_h), len(_len){};  
 };  

 int trap(vector<int>& A) 
{  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int n= A.size();
        int areaSum = 0;  
        stack<Node> S;  
        S.push(Node(0, 0));  
        for(int i = 0; i < n; ++i)  
        {  
            if(A[i] < S.top().h)  
            {  
                 S.push(Node(A[i], 1));  
                 continue;  
            }  
            int curLen = 0;  
            int heightSum = 0;  
            while(S.size() > 1 && A[i] >= S.top().h)  
            {  
                curLen += S.top().len;  
                heightSum += S.top().h*S.top().len;  
                S.pop();  
            }  
             
            int minHeight = min(S.top().h, A[i]);  
            int curArea = minHeight*curLen-heightSum;  
            areaSum += curArea;  
            if(A[i] > S.top().h)  
            {  
                S.pop();  
                S.push(Node(A[i], 0));  
            }  
            else S.push(Node(A[i], curLen+1));  
        }  
        return areaSum ;  
 }  
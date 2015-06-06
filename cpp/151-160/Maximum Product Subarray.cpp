class Solution {
public:
    int maxProduct(vector<int>& A) {
        if(A.size() == 1)
    		return A[0];
        
        
        int *positive = new int[A.size()+1];
        int *negative = new int[A.size()+1];
        positive[0] = 0;
        negative[0] = 0;
        
        for(int i = 0;i < A.size();i++)
        {
        	if(A[i] > 0)
        	{
        		if(positive[i] == 0)
        			positive[i+1] = A[i];
        		else
        			positive[i+1] = positive[i]*A[i];
        		negative[i+1] = negative[i]*A[i];
        	}
        	
        	else if(A[i] < 0)
        	{
        	    positive[i+1] = negative[i]*A[i];
        		if(negative[i] == 0) {
        			if(i > 0 && positive[i] > 0)
        				negative[i+1] = positive[i]*A[i];
        			else 
        				negative[i+1] = A[i];
        		}
        		else
        		{
        			if(positive[i] == 0)
        				negative[i+1] = A[i];
        			else
        				negative[i+1] = positive[i]*A[i];
        		}
        	}
        	
        	else if(A[i] == 0)
        	{
        		negative[i+1] = 0;
    			positive[i+1] = 0;
        	}
        }
 
        int res = 0;
        for(int i =1;i <= A.size();i++)
        	res = max(res, positive[i]);
        
        return res;
    }
};

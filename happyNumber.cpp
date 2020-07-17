
#include<list>
#include <algorithm>

class Solution {
public:
    int sumDgt2(int n)
    {
		int vLast = 0;
        int iSum = 0;
		while(n>9)
		{
			vLast = n%10;
			iSum += vLast * vLast;
			n = n/10;
		}
		iSum += n * n;
		return iSum;
    }
    
    bool isHappy(int n) {
    	int num = n;
    	int iSum = sumDgt2(num);
    	list<int> iListV;
    	iListV.push_back(iSum);
    	list<int>::iterator liter;
      while(iSum!=1)
      {
      	num = iSum;
      	iSum = sumDgt2(num);
      	liter = find(iListV.begin(), iListV.end(), iSum);
      	//iSum is a new value
      	if(liter==iListV.end())    	
      	{
      		iListV.push_back(iSum);
      	}
      	//iSum appears again, goes into an endless cycle
      	else
      	{
      			return false;
      	}
      }
      //iSum == 1, n is a happy number
      return true;
    }
};
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

//4/4
class Solution_moveos {
public:
    void moveZeroes(vector<int>& nums) {
        int iLength = nums.size();
        int iIndex = 0;
        vector<int>::iterator ite = nums.begin();
        while(iIndex<iLength)
        {
            int iV = *ite;
            if(iV==0)
            {
                //ite moves to the next one
                ite = nums.erase(ite);
                nums.push_back(0);
            }
            else 
                ite++;
            iIndex++;
        }
    }
};

class Solution_HappyNumber2 {
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

//Difficult 3/4
class Solution_subArray
{
	public:
		    int maxSubArray(vector<int>& nums) {
        int sum=0, maxsub=0, maxone=nums[0];
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            if(sum<=0) sum=0;
            else  maxsub = (sum>maxsub)?sum:maxsub;
            if(nums[i]>maxone) maxone = nums[i];
        }
        if(maxsub>0) return maxsub;
        else return maxone;
    }
};


int main()
{
  cout << "\nReady? go!";
  /*--------Happy Number Test ------------
	cout << "\nInput an integar(0:quit):";
	int num = 0; 
	cin>>num;
	class Solution_HappyNumber2 sol;
	while(num)
	{

			bool val = sol.isHappy(num);
			if(val)
			{
				cout <<"\nHappy ---";
			}	
			else
			{
				cout << "\nNot happy :(";
			}	
			cout << "\nInput an integar(0:quit):";
			cin>>num;
		
	}
	-------------------------------------*/
	
	return 0;		
	
}



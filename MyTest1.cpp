#include<iostream>
#include<list>
#include<vector>
#include<set>
#include <stdio.h>

#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

//8/4 Middle of the  Linked List
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL)
		{}
};

class Solution_MiddleList{
	public:
		ListNode* middleNode(ListNode* head){
			ListNode* pMiddle=head, *pNext=head;
			while(1)
			{
				if(pNext)
					pNext=pNext->next;
				else
					break;

				if(pNext)
					pNext = pNext->next;
				else
					break;

				if(pMiddle)
					pMiddle=pMiddle->next;
			}
			return pMiddle;
		}
	};

//7/4
class Solution_Count{
	public:
		int countElements(vector<int>& arr)
		{
			int iSum = 0;

			if(arr.size()<=1) return iSum;

			set<int> iS;
			for(int i=0; i<arr.size(); i++)
			{
				iS.insert(arr[i]);
			}

			for(int i=0; i<arr.size(); i++)
			{
				if(iS.find(arr[i]+1)!=iS.end())
					iSum++;
			}
			return iSum;
		}
};

//6/4
string key(string str)
{
    //字符串排序
  sort(str.begin(),str.end());
  return str;
}

bool cmp(const string& str1,const string& str2)
{
    //排序后的字符串比较
   return key(str1)<key(str2);
}


class Solution_Anagrams_Magi {
public:

   vector<vector<string> > groupAnagrams(vector<string>& strs)
   {
        //1 排序后：AAT、ATA、TAA、BBC、BCC、CEF...同类的在一起
        sort(strs.begin(),strs.end(),cmp);
        vector<vector<string> > ret;
        int start=0;
        vector<string> vec;
        //2 循环，vec存一类，等出现新类的时候，保存前面的vec，并清空，存下一组
        for(int i=0; i< strs.size(); i++)
         {
            if(key(strs[i])!=key(strs[start]))
            {
             ret.push_back(vec);
              vec.clear();
              vec.push_back(strs[i]);
              start=i;
             }
             else
             {
               vec.push_back(strs[i]);
              }

           }
        ret.push_back(vec);
                return ret;
   }
};

//6/4
class Solution_Anagrams {
public:

    int getNum(string str, char c)
    {
        int n = 0;
        for(int i=0; i<str.length(); i++)
        {
            if(c==str[i]) n++;
        }

        return n;
    };

    bool anagramEqual(string str1, string str2)
    {
        //0 sizes are different, not equal
        int len1 = str1.size();
        int len2 = str2.size();
        if(len1!=len2)
           return false;

        for(int i=0; i<len1; i++)
        {
            char c = str1[i];
            char d = str2[i];
            if(str2.find(c)==string::npos || str1.find(d)==string::npos)
                return false;
            if(getNum(str1, c)!=getNum(str2, c)) return false;
        }

        return true;
    };

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<string> curStrVec;
    	vector<vector<string> > vecResult;

        int iLength = strs.size();

        //0 special case
        if(iLength==1)
      	{
      		curStrVec.push_back(strs[0]);
      		vecResult.push_back(curStrVec);

      		return vecResult;
      	}
    	//1 loop
    	//default: each item needs to be dealt with
    	vector<bool> vecFlg;
    	vecFlg.assign(iLength, true);

    	for(int i=0; i<iLength; i++)
    	{
    		string strL = strs[i];
    		vector<string> newStrVec;
    		if(vecFlg[i]) {
                //create a new vector
                newStrVec.push_back(strL);
                //cout<<"\nNew Vec:" <<strL;

                vecFlg[i]=false;

                for(int j=i+1; j<iLength; j++){
  		  			if(vecFlg[j])
                    {
                        string strR = strs[j];
                        if(anagramEqual(strL, strR))
                        {
                            newStrVec.push_back(strR);
                            //cout<<"\t" <<strR;
                            vecFlg[j]=false;
                        }
                    }

 			   	}

 				vecResult.push_back(newStrVec);
    		}
    	}

    	return vecResult;
    }

};


//5/4
class Solution_Stock {
public:
    int maxProfit(vector<int>& prices) {
        int iSum = 0;
        int iCur=0, iNext=0, iDif = 0;
        for(int i=0; i<prices.size()-1; i++)
        {
            iCur = prices[i];
            iNext = prices[i+1];
            iDif = iNext - iCur;
            if(iDif>0) iSum+=iDif;
        }
        return iSum;
    }
};

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


	class Solution_Anagrams sol;
	string str1 = "aac";
	string str2 = "acc";
	if(sol.anagramEqual(str1, str2))
		cout <<"\nanagram Equa, len:" << str1.size() << endl;
   else
   	cout<<"\nNo!" << endl;


  /*---------buy and sell stock-----------
  class Solution_Stock sol_stock;

  cout << "\nInput the number of prices(0:quit):";
  vector<int> prices;
  int n = 0;
  cin>>n;
  if(n>0)
  {
  	int p=0;

  	for(int i=0; i<n; i++)
  	{
  		cin>>p;
  	  prices.push_back(p);
  	}

  }
  int iProfit = sol_stock.maxProfit(prices);

  cout<<"\nProfit:"<<iProfit<<endl;
  */


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



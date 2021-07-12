#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        if(s=="\0")return s;
        QuickSort(s,0,s.length()-1);
        vector<char> sTemp;
        vector<int> sCnt;  
        //sTemp.push_back(s[0]);
        //sCnt[0]++;
        int cnt=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                sTemp.push_back(s[i-1]);
                sCnt.push_back(cnt);
                cnt=1;
            }
            
        }
        sTemp.push_back(s[s.length()-1]);
		sCnt.push_back(cnt);
        string res;
        while(res.length()<s.length())
        {
            for(int i=0;i<sTemp.size();i++)
            {
                if(sCnt[i]==0)
                {
                    continue;
                }
                res+=sTemp[i];
                sCnt[i]--;
            }
             for(int i=sTemp.size()-1;i>=0;i--)
            {
                if(sCnt[i]==0)
                {
                    continue;
                }
                res+=sTemp[i];
                sCnt[i]--;
            }
        }
        return res;
    }
    int partition(string &s,int low, int high)
    {
        int p=s[low];
        while(low<high)
        {
            while(low<high && s[high]>=p)
                high--;
            s[low]=s[high];
            while(low<high && s[low]<=p)
                low++;
            s[high]=s[low];
        }

        s[low]=p;
        return low;
    }



    void QuickSort(string &s,int low,int high)
    {
        if(low<high)
        {
            int p=partition(s,low,high);
            QuickSort(s,low,p-1);
            QuickSort(s,p+1,high);
            
        }
    }

};

int main()
{
	string s;
	Solution res;
	cin >> s;
	cout << res.sortString(s);
	return 0;
}


//题解利用桶排序 比我的快排好

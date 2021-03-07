#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s) {
        bool bp[30000]={0};
        stack<char> sk;
        stack<int> si;
        for(int i=0;i<s.length();i++)
        {
            /*if(sk.empty() && s[i]==')')
                continue;
            if(s[i]=='(')
            {
                index++;
                sk.push(s[i]);
                si.push(index);
            }
            else if(s[i]==')')
            {
                sk.pop();
                bp[si.top()]=true;
                si.pop();
            }*/
            if(sk.empty())
            {
                sk.push(s[i]);
                si.push(i);
                continue;
            }
            if(s[i]=='(')
            {
                sk.push(s[i]);
                si.push(i);
            }
            else if(s[i]==')')
            {
                if(sk.top()=='(')
                {
                    bp[i]=true;
                    bp[si.top()]=true;
                    si.pop();
                    sk.pop();
                }
                else
                {
                    sk.push(s[i]);
                    si.push(i);
                }
                
            }
        }

        int maxLen=0,tempLen=0;
        int high=0,low=0;
        for (int i = 0; i < s.length(); i++)
        {
            cout << bp[i];
        }
        for(int i=0;i<s.length();)
        {
            if(bp[i])
            {
                low=i;
                high=i;
                for(int j=i;j<s.length();j++)
                {
                    if(bp[j])
                        high=j;
                    else
                    {
                        break;
                    }
                } 
                maxLen=maxLen>high-low+1?maxLen:high-low+1;
                i=high;
            }
            i++;           
        }
        return maxLen;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution res;
    cout<<res.longestValidParentheses(s)<<endl;
    return 0;
}

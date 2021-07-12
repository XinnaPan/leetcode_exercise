#include<stack>
#include<string>
#include<iostream>


using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<char> st_temp;
        int cnt=0;
        int max_cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st_temp.push(s[i]);
            else
            {
                if(st_temp.empty())
                {
                    max_cnt=max_cnt>cnt?max_cnt:cnt;
                    cnt=0;
                    continue;
                }
                else if(st_temp.top()==')')
                {
                    cnt++;
                    st_temp.pop();
                }
                else
                {
                    max_cnt = max_cnt > cnt ? max_cnt : cnt;
                    cnt = 0;
                    stack<char>().swap(st_temp);
                }
                
            }
            

        }
        return max_cnt;
    }
};

int main()
{
    string s = "(())";
    cout<<Solution().longestValidParentheses(s)<<endl;
    return 0;
}
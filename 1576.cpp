#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    string modifyString(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                if(i==0)
                {
                    for(int j=0;j<26;j++)
                    {
                        if(s[i+1]!='a'+j)
                        {
                            s[i]='a'+j;
                            break;
                        }
                    }
                }
                else if(i==s.length()-1)
                {
                    for(int j=0;j<26;j++)
                    {
                        if(s[i-1]!='a'+j)
                        {
                            s[i]='a'+j;
                            break;
                        }
                    }
                }
                else
                {
                   for(int j=0;j<26;j++)
                    {
                        if(s[i-1]!='a'+j && s[i+1]!='a'+j)
                        {
                            s[i]='a'+j;
                            break;
                        }
                    }
                }
                
            }
        }
        return s;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution res;
    cout<<res.modifyString(s)<<endl;
    return 0;
}
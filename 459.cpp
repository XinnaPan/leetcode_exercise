#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s) {
        char ch=s[0];
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[0])
            {
                string stemp=s.substr(0,i);
                int j;
                for(j=i;j<s.length();j+=i)
                {
                    string scmp=s.substr(j,i);
                    if(stemp != scmp) break;
                }
                if(j==s.length())
                    return true;

            }
        }
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution res;
    cout<<res.repeatedSubstringPattern(s)<<endl;
    return 0;
}

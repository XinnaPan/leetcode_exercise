#include<iostream>
using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int res[2];
    res[0] = 0;
    res[1] = 0;
    bool bp[1000][1000];
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
      bp[i][i] = true;
      int j = i + 1;
      if (j < s.length())
        bp[i][j] = (s[i] == s[j]);
    }
    for (int dex = 2; dex < s.length(); dex++)
    {
      for (int i = 0; i < s.length(); i++)
      {
        int j = i + dex;
        if (j < s.length())
          bp[i][j] = bp[i + 1][j - 1] & (s[i] == s[j]);
      }
    }

    for (int i = 0; i < s.length(); i++)
    {
      for (int j = i; j < s.length(); j++)
      {
        if (bp[i][j])
        {
          if (len < j - i + 1)
          {
            res[0] = i;
            res[1] = j;
            len = j - i + 1;
          }
        }
      }
    }
    string resS(s, res[0], len);
    return resS;
  }
};
int main()
{
  Solution a;
  string s = "cbbd";
  cout << a.longestPalindrome(s) << endl;
  return 0;
}
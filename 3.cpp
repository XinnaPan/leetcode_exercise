#include<iostream>

using namespace std;

class Solution
{
  public:
  int checkSame(string s,int i,int j, char target)
  {
    for (int b = i; b <= j;b++)
    {
      if(s[b]==target)
        return b + 1;
    }
    return i;
  }
  int lengthOfLongestSubstring(string s)
  {
    if(s=="\0")
      return 0;
    int begin = 0, end = 1; //end need check
    int res = 1;
    while(end<s.length())
    {
      begin = checkSame(s, begin, end - 1, s[end]);
      //cout << "be==" << begin<<"   end=="<<end << endl;
      res = (res > end - begin + 1) ? res : end - begin + 1;
      //cout << "res==" << res << endl;
      end++;
    }
    return res;
  }
};

int main()
{
  string s = "bbbb";
  Solution a;
  cout << a.lengthOfLongestSubstring(s);
  return 0;
}
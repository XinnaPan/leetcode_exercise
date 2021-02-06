#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
  vector<int> twoSum(vector<int>& nums, int target){
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size();j++)
      {
        if(nums[i]+nums[j]==target)
        {
          res.push_back(i);
          res.push_back(j);
          return res;
        }
      }
    }
  }
};

int main()
{
  int temp[3]={3, 2, 4};
  vector<int> nums(temp, temp + 3);
  int target = 6;
  Solution a;
  vector<int> res = a.twoSum(nums, target);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
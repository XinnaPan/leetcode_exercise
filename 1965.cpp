//"给定一个包含正整数、加(+)、减(-)、乘(*)、除(/)的算数表达式(括号除外)，计算其结果。
//
//表达式仅包含非负整数， + ， - ， * ， / 四种运算符和空格  。 整数除法仅保留整数部分。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/calculator-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。"

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
	int doCal(int a, int b, char s)
	{
		int res;
		switch (s)
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		}
		return 0; 
	}
public:
	int calculate(string s)
	{
		stack<char> ss;
		stack<int> si;
		for (int i = 0; i < s.length();i++)
		{
			//cout << s[i];
			if (s[i] <= '9' && s[i] >= '0')
			{
				//cout << stoi(s) << endl;
				//return 0;
				string subs = s.substr(i);
				si.push(stoi(subs));
				while (s[i] <= '9' && s[i] >= '0')
				{
					if (i + 1 < s.length())
					{
						i++;
					}
					else
					{
						i++;
						break;
					}
				}
				i--;
			}
			else //symbol
			{
				if (s[i] == ' ')
					continue;
				if (ss.empty())
				{
					ss.push(s[i]);
					//cout << "ss=" << ss.top() << "; ";
					continue;
				}
				if (s[i] == '*' || s[i] == '/')
				{
					if (ss.top() == '+' || ss.top() == '-')
						ss.push(s[i]);
					else
					{
						int iTemp;
						int a = si.top();
						si.pop();
						int b = si.top();
						si.pop();
						iTemp = doCal(b, a, ss.top());
						ss.pop();
						si.push(iTemp);
						i--;

					}
				}
				else if (s[i] == '+' || s[i] == '-')
				{
					int iTemp;
					int a = si.top();
					si.pop();
					int b = si.top();
					si.pop();
					iTemp = doCal(b, a, ss.top());
					ss.pop();
					si.push(iTemp);
					i--;
				}
				//cout << "ss=" << ss.top() << "; ";
				//cout << "si=" << si.top() << "; ";
			}
		}

		while (!ss.empty())
		{
			int iTemp;
			int a = si.top();
			si.pop();
			int b = si.top();
			si.pop();
			iTemp = doCal(b, a, ss.top());
			
			//cout << a <<ss.top()<< b<<"="<<iTemp << endl;
			ss.pop();
			si.push(iTemp);


		}

		int ret = si.top();
		si.pop();
		return ret;
	}
};
int main()
{
	string s;
	Solution res;
	cin >> s;
	cout << res.calculate(s);
	return 0;
}

//超时错误 没什么道理的感觉 再说吧
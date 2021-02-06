#include<iostream>
#include <stdio.h>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
};
class Solution
{
public:
  ListNode* addTwoNumbers(ListNode *L1, ListNode *L2)
  {
    int signIn = 0;
    ListNode *L11 = L1, *L22 = L2;
    ListNode *res=new ListNode;
    ListNode *trueRes = res;
    while (L11 && L22)
    {
      res->next = new ListNode;
      res = res->next;
      res->val = L11->val + L22->val + signIn;
      signIn = res->val / 10;
      res->val = res->val % 10;
      L11 = L11->next;
      L22 = L22->next;
    }
    res->next = NULL;

    while (L11 && signIn)
    {
      res->next = new ListNode;
      res = res->next;
      res->val = L11->val + signIn;
      signIn = res->val / 10;
      res->val = res->val % 10;
      L11 = L11->next;
    }
    if(L11)
    {
      res->next = L11;
    }
    while (L22 && signIn)
    {
      res->next = new ListNode;
      res = res->next;
      res->val = L22->val + signIn;
      signIn = res->val / 10;
      res->val = res->val % 10;
      L22 = L22->next;
    }
    if (L22)
    {
      res->next = L22;
    }

    if (signIn)
    {
      res->next = new ListNode;
      res = res->next;
      res->val = signIn;
      res->next = NULL;
    }
    return trueRes->next;
  }
};
void printList(ListNode *L1)
{
  ListNode *L11 = L1;
  while (L11)
  {
    cout << L11->val<<" ";
    L11 = L11->next;
  }
  cout << endl;
}
int main()
{
  char ch;
  ListNode *L1 = new ListNode;
  ListNode *L2 = new ListNode;
  ListNode *L10 = L1, *L20 = L2;
  cout << "1/" << endl;
  while ((ch = getchar()) != '\n')
  {
    if(ch==' ')
      continue;
    L1->next = new ListNode;
    L1 = L1->next;
    L1->val = ch - '0';
  }
  L1->next = NULL;
  cout << "2/" << endl;
  while ((ch = getchar()) != '\n')
  {
    if (ch == ' ')
      continue;
    L2->next = new ListNode;
    L2 = L2->next;
    L2->val = ch - '0';
  }
  L2->next = NULL;
  Solution a;
  printList(L10->next);
  printList(L20->next);
  printList(a.addTwoNumbers(L10->next, L20->next));
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int counte = 0;

int charToNum(string exp)
{
    int num = 0;
    int indexnum;
    for( ; exp[counte] != ',' && exp[counte] != ')' ; counte++)
    {
        indexnum = exp[counte]-'0';
        num = num*10 + indexnum;
    }

    return num;

}

int main()
{

    string exp = "1,2,54,*,+,2,1,-,+";
   // cin >> exp;

    exp = exp + ")";

    stack<int> ans;
        int len = exp.size();

   int p,q;
    for(; counte < len; counte++)
    {
     //   cout<< "kdnf";
        if(exp[counte] != ')')
        {
            if(exp[counte] == '*')
            {
                p = ans.top();
                ans.pop();
                q = ans.top();
                ans.pop();
                p=q*p;
                ans.push(p);
                counte++;
            }
            else if(exp[counte] == '/')
            {
                p = ans.top();
                ans.pop();
                q = ans.top();
                ans.pop();
                 p=q/p;
                ans.push(p);
                counte++;
            }
            else if(exp[counte] == '+')
            {
                p = ans.top();
                ans.pop();
                q = ans.top();
                ans.pop();
                p=p+q;
                ans.push(p);
                counte++;
            }
            else if(exp[counte] == '-')
            {
                p = ans.top();
                ans.pop();
                q = ans.top();
                ans.pop();
                p=q-p;
                ans.push(p);
                counte++;
            }
            else
            {
                ans.push(charToNum(exp));
            }
        }
    }

    cout << ans.top();


}

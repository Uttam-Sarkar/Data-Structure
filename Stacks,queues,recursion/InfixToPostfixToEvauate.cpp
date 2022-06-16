#include<bits/stdc++.h>
using namespace std;
int counte ;
string exple = "1+257*5+(2-1)";
double charToNum()
{
    double num = 0;
    double indexnum;
    for( ; exple[counte] != ',' && exple[counte] != ')' ; counte++)
    {
        indexnum = exple[counte]-'0';
        num = num*10 + indexnum;
    }
    return num;
}

// stack

   int maxsize = 1000;
   double ans[1000] = {0};
   int id = 0;

void push(double p)
{
    if(id > maxsize)
            {
                cout << "Array Overflow" << endl;
            }
     ans[id]=p;
     id++;
}
void pop()
{
     if(id <= 0)
    {
        cout << "Array Underflow" << endl;
      //  return 0;
    }
    ans[id] = 0;
    id--;
}
double top()
{
    return ans[id-1];
}
double evaluatePostfix(){
    counte=0;
exple = exple + ")";
    int len = exple.size();
   double p,q;
    for(; counte < len; counte++)
    {
        if(exple[counte] != ')')
        {
            if(exple[counte] == '*')
            {
                p = top();
                pop();
                q = top();
                pop();
                p=q*p;
                push(p);
                counte++;
            }
            else if(exple[counte] == '/')
            {
                p = top();
                pop();
                q = top();
                 pop();
                 p=q/p;
                push(p);
                counte++;
            }
            else if(exple[counte] == '+')
            {
                p = top();
                pop();
                q = top();
                pop();
                p=p+q;
                push(p);
                counte++;
            }
            else if(exple[counte] == '-')
            {
                p = top();
                pop();
                q = top();
                pop();
                p=q-p;
                push(p);
                counte++;
            }
            else
            {
                push(charToNum());
                //push(',');

            }
        }
    }
return top();
}

string infixToPostfix()
{
    counte=0;
     string q = exple;
         cout << q << endl;

      q = q + ")";
    string expe;// RESULT
    string CtoS;

    push('(');
    int len = exple.size();
    for(; counte <= len; counte++)
    {

        if(q[counte]>='0' && q[counte]<='9' || q[counte]>='a' && q[counte]<='z' || q[counte]>='A' && q[counte]<='Z')  //isdigit(q[i])
        {
            CtoS = q[counte];
            counte++;
            while(q[counte]>='0' && q[counte]<='9' || q[counte]>='a' && q[counte]<='z' || q[counte]>='A' && q[counte]<='Z')  //isdigit(q[i])
            {
                CtoS = CtoS + q[counte];
                counte++;
            }
            expe = expe + ',';
            expe = expe + CtoS;
            counte--;
        }

        else if(q[counte] == '(')
        {
            push(q[counte]);
        }
        else if(q[counte] == '+' || q[counte] == '-')
        {
            while(top() != '(')
            {
            CtoS = top();
            expe = expe + ',';
            expe = expe + CtoS;
             pop();
            }
            push(q[counte]);
        }
        else if(q[counte]=='*' || q[counte]=='/')
        {
            while(top() != '(' && top() != '-' && top() != '+' )
            {
             CtoS = top();
             expe = expe + ',';
            expe = expe + CtoS;
             pop();
            }
            push(q[counte]);
        }
         else if(q[counte]=='^')
        {
            push(q[counte]);
        }
        else if(q[counte]==')')
        {
            while(top() != '(' )
            {
            CtoS = top();
            expe = expe + ',';
            expe = expe + CtoS;
           pop();

            }
           pop();
        }
    }
    return expe;
}

int main()
{
string ans;
   ans = infixToPostfix();
   exple = ans;
   cout << exple << endl;
   double c = evaluatePostfix();
  cout <<  c <<endl;
}

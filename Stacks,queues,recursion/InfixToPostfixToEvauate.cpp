#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int counte ;

double substituteValue(char ch)
{
    counte++;
    if(ch == 'A')
        return 10.8;
    if(ch == 'D')
        return 20;

    return 0;
}

double charToNum(string exple)
{
    double num = 0;
    double indexnum ;
    for( ; exple[counte] != ',' && exple[counte] != ')' ; counte++)
    {
        indexnum = exple[counte]-'0';
        num = num*10 + indexnum;
    }
    return num;
}
// stack
   double STACK[N] = {0};
   int id = 0;

void push(double p)
{
    if(id > N)
            {
                cout << "Array Overflow" << endl;
            }
     STACK[id]=p;
     id++;
}
void pop()
{
     if(id <= 0)
    {
        cout << "Array Underflow" << endl;
    }
    STACK[id] = 0;
    id--;
}
double top()
{
    return STACK[id-1];
}
double evaluatePostfix(string exple){
    counte=0;
    exple = exple + ")";
    int len = exple.size();
    double p,q;//Oparetional 2 num
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

                if(exple[counte]>='a' && exple[counte]<='z' || exple[counte]>='A' && exple[counte]<='Z' )
                   {
                    push(substituteValue(exple[counte]));
                   } 
                else
                {
                    push(charToNum(exple));
                }
            }
        }
    }
return top();
}

string infixToPostfix(string q)
{
    counte=0;
    cout << q << endl;

    q = q + ")";
    string expe;// RESULT
    string CtoS;
    push('(');
    int len = q.size();
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
             expe = expe + CtoS;
            expe = expe + ',';
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
            expe = expe + CtoS;
            expe = expe + ',';
             pop();
            }
            push(q[counte]);
        }
        else if(q[counte]=='*' || q[counte]=='/')
        {
            while(top() != '(' && top() != '-' && top() != '+' )
            {
            CtoS = top();
            expe = expe + CtoS;
            expe = expe + ',';
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
            expe = expe + CtoS;
            expe = expe + ',';
           pop();

            }
           pop();
        }
    }

    int siz = expe.size()-1;
    expe.resize(siz);
    return expe;
}

int main()
{
    string exple;
    cin >> exple;
    exple = infixToPostfix(exple);
    cout << exple << endl;
    double c = evaluatePostfix(exple);
    cout <<  c <<endl;
}

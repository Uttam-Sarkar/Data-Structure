#include<bits/stdc++.h>
using namespace std;

int main()
{
    string q = "A+(B*C-(D/E^F)*G)*678";
      q = q + ")";
    string exp;// RESULT
    string CtoS;

    cout << q << endl;

    stack <char> st;

    st.push('(');

    for(int i=0; !st.empty(); i++)
    {
        if(q[i]>='0' && q[i]<='9' || q[i]>='a' && q[i]<='z' || q[i]>='A' && q[i]<='Z')  //isdigit(q[i])
        {
            CtoS = q[i];
            exp = exp + CtoS;
        }

        else if(q[i] == '(')
        {
            st.push(q[i]);
        }
        else if(q[i] == '+' || q[i] == '-')
        {
            while(st.top() != '(')
            {
            CtoS = st.top();
            exp = exp + CtoS;
             st.pop();
            }
            st.push(q[i]);
        }
        else if(q[i]=='*' || q[i]=='/')
        {
            while(st.top() != '(' && st.top() != '-' && st.top() != '+' )
            {
             CtoS = st.top();
            exp = exp + CtoS;
             st.pop();
            }
            st.push(q[i]);
        }
         else if(q[i]=='^')
        {
            st.push(q[i]);
        }
        else if(q[i]==')')
        {
            while(st.top() != '(' )
            {
            CtoS = st.top();
            exp = exp + CtoS;
           st.pop();

            }
           st.pop();
        }
    }
cout << exp << endl;
}

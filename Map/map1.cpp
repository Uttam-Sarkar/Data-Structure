#include<bits/stdc++.h>
using namespace std;

void print(map<int ,string> &m){

    cout << m.size() << endl;
    for(auto pr : m){
        cout << pr.first  << " "<< pr.second << endl;
    }
}
int main()
{
    map<int ,string> m;

    m[99] = "Uttam";
    m[9] = "Mrinal";

    m.insert({90, "Apurba"});

    auto it = m.find(99);
    if(it == m.end())
    {
        cout << "No value";
    }
    else
        cout << (*it).first << " " << (*it).second;


    //print(m);
}

#include<bits/stdc++.h>
using namespace std;

     int maxsize = 10;
    int item[10] = {0};
    int id = 0;

void push()
{
    if(id > maxsize)
            {
                cout << "Array Overflow" << endl;
            }
            cin >> item[id];
            id++;
}

void pop()
{
     if(id <= 0)
    {
        cout << "Array Underflow" << endl;
      //  return 0;
    }
    item[id] = 0;
    id--;

}
int top()
{
    //cout << item[id-1];
    return item[id-1];
}

void print()
{
    for(int i=0; i<id; i++)
    {
        cout << item[i] << " " ;
    }
    cout << endl;
}
// top, push, pop
int main()
{

    cout << "To insert use 'i' and to delete use 'd' and then the element which have to delete or insert. To exist use 'e'." << endl;

    char ch = 'k';

    while(ch != 'e')
    {

        cin >> ch;

        if(ch == 'i')
        {
            push();
        }
        else if(ch == 'd')
        {
           pop();
        }
        else if(ch == 't')
        {
          cout << top() ;

        }
      else if(ch == 'p')
        {
           print();
        }



    }

}

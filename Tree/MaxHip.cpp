#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;

ll arr[N];
//ll index = 0;
ll pos = 1;
void setPossition(){
   // cout << "u";
    ll prev = pos/2;
    ll pos2 = pos;
    ll p = 0;

        while(arr[pos2]>arr[prev] && prev!=0)
        {
            p=arr[pos2];
            arr[pos2] = arr[prev];
            arr[prev] = p;

            pos2 = prev;
            prev = pos2/2;

        }

}

int main()
{

    cout << "To exit the program enter a negative number: " << endl;
    int n;

   // vector <int> ;

    while(1){
cout << "Insert a number: ";
        cin >> n;//arr[index];
        if(n<0)
            break;


        arr[pos] = n;

        setPossition();
pos++;

    //while(n>=0);

    ll interSpace = 16;
    ll space = 30;
    for(int i=0; i<space+1; i++)
                cout << " ";

    for(int i=1, j=1,k=1; i<1000; i++,k++)
        {
            if(arr[i] != 0)
                cout << arr[i] ;

            for(int h=0; h<interSpace; h++)
                cout << " ";

            if(k == j){
                cout << endl;
                interSpace = interSpace /2;
                space = space  - interSpace/2 +interSpace/8;
                for(int i=0; i<space; i++)
                    cout << " ";

                j=j*2;

                k=0;
            }


        }

    }



}

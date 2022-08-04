#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;

ll arr[N];
//ll index = 0;file:///home/uttam/Desktop/Data-Structure/Tree/MaxHip.cpp

ll pos = 1;
void setPossition(int n){
   // cout << "u";
        if(arr[pos] == 0 || arr[pos] == n)
        {
            if(arr[pos] == n){
            cout << endl;file:///home/uttam/Desktop/Data-Structure/Tree/MaxHip.cpp

            cout << "the element already exist."<< endl;
        }
            arr[pos] = n;

        }
        else if(n < arr[pos])
        {
            pos = pos*2;
            setPossition(n);

        }
        else
        {
            pos = pos*2+1;
            setPossition(n);

        }

}

int main()
{

    cout << "To exit the program enter a negative number: " << endl;
    int n;


   // vector <int> ;
    while(1){
cout << "Insert a number: " ;
        cin >> n;//arr[index];
        if(n<0)
            break;
        //cout << "Insert a number: " << endl;

        pos = 1;
        setPossition(n);


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

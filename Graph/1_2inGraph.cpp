#include<bits/stdc++.h>
using namespace std;
const int n = 4;

int main()
{
	int p[n][n][n]={0};
	vector<int> A[n];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> p[0][i][j];

			if(p[0][i][j]==1)
				A[i].push_back(j);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			{
				for(int o=0; o<n; o++)
					{
						for(int k=0; k<n; k++)
							{
								p[i+1][j][o] = p[i+1][j][o] + p[i][j][k]*p[0][k][o];
							}
			   		}
			}
	}

	for(int i=0; i<n; i++)
	{
		cout << "A^" <<i+1 << endl;
		for(int j=0; j<n; j++)
			{
				for(int o=0; o<n; o++)
					{						
						cout << p[i][j][o] << " ";							
			   		}
			   	cout << endl;
			}
			cout << endl;
	}

/*
	cout << "Adjacent are :" << endl;
	for(int i=0; i<n; i++)
	{
		cout << i+1 << " ==> ";
		for(int j : A[i])
		{
			cout << j+1 << " ";
		}
		cout << endl;
	}
*/

	int len,vi,vj;
	cin >> len;

	while(len>0)
	{
		cin >> vi >> vj;
		cout << "The no. of paths of length " << len << " from "<<vi << " to "<< vj << " is : ";
		cout << p[len-1][vi-1][vj-1] << endl;
		cin >> len;
	}


	int b[n][n] = {0};
	int ans=0;

	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int o=0; o<n; o++)
			{
				b[i][j] = b[i][j]  + p[o][i][j];	
			}

			if(b[i][j]==0)
				ans=1;
		}
	}
	cout << endl << endl;
	cout << "B^" << n << endl;

	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<n; j++)
		{		
			cout <<	b[i][j] << " ";		
		}
		cout << endl;
	}
	cout << endl ;

	if(ans == 1)
	cout << "There exist zero. So, the graph is NOT STRONGLY connected." << endl;
	else
	cout << "There don't exist any zero. So, the graph is STRONGLY connected." << endl;
	
}
/*
not strongly connected
0 0 0 1
1 0 1 1
1 0 0 1
0 0 1 0 

3 2 3
2 1 4
1 4 2
4 2 4
-2

strongly connected
0 0 0 1
1 0 1 1
1 0 0 1
0 1 1 0 

3 2 3
2 1 4
1 4 2
4 2 4
-2

*/
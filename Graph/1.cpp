#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n = 4;
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

/*
	for(int i=0; i<n; i++)
	{
		cout << i+1 << endl;
		for(int j=0; j<n; j++)
			{
				for(int o=0; o<n; o++)
					{
						
						cout << p[i][j][o] << " ";
							
			   		}
			   	cout << endl;

			}
			cout << endl << endl;

	}
*/

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

	int len,vi,vj;

cin >> len;

while(len>0)
{
	cin >> vi >> vj;
	cout << "The no. of paths of length " << len << " from "<<vi << " to "<< vj << " is : ";
	cout << p[len-1][vi-1][vj-1] << endl;
	cin >> len;
}
	
}
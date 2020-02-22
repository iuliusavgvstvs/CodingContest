#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
using namespace std;

ifstream fin("level3_4.in");
ofstream fout("a.out");

int a[1002][1002], x[3000], y[3000],t[3000],oo,nr, ma = INT_MIN, mi = INT_MAX;
int n, m;
int main()
{
	fin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			fin >> oo >> nr;
			if (nr > ma)
				ma = nr;
			if (nr < mi)
				mi = nr;
			a[i][j] = nr;
			x[nr] += i;
			y[nr] += j;
			t[nr]++;
			if (nr == 1)
				cout << i << " " << j << '\n';
		}
	for (int i = 0; i <= ma; i++) {
		int cx, cy;
		cy = x[i]  / t[i];
		cx = y[i]  / t[i];
		cout << cx << " " << cy<< " "<<x[i]<<" "<<y[i]<<" "<<t[i] ;
		
		int k = a[cx][cy];
		int ok = 0;
		if ((a[cx + 1][cy] != k || a[cx][cy + 1] != k || a[cx - 1][cy] != k || a[cx][cy - 1] !=k)|| a[cx][cy] != i)
		{
			cout << "Granita" << '\n';
			int minimx=INT_MAX , minimy = INT_MAX;
			int dmax = INT_MAX;
			for (int jj = 0; jj < n; jj++)
				for (int ii = 0; ii < m; ii++)
				{
					if ((a[jj][ii] == i)&& (ii != m && ii != 0 && jj != n && jj != 0))
					{
						
						if (a[jj + 1][ii] == i && a[jj][ii + 1] == i && a[jj - 1][ii] == i && a[jj][ii - 1] == i)
							
						{
							if (sqrt((cx-jj) * (cx-jj) + (cy-ii) * (cy-ii) <= dmax))
							{
								dmax = sqrt((cx - jj) * (cx - jj) + (cy - ii) * (cy - ii));
								minimx = jj;
								minimy = ii;
							}
						}
					}
				}
			fout << minimy << " " << minimx << '\n';
			ok = 1;

		}
		if(ok==0)
			fout << cy << " " << cx << '\n';
		cout << endl;
	}
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m;++j)
		{
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	*/
}

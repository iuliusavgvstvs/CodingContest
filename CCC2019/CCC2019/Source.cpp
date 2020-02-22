#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
using namespace std;

ifstream fin("level3_example.in");
ofstream fout("a.out");
int a[1002][1002], z[3000], y[3000], t[3000] = { 0 };
int  main() {
	int n, m, x, ma = INT_MIN, mi = INT_MAX, nr, v[3000] = { 0 };
	long long avg = 0;
	fin>> n >> m;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {
			fin >>x >> nr;
			if (nr > ma)
				ma = nr;
			if (nr < mi)
				mi = nr;
			a[i][j] = nr;
			v[nr] += j;
			z[nr] += i;
			t[nr]++;
		}

	for (int i = 0; i <= n + 1; i++) {
		a[0][i] = -20;
		a[m + 1][i] = -20;
	}
	for (int i = 0; i <= m + 1; i++) {
		a[i][0] = -20;
		a[i][n + 1] = -20;
	}
	/*
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	*/
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int k = a[i][j];
			if (a[i + 1][j] != k || a[i][j + 1] != k || a[i - 1][j] != k || a[i][j - 1] != k)
			{
				v[k]++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int id = a[i][1];
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == id){

			}
		}
	}
	*/
	for (int i = 0; i <= ma; i++) {
		int cx, cy;
		cx = (v[i]-t[i]) / t[i];
		cy = (z[i] -t[i])/ t[i];
		cout << cx<<" "<<cy;
		int k = a[cx][cy];
		if (a[cx + 1][cy] != k || a[cx][cy + 1] != k || a[cx - 1][cy] != k || a[cx][cy - 1] != k)
			cout << "granita";
		if (a[cx][cy] != i) {
			cout << "e in afara";
		}
		cout << endl;
	}
	//cout << mi << " " << ma << " " << avg/(n * m);
}
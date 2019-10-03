#include <iostream>

using namespace std;

int main() {	
	int n=0;
	long long a = 1, b = 0, s=0;
	while (n != -1) {
		cout << "\nn= ";
		cin >> n;
		if (n == 0)
			cout << "0";
		else
			if (n == 1)
			cout << "1";
		else
		{
			while (n) {
				s = a + b;
				a = b;
				b = s;
				n--;
			}
			cout << s;
		}
		a = 1;
		b = 0;
		s = 0;
	}
	return 0;
}
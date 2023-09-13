#include <iostream>
#include <vector>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial p1(4, {-21, 5, 20, 6 });
	Polynomial p2(2, { 7, 3 });
	Polynomial exp(3, { -3, 2, 2 });
	Polynomial res = p1 / p2;
	for (int i = 0; i < res.getSize(); i++) {
		cout << res[i] << " ";
	}
	cout << endl << "res: " << (res == exp);
}
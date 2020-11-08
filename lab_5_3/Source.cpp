#include <iostream>
#include <cmath>
using namespace std;
double s(const double x);
int main()
{ 
	double rp, rk, z;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;
	double dr = (rk - rp) / n;
	double r = rp;
	while (r <= rk)
	{
		z = s(sqrt(r)+1) - s(sqrt(r) - 1)  * s(sqrt(r)-1)+1;
		cout << r << " " << z << endl;
		r += dr;
	}
	return 0;
}
double s(const double x)
{
	if (abs(x) >= 1)
		return ((1 + x * x + sqrt(abs(sin(x)))) / (sin(2) * sin(2) * x * x + 1));
	else
	{
		double s1, s2, S;
		{
			double s1 = 0;
			int i = 0;
			double a = 1;
			s1 = a;
			do
			{
				i++;
				double R = x / (i);
				a *= R;
				s1 += a;
			} while (i < 5);
			return s1;

		}

		{
			double s2 = 0;
			int k = 1;
			double a = 1;
			s2 = a;
			do
			{
				k++;
				double R = x / k;
				a *= R;
				s2 += a;
			} while (k < 6);
			return s2;
		}
		S = s1 + s2;
		return S;
	}
}

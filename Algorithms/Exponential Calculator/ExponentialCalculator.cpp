#include <iostream>
#include <math.h>

double factorial(int n)
{
	long double r = 1;
	for(int i = n; i > 0; i--)
	{
		r *= i;
	}
	return r;
}

double exponential(double e)
{
  double er = 1.0;
  for(int i = 1; i < 170; i++)
  {
    er += pow(e, i)/factorial(i);
  }
  return er;
}

int main()
{
	std::cout << exponential(1.5) << std::endl;
	return 0;
}
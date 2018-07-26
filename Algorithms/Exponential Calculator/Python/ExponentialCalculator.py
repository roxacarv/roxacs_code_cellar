def Factorial(n):
  r = 1;
  for i in range(n, 0, -1):
    r *= i;
  return r;

'''any number over 170 will return an error. Factorial are large numbers, 
floats can not handle it when it grows too much.
if you want try higher numbers please use decimal.Decimal() 
module (IT'S SLOWER THAN BASIC FLOAT!)
!170 already gives a very precise answer!'''
def Exponential(e):
  er = 1;
  for i in range(1, 170):
    er += ((e)**i)/Factorial(i);
  return er;

print(Exponential(1.5));
import math
base = float(input())
integral=[]
x=0
while x < 5.0:
  x = x + base
  area = (x**0.5)*base
  integral.append(area)
print(f"{sum(integral):.3f}")
ull nFactorial(ull n)
{
  ull ans = 1;

  for (ull i = 2; i <= n; i++)ans *= i;

  return ans;
}
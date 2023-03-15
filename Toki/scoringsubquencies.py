MOD = 998244353

n = int(input())
a = list(map(int, input().split()))

# Count the frequency of each number in the list
freq = {}
for x in a:
    freq[x] = freq.get(x, 0) + 1

# Compute the maximum exponent of each prime factor
# by taking the maximum exponent of each number in the list
max_exponent = {}
for x in freq:
    for p in range(2, int(x ** 0.5) + 1):
        if x % p == 0:
            max_exponent[p] = max(max_exponent.get(p, 0), freq[x])
            while x % p == 0:
                x //= p
    if x > 1:
        max_exponent[x] = max(max_exponent.get(x, 0), freq[x])

# Compute the answer using the formula (1 + e1) * (1 + e2) * ... * (1 + ek)
ans = 1
for p in max_exponent:
    ans = (ans * (max_exponent[p] + 1)) % MOD

print(int((ans-2)/2))

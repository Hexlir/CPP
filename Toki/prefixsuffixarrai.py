t = int(input())

for _ in range(t):
    n = int(input())
    prefixes_suffixes = input().split()
    # Calculate the number of prefixes and suffixes
    num_prefixes_suffixes = 2*n - 2
    
    # Check if the string is a palindrome
    is_palindrome = True
    for i in range(n-1):
        prefix = prefixes_suffixes[i]
        suffix = prefixes_suffixes[num_prefixes_suffixes-i-1]
        if prefix[0] != suffix[-1] or suffix[0] != prefix[-1]:
            is_palindrome = False
            break
    
    if is_palindrome:
        print("YES")
    else:
        print("NO")

# function to check if a string is a meowing
def is_meowing(s):
    # check if string starts with 'm' or 'M'
    if s[0] not in ['m', 'M']:
        return False
    
    i = 1
    # check if there is a sequence of 'e' or 'E' after 'm' or 'M'
    while i < len(s) and s[i] in ['e', 'E']:
        i += 1
    if i == 1:
        return False
    
    # check if there is a sequence of 'o' or 'O' after 'e' or 'E'
    while i < len(s) and s[i] in ['o', 'O']:
        i += 1
    if i == 2:
        return False
    
    # check if there is a sequence of 'w' or 'W' after 'o' or 'O'
    while i < len(s) and s[i] in ['w', 'W']:
        i += 1
    if i != len(s):
        return False
    
    # string is a meowing
    return True

# read number of test cases
t = int(input())

# process each test case
for i in range(t):
    # read input
    n = int(input())
    s = input()
    
    # check if string is a meowing
    if is_meowing(s):
        print("YES")
    else:
        print("NO")

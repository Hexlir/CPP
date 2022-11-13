from collections import defaultdict as defDict

while (True):
    n = int(input())
    
    if n == 0:
        break
    
    lst = defDict(list)
    
    for i in range(n):
        j = input().split()
        for w in j[1:]:
            lst[w].append(j[0])
            
    for k in sorted(lst.keys()):
        print(f'{k} {" ".join(sorted(lst[k]))}')

    print()
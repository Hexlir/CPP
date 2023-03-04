t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()

    uppercase = {}
    lowercase = {chr(i+97):0 for i in range(26)}

    for i in range(n):
        c = s[i]
        if c.islower():
            lowercase[c] += 1
        else:
            if c.lower() in lowercase and lowercase[c.lower()] > 0:
                lowercase[c.lower()] -= 1
            else:
                if c not in uppercase:
                    uppercase[c] = 0
                uppercase[c] += 1

    pairs = sum(lowercase.values())

    for i in range(k):
        if not uppercase or not lowercase:
            break
        max_upper = max(uppercase, key=uppercase.get)
        max_lower = max(lowercase, key=lowercase.get)
        if uppercase[max_upper] >= lowercase[max_lower]:
            pairs += 1
            uppercase[max_upper] -= 1
            if uppercase[max_upper] == 0:
                del uppercase[max_upper]
        else:
            pairs += 1
            lowercase[max_lower] -= 1
            if lowercase[max_lower] == 0:
                del lowercase[max_lower]

    print(pairs)

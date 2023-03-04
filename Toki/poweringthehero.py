t = int(input())

for _ in range(t):
    n = int(input())
    cards = list(map(int, input().split()))

    bonuses = []
    total_power = 0

    for card in cards:
        if card == 0:
            if bonuses:
                total_power += max(bonuses)
                bonuses.remove(max(bonuses))
        else:
            bonuses.append(card)

    print(total_power)
t = int(input())
for test_case in range(1, t+1):
    n = int(input())
    powers = list(map(int, input().split()))
    bonus_stack = []
    hero_stack = []
    for power in powers:
        if power == 0:  # hero card
            if bonus_stack:
                bonus_power = bonus_stack.pop()
                power += bonus_power
            hero_stack.append(power)
        else:  # bonus card
            bonus_stack.append(power)
    total_power = sum(hero_stack)
    print("Test case {}: {}".format(test_case, total_power))

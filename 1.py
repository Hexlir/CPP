import random
import numpy as np


def BinarySearch(list, item):
    low = 0
    high = len(list) - 1
    
    while low<= high:
        mid = (low + high) // 2
        
        guess = list[mid]
        
        if guess == item:
            return list[mid]
        
        if guess > item:
            high = mid - 1
        
        else:
            low = mid + 1
            
    return None
    
mylist = random.sample(range(0,20), 19)

item = random.randint(0,20)

print(BinarySearch(mylist, item),mylist, item)
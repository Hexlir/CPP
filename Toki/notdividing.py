# read the number of test cases
t = int(input())

# loop over the test cases
for _ in range(t):
  # read the length of the sequence
  n = int(input())
  # read the sequence elements
  a = list(map(int, input().split()))

  # initialize variables to store the maximum element and score
  max_element = 0
  max_score = 1

  # initialize a variable to store the cost of the prefix
  cost = 0

  # initialize a variable to store the index of the first occurrence of max_element
  first_index = -1

  # iterate over the sequence from left to right
  for i in range(n):
    # get the current element
    x = a[i]

    # check if it is greater than max_element
    if x > max_element:
      # update max_element and max_score accordingly
      max_element = x
      max_score = x

      # update first_index to i 
      first_index = i

      # update cost to one since we have a new maximum element 
      cost = 1
    
    elif x == max_element:
      # update max_score by multiplying it by (i - first_index + 1)
      max_score *= (i - first_index + 1)

      # update cost by adding one since we have another occurrence of max_element 
      cost += 1
    
    else:
      # do nothing since x is less than max_element 
      pass
    
    # print cost as part of output for this test case 
    print(cost, end=" ")
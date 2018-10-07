import sys

alpha = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
string = input()
# Divide
first = string[:int(len(string)/2)]
second = string[int(len(string)/2):]

# Rotate
first_sum = 0
second_sum = 0
for i in range(len(first)):
    first_sum = first_sum + (ord(first[i]) - ord('A'))
    second_sum = second_sum + (ord(second[i]) - ord('A'))

for i in range(len(first)):
    # Initial Offset
    offset = ord(first[i]) - ord('A')
    print(first[i], alpha[(offset + first_sum) % 26])



print (first_sum, second_sum)

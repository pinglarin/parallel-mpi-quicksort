import random
total_number = 100
filename = 'input.txt'
str_all = str(total_number) + " "

for i in range(0, total_number):
    n = random.randrange(0, 9999)
    str_all += str(n) + " "

with open(filename, 'w') as f:
    f.write(str_all)

#1
d = dict()
a, b = input().split()
d[a] = int(b)
a, b = input().split()
d[a] = int(b)
a, b = input().split()
d[a] = int(b)
a, b = input().split()
d[a] = int(b)
a, b = input().split()
d[a] = int(b)

name = input("Which student's score?\n")
if name in d.keys():
    print(f"{name}'s score: {d[name]}")
else:
    print(name, "is not in the database.")

#2 
import random
nums = []
for _ in range(100):
    nums.append(random.randint(1, 1000))
for i in nums:
    print(i, end=" ")
print()

maximum = 0
for i in nums:
    if maximum < i:
        maximum = i
print("max value:", maximum)

#3
words = input().split()
d = dict()
for w in words:
    if w in d:
        d[w] += 1
    else:
        d[w] = 1

for k in d.keys():
    print(k + ":", d[k])

#4
def getRandomString(leng):
    s = ""
    for _ in range(leng):
        s += chr(random.randint(97, 122))
    return s

l = int(input())
print(getRandomString(l))

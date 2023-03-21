#1
s = 0
while True:
    i = int(input())
    s += i
    if i == 0:
        break

print("sum:", s)

#2
for i in range(2, 10):
    for j in range(1, 10):
        print(f"{i}*{j}={i*j}")
    print()

#3
n = int(input())
for i in range(1, n+1):
    print("*"*i)

#4
n = int(input())
for i in range(1, n+1):
    print(" "*(n-i) + "* "*i)

#5
n = 5
for i in range(n, 0, -1):
    print(" "*(n-i) + "*"*i)

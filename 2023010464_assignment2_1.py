#1
n = int(input("n: "))
m = int(input("m: "))
for i in range(n, m+1):
    print(i)

#2
n = int(input("n: "))
m = int(input("m: "))
while n <= m:
    print(n)
    n += 1

#3
n = int(input("number: "))
for i in range(1, 10):
    print(f"{n} * {i} = {n*i}")

#4
n = int(input("number: "))
i = 1
while i <= 9:
    print(f"{n} * {i} = {n*i}")
    i += 1

#1
n = int(input())
for i in range(1, n+1):
    if i%2 == 0 or i%3 == 0:
        print(i)

#2
def add(a, b):
    return a+b

def sub(a, b):
    return a-b

def mul(a, b):
    return a*b

def div(a, b):
    return a/b

def mod(a, b):
    return a%b

def printMsg():
    print("completed")

a = int(input())
b = int(input())
print("sum:", add(a, b))
print("differenece:", sub(a, b))
print("product:", mul(a, b))
print("division:", div(a, b))
print("remainder", mod(a, b))
printMsg()

#3
gMul = 1

def addTotal(a):
    s = 0
    for i in range(1, a+1):
        s += i
    return s

def mulTotal(a):
    global gMul
    for i in range(1, a+1):
        gMul *= i

n = int(input())
print("addTotal():", addTotal(n))
mulTotal(n)
print("gMul:", gMul)

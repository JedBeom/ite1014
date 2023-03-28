#1
def printLine(n):
    for i in range(1, n+1):
        print(i, end=" ")
    print()

n = int(input())
for i in range(1, n+1):
    printLine(i)
for i in range(n, 0, -1):
    printLine(i)

#2
def problemDescription():
    print("* Number of divisors *")

def getNumOfDivisors(number):
    count = 0
    for i in range(1, number+1):
        if number%i==0:
            count += 1
    return count

first = int(input("Type the first number:\n"))
second = int(input("Type the second number:\n"))

print(f"Number of divisors of the first number is {getNumOfDivisors(first)}")
print(f"Number of divisors of the second number is {getNumOfDivisors(second)}")

#3
import random

def Roll():
    return random.randint(1, 6)

def Compare(A, B):
    if A > B:
        print("Dice A win")
    elif A < B:
        print("Dice B win")
    else:
        print("draw")

DiceA = Roll()
DiceB = Roll()
print("Dice A:", DiceA)
print("Dice B:", DiceB)
Compare(DiceA, DiceB)

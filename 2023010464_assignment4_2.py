import random

def getRandomChr():
    return chr(random.randint(97, 122))

def getRandomString(leng):
    s = ""
    for _ in range(leng):
        s += getRandomChr()
    return s

def chooseAlphabet(chosen):
    while True:
        c = getRandomChr()
        if c not in chosen:
            return c 

def getEatenCheese(original, chosen):
    s = ""

    for piece in original:
        if piece in chosen:
            s += "_"
        else:
            s += piece
    return s

def checkOutOfCheese(original, chosen):
    eatenCheese = getEatenCheese(original, chosen)
    for piece in eatenCheese:
        if piece != "_":
            return False

    return True

def printCheeseStatus(cheese, chosen):
    print("Eaten alphabet of cheese :", " ".join(chosen))
    print("Original cheese :", cheese)
    print("Current cheese status : ", getEatenCheese(cheese, chosen))

l = int(input("Input the length of the string : "))

if l < 10 or l > 30:
    print("Refer to the restriction, your input was changed to 10.")
    l = 10

cheese = getRandomString(l)
print("Generated Cheese is '"+cheese+"'")
print("Mouse starts eating!!")

chosen = []
isCompleted = False

for _ in range(10):
    alphabet = chooseAlphabet(chosen)
    chosen.append(alphabet)

    print(f"Start eating '{alphabet}'")
    printCheeseStatus(cheese, chosen)
    print()

    if checkOutOfCheese(cheese, chosen):
        isCompleted = True
        break

print()

if isCompleted:
    print("Out of cheese!")
else:
    print("Finally remained Cheese Status :")
    printCheeseStatus(cheese, chosen)

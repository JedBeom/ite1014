import random

"""
  +---+

  |   |

  O   |

 /|\  |

 / \  |

      |

=========

  +---+

  |   |

  0   |

 213  |

 4 5  |

      |

=========

0 face
1 body
2 leftHand
3 rightHand
4 leftLeg
5 rightLeg
"""

# itrue = return str if true
def itrue(s, condition):
    if condition:
        return s
    return " "

def picMaker(codes):
    form = f"""  +---+

  |   |

  {itrue("O", 0 in codes)}   |

 {itrue("/", 2 in codes)}{itrue("|", 1 in codes)}{itrue(chr(92), 3 in codes)}  |

 {itrue("/", 4 in codes)} {itrue(chr(92), 5 in codes)}  |

      |

========="""

    return form


words = {
    "Fruits" : 'apple orange lemon lime grapefruit strawberry'.split(),
    'Shapes' : "square triangle rectangle circle elipse".split(),
    'Animals' : 'bat bear beaver cat cougar crab rabbit weasel'.split()
}

def getRandomCategoryAndWord(words):
    category = random.choice(list(words.keys()))
    answer = random.choice(words[category])
    return (category, answer)

displayOrder = list(range(6))
random.shuffle(displayOrder)

def displayBoard(missedLetters, correctLetters, secretWord, secretCategory):
    print(picMaker(displayOrder[:len(missedLetters)]))
    print()
    print("Hint Category:", secretCategory)
    print('Missed letters:', end=' ')

    for letter in missedLetters:
        print(letter, end=' ')
    print()


    blanks = '_' * len(secretWord)

    for i in range(len(secretWord)): # replace blanks with correctly guessed letters
        if secretWord[i] in correctLetters:
            blanks = blanks[:i] + secretWord[i] + blanks[i+1:]

    for letter in blanks: # show the secret word with spaces in between each letter
        print(letter, end=' ')
    print()


def getGuess(alreadyGuessed):

    # Returns the letter the player entered. This function makes sure the player entered a single letter, and not something else.
    while True:
        print('Guess a letter.')
        guess = input()
        guess = guess.lower()
        if len(guess) != 1:
            print('Please enter a single letter.')
        elif guess in alreadyGuessed:
            print('You have already guessed that letter. Choose again.')
        elif guess not in 'abcdefghijklmnopqrstuvwxyz':
            print('Please enter a LETTER.')
        else:
            return guess


def playAgain():
    # This function returns True if the player wants to play again, otherwise it returns False.
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')

print('H A N G M A N modified')
missedLetters = ''
correctLetters = ''
secretCategory, secretWord = getRandomCategoryAndWord(words)
gameIsDone = False

while True:
    displayBoard(missedLetters, correctLetters, secretWord, secretCategory)
    # Let the player type in a letter.
    guess = getGuess(missedLetters + correctLetters)
    if guess in secretWord:

        correctLetters = correctLetters + guess
        # Check if the player has won

        foundAllLetters = True
        for i in range(len(secretWord)):
            if secretWord[i] not in correctLetters:
                foundAllLetters = False
                break

        if foundAllLetters:
            print('Yes! The secret word is "' + secretWord + '"! You have won!')
            gameIsDone = True

    else:
        missedLetters = missedLetters + guess
        # Check if player has guessed too many times and lost

        if len(missedLetters) == len(displayOrder) - 1:
            displayBoard(missedLetters, correctLetters, secretWord, secretCategory)
            print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' missed guesses and ' + str(len(correctLetters)) + ' correct guesses, the word was "' + secretWord + '"')
            gameIsDone = True


    # Ask the player if they want to play again (but only if the game is done).

    if gameIsDone:
        if playAgain():
            missedLetters = ''
            correctLetters = ''
            gameIsDone = False
            secretWord = getRandomWord(words)

        else:
            break

__author__ = 'YUVAL'

# ! python3
#  QuizGenerator - Generates country quizes

from random import shuffle
from random import sample

# Puts all capitals in a dictionary

capitals = {'Israel': 'Jerusalem', 'Jordan': 'Amman', 'Iraq': 'Baghdad', 'Iran': 'Tehran', 'Kuwait': 'Kuwait City',
            'Turkey': 'Ankara', 'Yemen': 'Sana',
            'Syria': 'Damascus', 'Pakistan': 'Islamabad', 'Saudi Arabia': 'Riyadh', 'Lebanon': 'Beirut',
            'Afghanistan': 'Kabul'}


# 10 Quizzes

for quizNum in range(10):
    quizFile = open('capitalsquiz%s.txt' % (quizNum + 1), 'w')
    answerKeyFile = open('capitalsquiz_answers%s.txt' % (quizNum + 1), 'w')

    quizFile.write('Name:\n\nDate:\n\nPeriod:\n\n')
    quizFile.write((' ' * 20) + 'State Capitals Quiz (Form %s)' % (quizNum + 1))
    quizFile.write('\n\n')

    # Shuffles the order

    countries = list(capitals.keys())
    shuffle(countries)

    # loops through the 12 countries and makes a question for each country


    for questionNum in range(4):
        correctAnswer = capitals[countries[questionNum]]
        wrongAnswers = list(capitals.values())
        del wrongAnswers[wrongAnswers.index(correctAnswer)]
        wrongAnswers = sample(wrongAnswers, 3)
        answerOptions = wrongAnswers + [correctAnswer]
        shuffle(answerOptions)

        # Writing Questions and Answers
        quizFile.write('%s. What is the capital %s?\n' % (questionNum + 1, countries[questionNum]))

        for i in range(4):
            quizFile.write('%s. %s\n' % ('ABCD'[i], answerOptions[i]))
        quizFile.write('\n')

        answerKeyFile.write('%s. %s\n' % (questionNum + 1, 'ABCD'[answerOptions.index(correctAnswer)]))
quizFile.close()
answerKeyFile.close()

from cs50 import get_string

text = get_string("Input text you wish to grade: ")

letters = 0
words = 1
sentences = 0

for i in range(len(text)):
    if text[i] >= 'A' and text[i] <= 'Z' or text[i] >= 'a' and text[i] <= 'z':
        letters += 1
    elif text[i] == ' ':
        words += 1
    elif text[i] == '?' or text[i] == '!' or text[i] == '.':
        sentences += 1

L = (letters / words) * 100
S = (sentences / words) * 100

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade", grade)
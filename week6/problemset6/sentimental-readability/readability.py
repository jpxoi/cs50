from cs50 import get_string

# Define a function to count the number of letters in a string.
def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
    return letters

# Define a function to count the number of words in a string.
def count_words(text):
    words = 0
    for i in range(len(text)):
        if text[i] == " ":
            words += 1
    words += 1
    return words

# Define a function to count the number of sentences in a string.
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] in [".", "!", "?"]:
            sentences += 1
    return sentences

# Get the text string from the user.
text = get_string("Text: ")

# Count the number of letters, words, and sentences in the text string.
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

# Calculate the L and S values.
L = letters / words * 100
S = sentences / words * 100

# Calculate and round the index value.
index = 0.0588 * L - 0.296 * S - 15.8
grade = int(round(index))

# Print the grade depending on the index value.
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade", grade)

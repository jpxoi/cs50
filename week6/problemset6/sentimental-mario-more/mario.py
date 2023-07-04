from cs50 import get_int

# Prompt user for height
height = get_int("Height: ")

while height < 1 or height > 8:
    height = get_int("Height: ")

# Print pyramid
for i in range(height):
    spaces = height - i - 1
    hashes = i + 1
    print(" " * spaces + "#" * hashes + "  " + "#" * hashes)

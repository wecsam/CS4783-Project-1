#!/usr/bin/python3
# This script prints out a pseudorandom set of words from english_words.txt, truncated at 500 characters.
import random, sys
# Read list of English words into memory.
english_words = [line[:-1] for line in open("english_words.txt", "r") if len(line) > 1]
# Now, randomize the order.
random.shuffle(english_words)
# Print the English words until 500 characters have been printed.
num_chars_printed = 0
while num_chars_printed < 500:
    to_print = english_words.pop() + " "
    new_num_chars_printed = num_chars_printed + len(to_print)
    if new_num_chars_printed <= 500:
        sys.stdout.write(to_print)
    else:
        sys.stdout.write(to_print[:500-num_chars_printed])
    num_chars_printed = new_num_chars_printed
print()

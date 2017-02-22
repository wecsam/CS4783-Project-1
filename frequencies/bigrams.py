#!/usr/bin/python3
# This script computes a table of characters vs. previous characters.
# Each cell is the number of times the row character followed the column character.
# This table will be saved as a CSV file, and a JSON file will also be saved.
# Another JSON file will hold, for every possible first letter, the probability
# distribution of possible second letters.
# The input file should have one word per line.
INPUT_FILE = "english_words.txt"
import csv, json, string
# This function returns a dict with a key for every letter and a key for the space character.
# The values are initialized based on value_maker, a callback that takes no arguments.
def make_a_dict_with_a_key_for_every_letter(value_maker=lambda: 0):
    result = {}
    for c in ' ' + string.ascii_lowercase:
        result[c] = value_maker()
    return result
# This function reads a dictionary (with float-type values) and returns a new dictionary
# where the values are divided by the sum.
def normalize_dict_of_floats(d):
    total = sum(d.values())
    result = {}
    for key in d:
        result[key] = d[key] / total
    return result
# The following dictionary maps a letter (Letter 1) to a dictionary that maps
# a letter (Letter 2) to the number of times that Letter 2 follows Letter 1.
# In other words, first_letter[Letter 1][Letter 2] is the number of times that
# Letter 2 follows Letter 1.
# The term "letter" actually also includes the space character. It will be assumed
# that there is a space before every word, so first_letter[space][Letter 2] is
# the number of times that Letter 2 was the first letter in a word.
first_letter = make_a_dict_with_a_key_for_every_letter(make_a_dict_with_a_key_for_every_letter)
with open(INPUT_FILE, "r") as f:
    for line in f:
        if len(line) < 2:
            # Ignore blank lines.
            continue
        previous_character = ' '
        for current_character in line[:-1] + ' ':
            if current_character in first_letter[previous_character]:
                first_letter[previous_character][current_character] += 1
                previous_character = current_character
            else:
                print("This character is invalid:", repr(current_character))
    f.close()
# Compute the data where every value is divided by the total.
# This dictionary maps the first letter to a probability distribution of possible second letters.
first_letter_prob = {}
for key in first_letter:
    first_letter_prob[key] = normalize_dict_of_floats(first_letter[key])
# Save the JSON files.
with open("bigrams.json", "w") as f:
    json.dump(first_letter, f, indent=4)
    f.close()
with open("bigrams_prob.json", "w") as f:
    json.dump(first_letter_prob, f, indent=4)
    f.close()
# Save the CSV file.
with open("bigrams.csv", "w", newline="") as f:
    writer = csv.DictWriter(f, ["First"] + list(make_a_dict_with_a_key_for_every_letter().keys()))
    writer.writeheader()
    for previous_character in first_letter:
        first_letter[previous_character]["First"] = previous_character
        writer.writerow(first_letter[previous_character])
    f.close()

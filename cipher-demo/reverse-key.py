#!/usr/bin/python3
# This script takes the key file, which is a table from plaintext letters to ciphertext values,
# and outputs a table from ciphertext values to plaintext letters.
INPUT_FILE = "Key.csv"
OUTPUT_FILE = "reverse-key.csv"
NUM_CIPHERTEXT_VALUES = 106
reversed_key = {}
with open(INPUT_FILE, "r") as key:
    for row in key:
        plaintext, ciphertexts = row[:-1].split(",", 1) # The -1 removes the newline character
        plaintext_formatted = "space" if plaintext == "' '" else plaintext.strip("'")
        for ciphertext in ciphertexts.split(" "):
            if ciphertext in reversed_key:
                print("Duplicate ciphertext value found:", ciphertext)
            reversed_key[ciphertext] = plaintext_formatted
    key.close()
with open(OUTPUT_FILE, "w") as output:
    print("Ciphertext,Plaintext", file=output)
    for ciphertext in map(str, range(0, NUM_CIPHERTEXT_VALUES)):
        if ciphertext in reversed_key:
            print(ciphertext, ",", reversed_key[ciphertext], sep="", file=output)
        else:
            print("Ciphertext not in reverse key:", ciphertext)
print("Done.")

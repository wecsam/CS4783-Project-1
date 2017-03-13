#!/bin/bash
EXECUTABLE="Tsai-Poch-decrypt"
KEY_FILE=".Tsai-Pock-key.bin"
# Test one plaintext. Pass in the plaintext as $1.
function test_plaintext {
	echo -n "Plaintext: "
	echo "$1"
	echo -n " -> Testing... "
	local decrypted=$(echo $1 | (cd ../cipher-demo/; ./cipher-demo 2>/dev/null) | "./$EXECUTABLE")
	# Check whether the plaintext matches the decrypted plaintext.
	if diff <(echo "$1") <(echo "$decrypted"); then
		# They match.
		echo
		echo "Decryption was successful."
	else
		# Set success to false to indicate that the program failed on at least one plaintext.
		success=false
	fi
	echo
}
echo "This script tests $EXECUTABLE for correctness."
# Remove the existing key file.
if [ -f "$KEY_FILE" ]; then
	rm "$KEY_FILE"
fi
# Build the executable.
echo "Running make..."
if make; then
	# The build was successful. Test the plaintexts in the plaintext dictionary.
	echo
	echo "Running part 1..."
	echo
	success=true
	cat ../cipher-demo/plaintext_dictionary.txt | while read plaintext; do
		# Ignore blank lines.
		if [ "$plaintext" ]; then
			test_plaintext "$plaintext"
		fi
	done
	if $success; then
		# The program passed part 1.
		echo "All of the plaintexts in part 1 were decrypted correctly."
		# Now, generate random plaintexts and see whether the program gets them right.
		echo "Running part 2..."
		echo
		((num_successful=0))
		for i in {1..1001}; do
			echo "Trial #$i"
			plaintext=$(cd ../frequencies; ./random_message.py)
			success=true
			test_plaintext "$plaintext"
			if $success; then
				((num_successful++))
			fi
		done
		echo "In part 2, the program succeeded $num_successful times."
		echo
	else
		echo "The tester will not continue because the program failed on at least one plaintext in part 1."
	fi
else
	echo "The tester will not continue because make did not exit normally."
fi

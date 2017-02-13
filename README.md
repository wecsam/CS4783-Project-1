# CS4783-Project-1

The files in this repository are a work-in-progress of the first project in the 2017 spring semester of CS 4783 Applied Cryptography at the NYU Tandon School of Engineering.

The repository is split into two folders, each of which is explained below.

### cipher-demo

This folder holds a program that actually executes the encryption algorithm specified in the assignment sheet. This allows us to run tests on the message space.

To compile, run `make`. To run, run `make run`.

There is also a key generation program. It generates a pseudorandom key that the encryption program can use to encrypt a message.

To compile, run `make keygen`. To run, run `make run-keygen`.

### decrypt

This is the actual program that accomplishes the objective outlined on the assignment sheet.

To compile, run `make`. To run, run `make run`.

#!/usr/bin/python3
# This script converts JSON data on STDIN to a C++ 2011 brace initialization list for a map.
# Any data that is not a dict/object or list/array is left as-is.
# The result is written to STDOUT.
import json, sys
# This class keeps track of the indentation level in the output text.
class PrettyPrinter:
    def __init__(self, stream=sys.stdout):
        self.output_stream = stream
        self.indentation_level = 0
        self.at_beginning_of_line = True
    # The following two functions increase and decrease the current indentation level.
    def increase_indent(self):
        self.indentation_level += 1
    def decrease_indent(self):
        if self.indentation_level > 0:
            self.indentation_level -= 1
    # This function automatically outputs a number of tabs based on the indentation level.
    def do_indent(self):
        self.output_stream.write("\t" * self.indentation_level)
        self.at_beginning_of_line = False
    # Call this function to write something to the output stream.
    def write(self, stuff):
        if self.at_beginning_of_line:
            self.do_indent()
        # Convert \n to calls to self.newline().
        split_at_newlines = iter(stuff.split("\n"))
        # Write the first line.
        self.output_stream.write(next(split_at_newlines))
        # Write the other lines, calling self.newline() before each line.
        for tail_line in split_at_newlines:
            self.newline()
            # Do not indent empty lines.
            if len(tail_line):
                self.do_indent()
                self.output_stream.write(tail_line)
    # This function writes a new line to the stream.
    def newline(self):
        self.output_stream.write("\n")
        self.at_beginning_of_line = True
out = PrettyPrinter()
def handle_dict(d):
    global out
    out.write("{")
    out.increase_indent()
    for key in d:
        out.write("\n{")
        handle_data(key)
        out.write(", ")
        handle_data(d[key])
        out.write("},")
    out.decrease_indent()
    out.write("\n}\n")
def handle_list(l):
    raise NotImplementedError
def handle_data(o):
    global out
    t = type(o)
    if t is list:
        handle_list(o)
    elif t is dict:
        handle_dict(o)
    else:
        out.write(repr(o))
handle_data(json.load(sys.stdin))

# Project logfind

Ex26 from Learn C the hard way.
It's a project to build a tool called logfind.
the tool takes an input and search the common places that log files are on the system and check them for occurrences of the input, if an occurrence is found the file is printed out.

features:
  1: This tool takes any sequence of words and assumes I mean "and" for them.
  2: It takes an optional argument of -o if the parameters are meant to be "or" logic 
  3: It loads the list of allowed log files from ~/.logfind
  4: The list of file names can be anything that the glob function allows. Refer to man 3 glob to see how this works. It is suggested to start with just a flat list of exact files. and then add glob functionality
  5: You should output the matching lines as you scan, and try to match them as fast as possible.


This could be a thing to practice TDD on?

CHANGELOG
[x] It should error if no search strings are provide.
[x] It should open a file in the current directory named .logfind
[ ] core functionality is to search one string for an other.

TODO
[x] create an .logfind file for testing.

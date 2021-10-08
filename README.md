
# Onegin
Tiny text formatting and sorting program.
### Description
**********************
Program formats text (cleans all line spacing), sorts lines in lexicographically ascending order (From beginning of the word, "lesser" word goes earlier, e.g. alpha < alphabet < book < bot). 

Also provides sorting in descending order and comparing words from end.

Ignores punctuation in the beginning and end of lines.

### Installing
*************************
Prerequisites: **gcc, make**
1) `clone` source code to your local repo.
2) Open command line in directory with local repo.
2) Type `make` in command line
3) Type `onegin` to open program
### Commands
**********************
* __--src <input.txt>__ 
Sets name of file to load input text from.

* __--dst <output.txt>__
Sets name of file to upload output text to.

* __-h, --help__
Prints short command reference.

* __--ralpha__
Sets line comparing from end. (E.g. tta < ttt**a** < ttt**b** < tta**c**)

* __--rsort__
Sorts lines in descending order. 

* __--format__ 
Disables sorting, only formatting occures.

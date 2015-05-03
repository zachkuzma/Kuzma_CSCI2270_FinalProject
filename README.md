# Kuzma_CSCI2270_FinalProject
## Project Summary
**Online Phone Directory:** This program will allow people to store their friend's contact in terms of names, phone numbers, and email addresses in a hash table so that other users can search for their friend's contact easily.  One major implementation the hash table will have is the ability to edit an entry.  So if a user entered their data wrong and needed to change any of the three elements of their entry, they will be able to edit by selecting a function to guide them through the process of editing their information.  The user will open the program and a list of options will be presented to the user, which include function such as:
- Inserting an Entry
- Deleting an Entry
- Finding an Entry
- Editing an Entry
- Print Entire Directory
- Exporting the Updated Directory
- Exiting the Program

## How to Run (with Geany)
To run this program, the user will first need to compile the `main.cpp` and `pdirectory.cpp` in the command line:

```
g++ main.cpp pdirectory.cpp -std=c++11
```

Since we are not using hard coding, one will need to enter a command line argument of the desired text file, which in this case is the `CurrentDirectory.txt`:

```
./a.out CurrentDirectory.txt
```

The program will run until you press 7, which as the menu states exits the program.

Follow the prompts as indicated by the program.

Press the desired number from the menu for which you want the program to perform.

## Dependencies
## Group Members
- Zach Kuzma,
- Chuan "Nelson" Khor

## Contributors:
- TA Matthew Bubernak & Prof. Hoenigman,
- bericp1
- austinholler


## Open Issues/Bugs:
- Needs ideas for a couple more functions.
- The `insertContanct` function is not running correctly right now and we
  would like if someone could try to help us get it setup correctly.  The
  problem seems to maybe arise in the initialization of the hashtable
  somewhere. [Nelson Update 5/1: partially solved]
- Alternate ideas of how to structure our edit function.
- [Nelson Update 5/1] We have come up with a simple solution for the insert function. 
- [Nelson Update 5/1] We have decided to use insertion sort to sort the collided contacts alphabatically 
  instead of vector's iterator since we don't really know how to impliment it. Suggestions to make
  it better are still welcomed.
- We still need help with the outfile for the updated directory in the `exportDirectory`
  function. 

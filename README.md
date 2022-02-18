# What is this project?

Version 1.0:  just a simple connect4 programm playable in the console. Simply build and run the code and take turns playing.
Version 1 contains:
- basic programm
- automatic checks for the win condition
- scorekeeping over multiple rounds
- option to reset scores

# How to play

Players alternate dropping pieces. Pieces will always be placed on the lowest possible space in the column. 

Try to connect four of your checkers in a row (horizontaly, vertically or diagonal), while preventing your opponent from doing the same.
First player to achieve this wins the round.

Pieces get played by entering the number of the column the player wants to put his piece in.

Version 1.0 allows you to chose at the end of each round to keep going, reset the score or stop playing by entering "y", "r" or "n".

# How the program works

The center of the program consists of a two-dimensional array saving the current gamestate.
There are methodes 
- to print the field by combining the array with different lines to make it easier to the eye.
- to ask for and fetch the user input 
- to check if the user input is a playable move
- to place the piece in the correct spot of the columnn
- to check for the win condition after each play
- to reset the board if wanted
while simple variables keep track of the score.


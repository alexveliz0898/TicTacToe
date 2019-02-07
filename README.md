# TicTacToe
Tic Tac Toe is a pretty simple game we all played as children, and the simplicity still holds when programing an AI to 
play against.

In tic tac toe, both players know all the relevant information. They both know what the playing field looks like.
Using this information, a computer can be programmed to find the best optimal solution for it to win.

Using the minMax algorithm, the computer can recursively try all possible solutions to till it reaches the end of the game
and pick out the moves that gives it the best chances of winning. 

MinMax is a decision making algorithm, the algorihtm tries to visit all possible solutions(nodes) and maximize the computers score,
while also attempting to guess what the opponents moves may be. The opponent will try to minimize the score. 
This alogorithm create a decision tree, and at the bottom of this tree is the possible scores due to the first moved picked.

You can read more about the minMax algorithm here: https://en.wikipedia.org/wiki/Minimax

MinMax is easier to implement on TicTacToe because there are lesss possible moves, making it easier for the comoputer to identify 
which moves to makes. 

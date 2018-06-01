
//you first first go to f12 sources in google developer tools
      //then add folder and then find your file, and the select and youll see the web page being linked to the webpage

//if you make changes to the code make sure to reload so you can see the results in terms of how it responds in real time.
         //for css the changes are immediate
         //for html the changes need to reloaded inorder to see the differences,

//this place seems like a good place to code in terms of developer envioment, and preety much the same as the codepen website, perhaps even better considering 
     //you can get your source files updated in real time.




//when you pause debugging and relaod then another file you can do step by step debugging.

















//////////////////////////////////////////////////////////////////////////////////////////////////////



//AI will be using the maxmin algorithm so it will become completly open to your access
      //you should put a 4x4 grid of tic tac toe have options to change options you go first or i go first.    
	   
	   //continuation with winning as well and ability to remove one move from enemy and place your own only one time.

//three player tic tac toe game 7 by 7 4 by four
       //win by tieing game
	   
	   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//in javascript i dont see int main function.  VERY STRANGE

/*

1. Basic setup
2. Determine Wi
3. Basic AI and winner notifcation
4. Minimax Algor
*/

var origBoard;
const huPlayer = 'O';              //constants       //human player and comp
const aiPlayer = 'X';

const winCombos = [
	[0, 1, 2],
	[3, 4, 5],              //straight vertical lines
	[6, 7, 8],
	[0, 3, 6],
	[1, 4, 7],           //diagonal lines       //8 ways to win
	[2, 5, 8],
	[0, 4, 8],              //horizontal lines
	[6, 4, 2]
]

const cells = document.querySelectorAll('.cell');       //cells   will calls on all the html queries that contian ".cell"
startGame();                                           //calls function  





//hey i see you


function startGame() {
	document.querySelector(".endgame").style.display = "none";        //will make sure that the end text is set to none
																			//regardless of the replay reset option
	origBoard = Array.from(Array(9).keys());         //will list 0 to 9 
	
	for (var i = 0; i < cells.length; i++) {
		cells[i].innerText = '';                        //inner text set to nothing
		cells[i].style.removeProperty('background-color');  //remove the background color that shows you the background win  
		cells[i].addEventListener('click', turnClick, false);       //cleans the board
	}                                                      //triggers the turnclick function
}









function turnClick(square) {
	if (typeof origBoard[square.target.id] == 'number') {     //
		turn(square.target.id, huPlayer)
		if (!checkWin(origBoard, huPlayer) && !checkTie()) turn(bestSpot(), aiPlayer);
	}
}








function turn(squareId, player) {
	origBoard[squareId] = player;
	document.getElementById(squareId).innerText = player;
	let gameWon = checkWin(origBoard, player)
	if (gameWon) gameOver(gameWon)
}




/*

The Equality Operator (==)

The equality operator (==) checks whether two operands are the same and returns true if they are the same and false if they are different.

The Identity Operator (===)

The identity operator checks whether two operands are “identical”.

These rules determine whether two values are identical:

They have to have the same type.
If number values have the same value they are identical, unless one or both are NaN.
If string values have the same value they are identical, unless the strings differ in length or content.
If both values refer to the same object, array or function they are identical.
If both values are null or undefined they are identical.


*/








                    
function checkWin(board, player) {   //e = board            //i = inndex
	let plays = board.reduce((a, e, i) => (e === player) ? a.concat(i) : a, []);
											//if true  a. index is increased added to array
											//if false then a is just returned
	
	let gameWon = null;
	
	//key and value relationship         //.entries access to the indexes of the win combos
	for (let [index, win] of winCombos.entries()) {            //loop thru win combo     //
	
		if (win.every(elem => plays.indexOf(elem) > -1)) {    //.every means all   //the amount of plays
			gameWon = {index: index, player: player};      //which wincombo and which player won
			break;
		}
	}
	return gameWon;
}

function gameOver(gameWon) {
	for (let index of winCombos[gameWon.index]) {
		document.getElementById(index).style.backgroundColor =
			gameWon.player == huPlayer ? "blue" : "red";
	}
	for (var i = 0; i < cells.length; i++) {
		cells[i].removeEventListener('click', turnClick, false);
	}
	declareWinner(gameWon.player == huPlayer ? "You win!" : "You lose.");
}

function declareWinner(who) {
	document.querySelector(".endgame").style.display = "block";
	document.querySelector(".endgame .text").innerText = who;
}

function emptySquares() {
	return origBoard.filter(s => typeof s == 'number');
}

function bestSpot() {
	return minimax(origBoard, aiPlayer).index;
}

function checkTie() {
	if (emptySquares().length == 0) {
		for (var i = 0; i < cells.length; i++) {
			cells[i].style.backgroundColor = "green";
			cells[i].removeEventListener('click', turnClick, false);
		}
		declareWinner("Tie Game!")
		return true;
	}
	return false;
}

function minimax(newBoard, player) {
	var availSpots = emptySquares();

	if (checkWin(newBoard, huPlayer)) {
		return {score: -10};
	} else if (checkWin(newBoard, aiPlayer)) {
		return {score: 10};
	} else if (availSpots.length === 0) {
		return {score: 0};
	}
	var moves = [];
	for (var i = 0; i < availSpots.length; i++) {
		var move = {};
		move.index = newBoard[availSpots[i]];
		newBoard[availSpots[i]] = player;

		if (player == aiPlayer) {
			var result = minimax(newBoard, huPlayer);
			move.score = result.score;
		} else {
			var result = minimax(newBoard, aiPlayer);
			move.score = result.score;
		}

		newBoard[availSpots[i]] = move.index;

		moves.push(move);
	}

	var bestMove;
	if(player === aiPlayer) {
		var bestScore = -10000;
		for(var i = 0; i < moves.length; i++) {
			if (moves[i].score > bestScore) {
				bestScore = moves[i].score;
				bestMove = i;
			}
		}
	} else {
		var bestScore = 10000;
		for(var i = 0; i < moves.length; i++) {
			if (moves[i].score < bestScore) {
				bestScore = moves[i].score;
				bestMove = i;
			}
		}
	}

	return moves[bestMove];
}
/**
 * Name: Joshua Venable
 * Date: 10/12/2022
 * Description: A good old fashioned chess game in console
 * Notes: 
 * 
 * 
 **/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "consolidates.h"
#include "chessPieces.h"

using namespace std;

class Piece;

/**
 * @brief The ChessBoard Class, this class is the board that the game is played on
 *
 */

class ChessBoard
{

private:
    Piece *board[8][8];
    Color turn;

public:
    ChessBoard();
    ChessBoard(Color startingTurn);
    ~ChessBoard() { delete this; }

    Color getTurn() { return turn; }
    void printBoard();
};

#endif

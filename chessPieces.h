/**
 * Name: Joshua Venable
 * Date: 11/1/2021
 * Description: A good old fashioned chess game in console
 * Notes:
 *
 * 11/1/2021 - creation of file, skeleton classes
 * 11/2/2021 - creation of multiple methods and constructors for classes
 **/

#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "consolidates.h"
#include "chessBoard.h"

using namespace std;

class ChessBoard;

/**
 * @brief The Piece Class, this class is the base class for all the pieces
 *
 */
class Piece
{
protected:
    int value;
    Color color;
    Position position;

public:
    Piece();
    Piece(Color color, Position position);
    ~Piece() { delete this; }

    Color getColor() { return color; }
    Position getPosition() { return position; }
    int getValue() { return value; }

    virtual bool isValidMove(Position newPosition);
    virtual bool isValidAttack(Position newPosition, Piece *piece);
    virtual bool pieceInWay(Position pos1, ChessBoard &board);

    virtual string getName() = 0;
};

/**
 * @brief The Pawn Class, this class is the pawn piece
 *
 */
class Pawn : public Piece
{
private:
    Piece promote();

public:
    Pawn();
    Pawn(Color color, Position position);
    ~Pawn() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "P"; }
};

/**
 * @brief The Rook Class, this class is the rook piece
 *
 */
class Rook : public Piece
{
public:
    Rook();
    Rook(Color color, Position position);
    ~Rook() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "R"; }
};

/**
 * @brief The Knight Class, this class is the knight piece
 *
 */
class Knight : public Piece
{
public:
    Knight();
    Knight(Color color, Position position);
    ~Knight() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "N"; }
};

/**
 * @brief The Bishop Class, this class is the bishop piece
 *
 */
class Bishop : public Piece
{
public:
    Bishop();
    Bishop(Color color, Position position);
    ~Bishop() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "B"; }
};

/**
 * @brief The Queen Class, this class is the queen piece
 *
 */
class Queen : public Piece
{
public:
    Queen();
    Queen(Color color, Position position);
    ~Queen() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "Q"; }
};

/**
 * @brief The King Class, this class is the king piece
 *
 */
class King : public Piece
{
public:
    King();
    King(Color color, Position position);
    ~King() { delete this; }

    bool isValidMove(Position newPosition);
    string getName() { return "K"; }
};

#endif
/**
 * Name: Joshua Venable
 * Date: 11/1/2021
 * Description: A good old fashioned chess game in console
 * Notes:
 *
 * 11/1/2021 - creation of file
 * 10/12/2022 - added building of chessboard & pieces
 *
 * TO-DOs:
 * make chess pieces
 * make board
 * let pieces move in the legal ways
 * make players
 * let players take turns
 * if in check player must get out of check
 * include all ways to get out of check
 * taking piece takes a piece
 * let valuation of pieces
 * Win/Lose if king in checkmate
 **/

#include "header.h"

// ---------------- ChessBoard Methods -------------- //

ChessBoard::ChessBoard()
{
    this->turn = WHITE;
}

ChessBoard::ChessBoard(Color startingTurn)
{
    this->turn = startingTurn;
}

ChessBoard::ChessBoard(Color startingTurn, Piece[][] board)
{
    this->turn = startingTurn;
    this->board = board;
}

ChessBoard::~ChessBoard()
{
    delete this;
}

// ------------------ Piece Methods ------------------ //

Piece::Piece()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = PAWN;
    this->value = 0;
}

Piece::Piece(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = PAWN;
    this->value = 1;
}

Piece::~Piece()
{
    delete this;
}

// ------------------ Pawn Methods ------------------ //

Pawn::Pawn()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = PAWN;
    this->value = 1;
}

Pawn::Pawn(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->value = 1;
}

bool Pawn::pieceInWay(Position newPosition, ChessBoard board)
{
    if (board[newPosition.x][newPosition.y] != NULL)
        return true;
    return false;
}

bool Pawn::isValidMove(Position newPosition)
{
    /* Checks for basic moves */
    switch (color)
    {
    case WHITE:
        /* Checking if the new position is one space ahead of the current position. */
        if (newPosition.y == position.y + 1 && newPosition.x == position.x)
        {
            return true;
        }
        /* Checking if the new position is two spaces ahead of the current position. Only if pawn is on the initial rank */
        else if (newPosition.y == position.y + 2 && position.y == 1 && newPosition.x == position.x)
        {
            return true;
        }
        break;

    case BLACK:
        /* Checking if the new position is one space ahead of the current position. */
        if (newPosition.y == position.y - 1 && newPosition.x == position.x)
        {
            return true;
        }
        /* Checking if the new position is two spaces ahead of the current position. Only if pawn is on the initial rank */
        else if (newPosition.y == position.y - 2 && position.y == 6 && newPosition.x == position.x)
        {
            return true;
        }
        break;
    }
    return false;
}

bool Pawn::isValidAttack(Position newPosition, Color color)
{
    switch (color)
    {
    case WHITE:
        /* Checking if attacking legally normally */
        else if (pieceInWay(newPosition) && newPosition.y == position.y + 1 && (newPosition.x == position.x + 1 || newPosition.x == position.x - 1))
        {
            return true;
        }

        Position passantL = {position.x - 1, position.y};
        Position passantR = {position.x + 1, position.y};
        
        /* Checking if attacking en Passant */
        else if (newPosition.y == position.y + 1 && (pieceInWay(passantR) && newPosition.x == position.x + 1) ||
                 (pieceInWay(passantL) && newPosition.x == position.x - 1))
        {
            return true;
        }
        {
            return true;
        }
        break;

    case BLACK:
        break;
    }
}

Piece Pawn::promote()
{
    char choice;
    cout << "What piece would you like to promote to? (Q)ueen, (R)ook, (B)ishop, or (K)night?" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'Q':
        return Queen(color, position);
        break;
    case 'R':
        return Rook(color, position);
        break;
    case 'B':
        return Bishop(color, position);
        break;
    case 'K':
        return Knight(color, position);
        break;
    default:
        cout << "Invalid choice. Defaulting to Queen." << endl;
        return Queen(color, position);
        break;
    }
}

// ------------------ Rook Methods ------------------ //

Rook::Rook()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = ROOK;
    this->value = 5;
}

Rook::Rook(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = ROOK;
    this->value = 5;
}

bool Rook::isValidMove(Position newPosition)
{
    /* Checking if the new position is on the same rank or file as the current position. */
    if (newPosition.y == position.y || newPosition.x == position.x)
    {
        return true;
    }
    return false;
}

// ------------------ Knight Methods ------------------ //

Knight::Knight()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = KNIGHT;
    this->value = 3;
}

Knight::Knight(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = KNIGHT;
    this->value = 3;
}

bool Knight::isValidMove(Position newPosition)
{
    /* Checking if the new position is two spaces ahead and one space to the left or right of the current position. */
    if (newPosition.y == position.y + 2 && (newPosition.x == position.x + 1 || newPosition.x == position.x - 1))
    {
        return true;
    }
    /* Checking if the new position is two spaces behind and one space to the left or right of the current position. */
    else if (newPosition.y == position.y - 2 && (newPosition.x == position.x + 1 || newPosition.x == position.x - 1))
    {
        return true;
    }
    /* Checking if the new position is two spaces to the left and one space ahead or behind the current position. */
    else if (newPosition.x == position.x - 2 && (newPosition.y == position.y + 1 || newPosition.y == position.y - 1))
    {
        return true;
    }
    /* Checking if the new position is two spaces to the right and one space ahead or behind the current position. */
    else if (newPosition.x == position.x + 2 && (newPosition.y == position.y + 1 || newPosition.y == position.y - 1))
    {
        return true;
    }
    return false;
}

// ------------------ Bishop Methods ------------------ //

Bishop::Bishop()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = BISHOP;
    this->value = 3;
}

Bishop::Bishop(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = BISHOP;
    this->value = 3;
}

bool Bishop::isValidMove(Position newPosition)
{
    /* Checking if the new position is on the same diagonal as the current position. */
    if (abs(newPosition.y - position.y) == abs(newPosition.x - position.x))
    {
        return true;
    }
    return false;
}

// ------------------ Queen Methods ------------------ //

Queen::Queen()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = QUEEN;
    this->value = 9;
}

Queen::Queen(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = QUEEN;
    this->value = 9;
}

bool Queen::isValidMove(Position newPosition)
{
    /* Checking if the new position is on the same rank, file, or diagonal as the current position. */
    if (newPosition.y == position.y || newPosition.x == position.x || abs(newPosition.y - position.y) == abs(newPosition.x - position.x))
    {
        return true;
    }
    return false;
}

// ------------------ King Methods ------------------ //

King::King()
{
    this->color = WHITE;
    this->position = {0, 0};
    this->type = KING;
    this->value = 0;
}

King::King(Color color, Position position)
{
    this->color = color;
    this->position = position;
    this->type = KING;
    this->value = 0;
}

bool King::isValidMove(Position newPosition)
{
    /* Checking if the new position is one space ahead, behind, to the left, or to the right of the current position. */
    if (newPosition.y == position.y + 1 && newPosition.x == position.x)
    {
        return true;
    }
    else if (newPosition.y == position.y - 1 && newPosition.x == position.x)
    {
        return true;
    }
    else if (newPosition.x == position.x + 1 && newPosition.y == position.y)
    {
        return true;
    }
    else if (newPosition.x == position.x - 1 && newPosition.y == position.y)
    {
        return true;
    }
    /* Checking if the new position is one space ahead and to the left or right of the current position. */
    else if (newPosition.y == position.y + 1 && (newPosition.x == position.x + 1 || newPosition.x == position.x - 1))
    {
        return true;
    }
    /* Checking if the new position is one space behind and to the left or right of the current position. */
    else if (newPosition.y == position.y - 1 && (newPosition.x == position.x + 1 || newPosition.x == position.x - 1))
    {
        return true;
    }
    return false;
}

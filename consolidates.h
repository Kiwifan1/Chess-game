/**
 * Name: Joshua Venable
 * Date: 10/12/2022
 * Description: A good old fashioned chess game in console
 * Notes: 
 * 
 * 
 **/

#ifndef CONSOLIDATES_H
#define CONSOLIDATES_H

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

enum Color
{
    WHITE,
    BLACK
};

enum PieceType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

struct Position
{
private:
    int x;
    int y;

public:
    Position()
    {
        this->x = 0;
        this->y = 0;
    }

    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }
    int getY() { return y; }
};

#endif
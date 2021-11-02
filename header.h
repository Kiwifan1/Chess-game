/**
 * Name: Joshua Venable
 * Date: 11/1/2021
 * Description: A good old fashioned chess game in console
 * Notes: 
 * 
 * 11/1/2021 - creation of file, skeleton classes
 * 11/2/2021 - creation of multiple methods and constructors for classes
 **/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 8;
const string CHESS_PIECES = "rkbQKbkrpppppppp";

class Player
{
private:
    bool inCheck;
    int numPieces;
    int valPieces;
public:
    Player();
    ~Player();
};

Player::Player(){
    inCheck = false;
    numPieces = 16;
    valPieces = 51; //p = 1, k = 3, b = 3, r = 5, Q = 10, K = 11
}

Player::~Player(){

}

class ChessPiece
{
private:
    char piece;
    char side;
    string location;
public:
    ChessPiece();
    ChessPiece(char type, char playerSide);
    void setLocation(string loc);
    void setSide(char playerSide);
    void setPiece(char type);
    string getLocation(void) const { return location; }
    char getPiece(void) const { return piece; }
    char getSide(void) const { return side; }
    ~ChessPiece();
};

ChessPiece::ChessPiece(char type, char playerSide) : ChessPiece() {
    side = playerSide;
    piece = type;
}

ChessPiece::ChessPiece(){
    side = '\0';
    piece = '\0';
    location = "\0";
}

void ChessPiece::setLocation(string loc){
    location = loc;
}

void ChessPiece::setSide(char playerSide){
    side = playerSide;
}

void ChessPiece::setPiece(char type){
    piece = type;
}

ChessPiece::~ChessPiece(){

}

class ChessBoard
{
private:
    int numPieces;
    ChessPiece board[BOARD_SIZE][BOARD_SIZE] = {};
public:
    ChessBoard();
    ~ChessBoard();
    void printBoard(void) const;
};

ChessBoard::ChessBoard(){
    ChessPiece chessPiece;
    for(int i = 0; i < BOARD_SIZE; i++){
        //sets the white pieces up on the board
        chessPiece.setPiece(CHESS_PIECES.at(i));
        board[0][i] = chessPiece;
        chessPiece.setLocation(0 + " " + i);

        chessPiece.setPiece(CHESS_PIECES.at(i + 8));
        board[1][i] = chessPiece;
        chessPiece.setLocation(1 + " " + i);
        
        chessPiece.setSide('b');
        
        //sets the black pieces up on the boards
        chessPiece.setPiece(CHESS_PIECES.at(i));
        board[BOARD_SIZE - 1][i] = chessPiece;
        chessPiece.setLocation(BOARD_SIZE - 1 + " " + i);

        chessPiece.setPiece(CHESS_PIECES.at(i + 8));
        board[BOARD_SIZE - 2][i] = chessPiece;
        chessPiece.setLocation(BOARD_SIZE - 2 + " " + i);
    }
}

ChessBoard::~ChessBoard(){
    
}

void ChessBoard::printBoard() const{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if(col != 0){
                cout << " ";
            }
            cout << board[row][col].getPiece();
        }
        cout << endl;
    }
}
#endif
#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "../config.hpp"


typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;
// const int piece_value[7] = {0, 124, 1276, 781, 825, 2538, 0};
// const int piece_value[7] = {0, 1, 3, 3, 5, 9, 2000};
const int piece_value[7] = {0, 2, 6, 7, 8, 20, 1000000};

const int piece_square_tables[7][BOARD_H][BOARD_W] = {
  {{0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // pawn
   {0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // rook
   {0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // knight
   {0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // bishop
   {0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // queen
   {0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 1, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}},

  {{0, 0, 0, 0, 0}, // king
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0}}
};



class Board{
  public:
    char board[2][BOARD_H][BOARD_W] = {{
      //white
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {2, 3, 4, 5, 6},
    }, {
      //black
      {6, 5, 4, 3, 2},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }};
};

enum GameState {
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};


class State{
  public:
    //You may want to add more property for a state
    GameState game_state = UNKNOWN;
    Board board;
    int player = 0;
    std::vector<Move> legal_actions;
    
    State(){};
    State(int player): player(player){};
    State(Board board): board(board){};
    State(Board board, int player): board(board), player(player){};
    
    int evaluate();
    int minimax(int depth, bool maximizingPlayer);
    int alphabeta(int depth, int alpha, int beta, bool maximizingPlayer);
    State* next_state(Move move);
    void get_legal_actions();
    std::string encode_output();
    std::string encode_state();
};

#endif
#include <cstdlib>
#include <map>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  std::map<int, Move> next_moves;

  for (Move move: state->legal_actions) {
    State* next_state = state->next_state(move);
    if (state->player==0) {
      next_moves[(*next_state).minimax(depth, false)] = move;
    }else {
      next_moves[(*next_state).minimax(depth, true)] = move;
    }
  }

  if (state->player == 0) 
    return (*next_moves.rbegin()).second;
  else
    return (*next_moves.begin()).second;
}
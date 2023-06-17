#include <cstdlib>
#include <map>

#include "../state/state.hpp"
#include "./random2.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Random2::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  std::map<int, Move> next_moves;

  for (Move move: actions) {
    State* next_state = state->next_state(move);
    next_moves[(*next_state).minimax(depth, !state->player)] = move;
  }

  if (state->player == 0) 
    return (*next_moves.rbegin()).second;
  else
    return (*next_moves.begin()).second;
}
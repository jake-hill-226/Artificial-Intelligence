/*
* Marcovian Decision Process Class
* MDP.h
*/
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <fstream>
#include <stdlib.h>
#include <iostream>

#define GAMMA 0.9
#define ERROR 0.001

// int = next_state_id, 
// float = probability of getting to that state
typedef std::pair<int, float> Next_State;

struct State{
  int reward;
  float utility;
  // char = action_id (S, G, B)
  // actions = all possible result states for taking action_id
  //            plus their probabilities
  std::map< char, std::vector<Next_State> > actions;
};

class MDP{
  
  private:

  public:
    MDP(std::string state_file_name, std::string trans_file_name);
    ~MDP();
    void toString();
    bool is_terminal_state(State);
    
    std::map<int, State> states;
    float gamma;
    float error_value;
};
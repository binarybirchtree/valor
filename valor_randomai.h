#ifndef INCLUDED_VALOR_RANDOMAI
#define INCLUDED_VALOR_RANDOMAI

#include <cpprest/json.h>

#include <valor_ai.h>
#include <valor_directions.h>
#include <valor_state.h>

namespace valor {

using namespace web;

class RandomAI : public AI {
public:
  virtual Direction decide (const State & state);
};

}

#endif

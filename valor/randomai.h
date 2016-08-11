#ifndef INCLUDED_VALOR_RANDOMAI
#define INCLUDED_VALOR_RANDOMAI

#include <cpprest/json.h>

#include "valor/ai.h"
#include "valor/directions.h"
#include "valor/state.h"

namespace valor {

using namespace web;

class RandomAI : public AI {
public:
  virtual Direction decide (const State & state);
};

}

#endif

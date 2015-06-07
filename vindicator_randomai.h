#ifndef INCLUDED_VINDICATOR_RANDOMAI
#define INCLUDED_VINDICATOR_RANDOMAI

#include <cpprest/json.h>

#include <vindicator_ai.h>
#include <vindicator_directions.h>
#include <vindicator_state.h>

namespace vindicator {

using namespace web;

class RandomAI : public AI {
public:
  virtual Direction decide (const State & state);
};

}

#endif

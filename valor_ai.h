#ifndef INCLUDED_VALOR_AI
#define INCLUDED_VALOR_AI

#include <cpprest/json.h>

#include <valor_directions.h>
#include <valor_state.h>

namespace valor {

using namespace web;

class AI {
public:
  virtual ~AI ();

  ///
  /// @param[in] state Current state.
  /// @return Direction in which to move.
  ///
  virtual Direction decide (const State & state) = 0;
};

}

#endif

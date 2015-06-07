#ifndef INCLUDED_VINDICATOR_AI
#define INCLUDED_VINDICATOR_AI

#include <cpprest/json.h>

#include <vindicator_directions.h>
#include <vindicator_state.h>

namespace vindicator {

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

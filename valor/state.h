#ifndef INCLUDED_VALOR_STATE
#define INCLUDED_VALOR_STATE

#include <memory>
#include <string>

#include <cpprest/json.h>

#include "valor/directions.h"

namespace valor {

using namespace web;

class State {
public:
  ///
  /// @param[in] value JSON representation of the state.
  ///
  State (const json::value & value);

  ///
  /// @return JSON representation of the state.
  ///
  const json::value & json () const;

  ///
  /// @return Whether or not the simulation is in an active state.
  ///
  bool active () const;

  ///
  /// @return URL of the API endpoint to which the next move request should be sent.
  ///
  std::string move_url () const;

  ///
  /// @return URL at which a graphical representation of the simulation can be viewed.
  ///
  std::string view_url () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif

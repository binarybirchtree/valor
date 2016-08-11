#ifndef INCLUDED_VALOR_CLIENT
#define INCLUDED_VALOR_CLIENT

#include <memory>
#include <string>

#include <cpprest/json.h>

#include <valor_directions.h>
#include <valor_state.h>

namespace valor {

using namespace web;

class Client {
public:
  ///
  /// @param[in] server Server to connect to.
  /// @param[in] key API key.
  ///
  Client (const std::string & server, const std::string & key);

  ///
  /// Sends the starting request to the server.
  ///
  /// @param[in] path Path to send the request to.
  /// @param[in] turns Number of turns.
  /// @param[in] board Board identifier.
  /// @return Starting state.
  ///
  State start (const std::string & path, int turns = 0, const std::string & board = "") const;

  ///
  /// Sends a move request to the server.
  ///
  /// @param[in] path Path to send the request to.
  /// @param[in] direction Direction in which to move.
  /// @return Resulting state.
  ///
  State move (const std::string & path, Direction direction) const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif
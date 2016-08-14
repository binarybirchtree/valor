// This file is part of Valor.
// Copyright (C) 2015, 2016 Binary Birch Tree
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef INCLUDED_VALOR_CLIENT
#define INCLUDED_VALOR_CLIENT

#include <memory>
#include <string>

#include <cpprest/json.h>

#include "valor/directions.h"
#include "valor/state.h"

namespace valor {

using namespace web;

///
/// Vindinium HTTP API client.
///
class Client {
public:
  ///
  /// @param[in] server Server to connect to.
  /// @param[in] key API key.
  ///
  Client (const std::string & server, const std::string & key);

  Client (Client &&);
  Client & operator = (Client &&);
  ~Client ();

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
  std::unique_ptr<Implementation> impl_;
};

}

#endif

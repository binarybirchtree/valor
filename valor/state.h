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

#ifndef INCLUDED_VALOR_STATE
#define INCLUDED_VALOR_STATE

#include <memory>
#include <string>

#include <cpprest/json.h>

#include "valor/directions.h"

namespace valor {

using namespace web;

///
/// Representation of the simulation state.
///
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

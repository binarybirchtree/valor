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

#ifndef INCLUDED_VALOR_AI
#define INCLUDED_VALOR_AI

#include <cpprest/json.h>

#include "valor/directions.h"
#include "valor/state.h"

namespace valor {

using namespace web;

///
/// Interface for decision-making AIs.
///
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

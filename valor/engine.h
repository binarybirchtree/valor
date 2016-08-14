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

#ifndef INCLUDED_VALOR_ENGINE
#define INCLUDED_VALOR_ENGINE

#include <memory>

#include "valor/configuration.h"

namespace valor {

///
/// Top-level component of the Valor API.
///
class Engine {
public:
  ///
  /// @param[in] config Configuration to use.
  ///
  Engine (const Configuration & config);

  Engine (Engine &&);
  Engine & operator = (Engine &&);
  ~Engine ();

  ///
  /// Runs one round of the simulation.
  ///
  void run () const;

private:
  class Implementation;
  std::unique_ptr<Implementation> impl_;
};

}

#endif

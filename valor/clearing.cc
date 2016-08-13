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

#include "valor/clearing.h"

namespace valor {

bool Clearing::passable () const {
  return true;
}

bool Clearing::nourishing () const {
  return false;
}

bool Clearing::bountiful () const {
  return false;
}

bool Clearing::adversarial () const {
  return false;
}

int Clearing::owner () const {
  return 0;
}

}

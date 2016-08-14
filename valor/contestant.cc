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

#include "valor/contestant.h"

namespace valor {

class Contestant::Implementation {
public:
  Implementation (int id) : id_(id) {}

  int id () const {
    return id_;
  }

private:
  int id_;
};

Contestant::Contestant (int id) : impl_(std::make_unique<Implementation>(id)) {}

Contestant::Contestant (Contestant &&) = default;
Contestant & Contestant::operator = (Contestant &&) = default;
Contestant::~Contestant () = default;

bool Contestant::passable () const {
  return false;
}

bool Contestant::nourishing () const {
  return false;
}

bool Contestant::bountiful () const {
  return false;
}

bool Contestant::adversarial () const {
  return true;
}

int Contestant::owner () const {
  return impl_->id();
}

}

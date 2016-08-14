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

#include "valor/resource.h"

namespace valor {

class Resource::Implementation {
public:
  Implementation (int owner) : owner_(owner) {}

  int owner () const {
    return owner_;
  }

private:
  int owner_;
};

Resource::Resource (int owner) : impl_(std::make_unique<Implementation>(owner)) {}

Resource::Resource (Resource &&) = default;
Resource & Resource::operator = (Resource &&) = default;
Resource::~Resource () = default;

bool Resource::passable () const {
  return false;
}

bool Resource::nourishing () const {
  return false;
}

bool Resource::bountiful () const {
  return true;
}

bool Resource::adversarial () const {
  return true;
}

int Resource::owner () const {
  return impl_->owner();
}

}

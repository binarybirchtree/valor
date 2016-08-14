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

#ifndef INCLUDED_VALOR_RESOURCE
#define INCLUDED_VALOR_RESOURCE

#include <memory>
#include <string>

#include "valor/element.h"

namespace valor {

///
/// Representation of a Resource-type board element.
///
class Resource : public Element {
public:
  Resource (int owner_id);

  Resource (Resource &&);
  Resource & operator = (Resource &&);
  ~Resource ();

  virtual bool passable () const;
  virtual bool nourishing () const;
  virtual bool bountiful () const;
  virtual bool adversarial () const;
  virtual int owner () const;

private:
  class Implementation;
  std::unique_ptr<Implementation> impl_;
};

}

#endif

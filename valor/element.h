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

#ifndef INCLUDED_VALOR_ELEMENT
#define INCLUDED_VALOR_ELEMENT

namespace valor {

///
/// Interface for board elements.
///
class Element {
public:
  virtual ~Element ();

  ///
  /// @return Whether or not the element is passable terrain.
  ///
  virtual bool passable () const = 0;

  ///
  /// @return Whether or not the element provides nourishment.
  ///
  virtual bool nourishing () const = 0;

  ///
  /// @return Whether or not the element contains resources.
  ///
  virtual bool bountiful () const = 0;

  ///
  /// @return Whether or not the element is adversarial.
  ///
  virtual bool adversarial () const = 0;

  ///
  /// @return ID of the owner of the element. Returns 0 if the element is unowned.
  ///
  virtual int owner () const = 0;
};

}

#endif

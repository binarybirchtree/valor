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

#include "valor/elementfactory.h"

#include <glog/logging.h>

#include <functional>
#include <unordered_map>

#include "valor/clearing.h"
#include "valor/obstacle.h"
#include "valor/nourishment.h"
#include "valor/contestant.h"
#include "valor/resource.h"

namespace valor {

namespace {

// This is a mapping from the first character of the type identifier (which determines the element type)
// to a function which takes the second character of the type identifier (which is used to specialize certain types)
// and creates an element of the appropriate type.
typedef std::unordered_map<char, std::function<std::shared_ptr<Element>(char)> > Mapping;

static const Mapping mapping = {
  { ' ' , [] (char) { return std::make_shared<Clearing>(); } },
  { '#' , [] (char) { return std::make_shared<Obstacle>(); } },
  { '[' , [] (char) { return std::make_shared<Nourishment>(); } },
  { '@' , [] (char modifier) { return std::make_shared<Contestant>(std::stoi(std::string(sizeof(char), modifier))); } },
  { '$' , [] (char modifier) { return std::make_shared<Resource>(modifier == '-' ? 0 : std::stoi(std::string(sizeof(char), modifier))); } }
};

} // namespace

std::shared_ptr<Element> ElementFactory::create (const Type & type) {
  Mapping::const_iterator i = mapping.find(type.front());
  if (i != mapping.end()) {
    return i->second(type.back());
  }

  LOG(ERROR) << "Invalid type string: '" << type << "'.";
  return nullptr;
}

std::ostream & operator << (std::ostream & stream, const ElementFactory::Type & type) {
  stream << type.data();
  return stream;
}

}

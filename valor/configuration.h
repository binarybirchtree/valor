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

#ifndef INCLUDED_VALOR_CONFIGURATION
#define INCLUDED_VALOR_CONFIGURATION

#include <memory>

namespace valor {

class Configuration {
public:
  ///
  /// @param[in] file_path Path to the configuration file to use.
  ///
  Configuration (const std::string & file_path = "config.json");

  ///
  /// @return Server to connect to.
  ///
  std::string server () const;

  ///
  /// @return API key.
  ///
  std::string key () const;

  ///
  /// @return Path to which the starting request should be sent.
  ///
  std::string start_path () const;

  ///
  /// @return Number of turns.
  ///
  int turns () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif

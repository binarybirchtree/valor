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

#include "valor/configuration.h"

#include <iostream>

#include <cpprest/json.h>

namespace valor {

using namespace web;

class Configuration::Implementation {
public:
  Implementation (const std::string & file_path) {
    std::ifstream file(file_path);
    std::stringstream stream;
    stream << file.rdbuf();
    try {
      data_ = json::value::parse(stream);
    }
    catch (const web::json::json_exception & error) {
      std::cerr << "Failed to parse configuration file '" << file_path << "'." << std::endl;
      throw error;
    }
  }

  std::string server () const {
    return data_.at("server").as_string();
  }

  std::string key () const {
    return data_.at("key").as_string();
  }

  std::string start_path () const {
    return data_.at("path").as_string();
  }

  int turns () const {
    return data_.at("turns").as_integer();
  }

private:
  json::value data_;
};

Configuration::Configuration (const std::string & file_path)
: impl_(std::make_unique<Implementation>(file_path)) {}

Configuration::Configuration (const Configuration & configuration)
: impl_(std::make_unique<Implementation>(*configuration.impl_)) {}

Configuration & Configuration::operator = (Configuration configuration) {
  this->impl_.swap(configuration.impl_);
  return *this;
}

Configuration::Configuration (Configuration &&) = default;
Configuration & Configuration::operator = (Configuration &&) = default;
Configuration::~Configuration () = default;

std::string Configuration::server () const {
  return impl_->server();
}

std::string Configuration::key () const {
  return impl_->key();
}

std::string Configuration::start_path () const {
  return impl_->start_path();
}

int Configuration::turns () const {
  return impl_->turns();
}

}

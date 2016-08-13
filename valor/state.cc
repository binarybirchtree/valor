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

#include "valor/state.h"

#include <cpprest/json.h>

namespace valor {

using namespace web;

class State::Implementation {
public:
  Implementation (const json::value & value) : value_(value) {}

  const json::value & json () const {
    return value_;
  }

  bool active () const {
    return !value_.at("game").at("finished").as_bool();
  }

  std::string move_url () const {
    return value_.at("playUrl").as_string();
  }

  std::string view_url () const {
    return value_.at("viewUrl").as_string();
  }

private:
  const json::value value_;
};

State::State (const json::value & value) : impl_(std::make_shared<Implementation>(value)) {}

const json::value & State::json () const {
  return impl_->json();
}

bool State::active () const {
  return impl_->active();
}

std::string State::move_url () const {
  return impl_->move_url();
}

std::string State::view_url () const {
  return impl_->view_url();
}

}

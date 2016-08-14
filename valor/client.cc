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

#include "valor/client.h"

#include <string>

#include <glog/logging.h>

#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "valor/directions.h"
#include "valor/state.h"

namespace valor {

using namespace web::http;
using namespace web::http::client;

class Client::Implementation {
public:
  Implementation (const std::string & server, const std::string & key)
  : server_(server), key_(key) {}

  State start (const std::string & path, int turns, const std::string & board) const {
    json::value data = json::value::object();
    data["key"] = json::value::string(key_);
    if (turns > 0) {
      data["turns"] = json::value(turns);
    }
    if (!board.empty()) {
      data["map"] = json::value::string(board);
    }

    return State(request(path, data));
  }

  State move (const std::string & path, Direction direction) const {
    json::value data = json::value::object();
    data["key"] = json::value::string(key_);
    std::stringstream stream;
    stream << direction;
    data["dir"] = json::value::string(stream.str());

    return State(request(path, data));
  }

private:
  const std::string server_;
  const std::string key_;

  json::value request (const std::string & path, const json::value & data) const {
    http_client client(server_);
    http_response response = client.request(methods::POST, path, data).get();
    if (response.status_code() != 200) {
      std::string message = "Error: '" + response.reason_phrase() + "'";
      LOG(ERROR) << message;
      LOG(ERROR) << response.to_string();
      throw std::runtime_error(message);
    }
    return response.extract_json().get();
  }
};

Client::Client (const std::string & server, const std::string & key)
: impl_(std::make_unique<Implementation>(server, key)) {}

Client::Client (Client &&) = default;
Client & Client::operator = (Client &&) = default;
Client::~Client () = default;

State Client::start (const std::string & path, int turns, const std::string & board) const {
  return impl_->start(path, turns, board);
}

State Client::move (const std::string & path, Direction direction) const {
  return impl_->move(path, direction);
}

}

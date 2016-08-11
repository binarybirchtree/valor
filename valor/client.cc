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
: impl_(std::make_shared<Implementation>(server, key)) {}

State Client::start (const std::string & path, int turns, const std::string & board) const {
  return impl_->start(path, turns, board);
}

State Client::move (const std::string & path, Direction direction) const {
  return impl_->move(path, direction);
}

}

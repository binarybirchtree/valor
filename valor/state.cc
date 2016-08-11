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

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

#include "valor/engine.h"

#include <stdexcept>

#include <glog/logging.h>

#include <cpprest/json.h>

#include "valor/client.h"
#include "valor/randomai.h"

namespace valor {

using namespace web;

class Engine::Implementation {
public:
  Implementation (const Configuration & config) : config_(config) {}

  void run () const {
    Client client(config_.server(), config_.key());
    RandomAI ai;

    State state = client.start(config_.start_path(), config_.turns());
    LOG(INFO) << "Simulation started.";
    LOG(INFO) << "View URL: " << state.view_url();

    while (state.active()) {
      Direction direction = ai.decide(state);
      LOG(INFO) << "Choosing to move in direction " << direction << ".";
      state = client.move(state.move_url(), direction);
    }

    LOG(INFO) << "Simulation finished.";
    state.json().serialize(LOG(INFO));
  }

private:
  const Configuration config_;
};

Engine::Engine (const Configuration & config) : impl_(std::make_shared<Implementation>(config)) {}

void Engine::run () const {
  try {
    impl_->run();
  }
  catch (const std::exception & error) {
    LOG(ERROR) << error.what();
  }
}

}

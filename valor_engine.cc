#include <valor_engine.h>

#include <stdexcept>

#include <glog/logging.h>

#include <cpprest/json.h>

#include <valor_client.h>
#include <valor_randomai.h>

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

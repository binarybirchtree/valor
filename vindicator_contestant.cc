#include <vindicator_contestant.h>

namespace vindicator {

class Contestant::Implementation {
public:
  Implementation (int id) : id_(id) {}

  int id () const {
    return id_;
  }

private:
  int id_;
};

Contestant::Contestant (int id) : impl_(std::make_shared<Implementation>(id)) {}

bool Contestant::passable () const {
  return false;
}

bool Contestant::nourishing () const {
  return false;
}

bool Contestant::bountiful () const {
  return false;
}

bool Contestant::adversarial () const {
  return true;
}

int Contestant::owner () const {
  return impl_->id();
}

}

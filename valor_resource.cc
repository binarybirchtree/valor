#include <valor_resource.h>

namespace valor {

class Resource::Implementation {
public:
  Implementation (int owner) : owner_(owner) {}

  int owner () const {
    return owner_;
  }

private:
  int owner_;
};

Resource::Resource (int owner) : impl_(std::make_shared<Implementation>(owner)) {}

bool Resource::passable () const {
  return false;
}

bool Resource::nourishing () const {
  return false;
}

bool Resource::bountiful () const {
  return true;
}

bool Resource::adversarial () const {
  return true;
}

int Resource::owner () const {
  return impl_->owner();
}

}

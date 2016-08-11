#include <valor_nourishment.h>

namespace valor {

bool Nourishment::passable () const {
  return false;
}

bool Nourishment::nourishing () const {
  return true;
}

bool Nourishment::bountiful () const {
  return false;
}

bool Nourishment::adversarial () const {
  return false;
}

int Nourishment::owner () const {
  return 0;
}

}

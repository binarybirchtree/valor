#include <vindicator_nourishment.h>

namespace vindicator {

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

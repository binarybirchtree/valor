#include <vindicator_clearing.h>

namespace vindicator {

bool Clearing::passable () const {
  return true;
}

bool Clearing::nourishing () const {
  return false;
}

bool Clearing::bountiful () const {
  return false;
}

bool Clearing::adversarial () const {
  return false;
}

int Clearing::owner () const {
  return 0;
}

}

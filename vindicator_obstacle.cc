#include <vindicator_obstacle.h>

namespace vindicator {

bool Obstacle::passable () const {
  return false;
}

bool Obstacle::nourishing () const {
  return false;
}

bool Obstacle::bountiful () const {
  return false;
}

bool Obstacle::adversarial () const {
  return false;
}

int Obstacle::owner () const {
  return 0;
}

}

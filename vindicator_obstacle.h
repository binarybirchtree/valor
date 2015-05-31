#ifndef INCLUDED_VINDICATOR_OBSTACLE
#define INCLUDED_VINDICATOR_OBSTACLE

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

class Obstacle : public Element {
public:
  virtual bool passable () const;
  virtual bool nourishing () const;
  virtual bool bountiful () const;
  virtual bool adversarial () const;
  virtual int owner () const;
};

}

#endif

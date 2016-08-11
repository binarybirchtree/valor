#ifndef INCLUDED_VALOR_OBSTACLE
#define INCLUDED_VALOR_OBSTACLE

#include <memory>

#include "valor/element.h"

namespace valor {

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

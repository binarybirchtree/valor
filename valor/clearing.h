#ifndef INCLUDED_VALOR_CLEARING
#define INCLUDED_VALOR_CLEARING

#include <memory>

#include "valor/element.h"

namespace valor {

class Clearing : public Element {
public:
  virtual bool passable () const;
  virtual bool nourishing () const;
  virtual bool bountiful () const;
  virtual bool adversarial () const;
  virtual int owner () const;
};

}

#endif

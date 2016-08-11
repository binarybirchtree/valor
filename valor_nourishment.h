#ifndef INCLUDED_VALOR_NOURISHMENT
#define INCLUDED_VALOR_NOURISHMENT

#include <memory>

#include <valor_element.h>

namespace valor {

class Nourishment : public Element {
public:
  virtual bool passable () const;
  virtual bool nourishing () const;
  virtual bool bountiful () const;
  virtual bool adversarial () const;
  virtual int owner () const;
};

}

#endif

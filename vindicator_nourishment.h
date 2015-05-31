#ifndef INCLUDED_VINDICATOR_NOURISHMENT
#define INCLUDED_VINDICATOR_NOURISHMENT

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

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

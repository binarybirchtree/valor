#ifndef INCLUDED_VINDICATOR_CLEARING
#define INCLUDED_VINDICATOR_CLEARING

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

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

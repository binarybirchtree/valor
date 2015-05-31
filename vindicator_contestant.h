#ifndef INCLUDED_VINDICATOR_CONTESTANT
#define INCLUDED_VINDICATOR_CONTESTANT

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

class Contestant : public Element {
public:
  Contestant (int id);

  virtual bool passable () const;
  virtual bool nourishing () const;
  virtual bool bountiful () const;
  virtual bool adversarial () const;
  virtual int owner () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif

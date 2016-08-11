#ifndef INCLUDED_VALOR_RESOURCE
#define INCLUDED_VALOR_RESOURCE

#include <memory>
#include <string>

#include <valor_element.h>

namespace valor {

class Resource : public Element {
public:
  Resource (int owner_id);

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

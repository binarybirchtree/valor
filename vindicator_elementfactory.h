#ifndef INCLUDED_VINDICATOR_ELEMENTFACTORY
#define INCLUDED_VINDICATOR_ELEMENTFACTORY

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

class ElementFactory {
public:
  ///
  /// Creates an Element specified by a type string.
  ///
  /// @return Pointer to the created element on success; null pointer on failure.
  ///
  static std::shared_ptr<Element> create (const std::string & type);
};

}

#endif

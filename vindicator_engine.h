#ifndef INCLUDED_VINDICATOR_ENGINE
#define INCLUDED_VINDICATOR_ENGINE

#include <memory>

#include <vindicator_configuration.h>

namespace vindicator {

class Engine {
public:
  ///
  /// @param[in] config Configuration to use.
  ///
  Engine (const Configuration & config);

  ///
  /// Runs one round of the simulation.
  ///
  void run () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif

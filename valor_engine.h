#ifndef INCLUDED_VALOR_ENGINE
#define INCLUDED_VALOR_ENGINE

#include <memory>

#include <valor_configuration.h>

namespace valor {

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

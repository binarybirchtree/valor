#ifndef INCLUDED_VINDICATOR_CONFIGURATION
#define INCLUDED_VINDICATOR_CONFIGURATION

#include <memory>

namespace vindicator {

class Configuration {
public:
  ///
  /// @param[in] file_path Path to the configuration file to use.
  ///
  Configuration (const std::string & file_path = "config.json");

  ///
  /// @return Server to connect to.
  ///
  std::string server () const;

  ///
  /// @return API key.
  ///
  std::string key () const;

  ///
  /// @return Path to which the starting request should be sent.
  ///
  std::string start_path () const;

  ///
  /// @return Number of turns.
  ///
  int turns () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif

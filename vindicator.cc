#include <glog/logging.h>

#include <vindicator_configuration.h>
#include <vindicator_engine.h>

int main (int argc, char * argv []) {
  using namespace vindicator;

  FLAGS_logtostderr = true;
  FLAGS_stderrthreshold = 0;
  google::InitGoogleLogging(argv[0]);

  Configuration config;
  Engine engine(config);
  engine.run();
}

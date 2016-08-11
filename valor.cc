#include <glog/logging.h>

#include <valor_configuration.h>
#include <valor_engine.h>

int main (int argc, char * argv []) {
  using namespace valor;

  FLAGS_logtostderr = true;
  FLAGS_stderrthreshold = 0;
  google::InitGoogleLogging(argv[0]);

  Configuration config;
  Engine engine(config);
  engine.run();
}

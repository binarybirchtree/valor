#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/program_options.hpp>
#include <glog/logging.h>

#include "valor/configuration.h"
#include "valor/engine.h"

namespace opts = boost::program_options;

int main (int argc, char * argv []) {
  using namespace valor;

  FLAGS_logtostderr = true;
  FLAGS_stderrthreshold = 0;
  google::InitGoogleLogging(argv[0]);

  opts::options_description options("Usage");
  options.add_options()("config,c", opts::value<std::string>()->required(), "Path to configuration file");
  opts::positional_options_description positional_options;
  positional_options.add("config", 1);
  opts::variables_map parsed_options;
  opts::store(opts::command_line_parser(argc, argv)
    .options(options).positional(positional_options).run(), parsed_options);

  try {
    opts::notify(parsed_options);
  }
  catch (const opts::required_option & error) {
    std::cout << "Invalid arguments: " << error.what() << "." << std::endl;
    std::cout << std::endl << options << std::endl;
    return EXIT_FAILURE;
  }

  Configuration config(parsed_options["config"].as<std::string>());
  Engine engine(config);
  engine.run();
}

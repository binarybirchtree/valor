// This file is part of Valor.
// Copyright (C) 2015, 2016 Binary Birch Tree
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

#include <vindicator_configuration.h>

#include <cpprest/json.h>

namespace vindicator {

using namespace web;

class Configuration::Implementation {
public:
  Implementation (const std::string & file_path) {
    std::ifstream file(file_path);
    std::stringstream stream;
    stream << file.rdbuf();
    data_ = json::value::parse(stream);
  }

  std::string server () const {
    return data_.at("server").as_string();
  }

  std::string key () const {
    return data_.at("key").as_string();
  }

  std::string start_path () const {
    return data_.at("path").as_string();
  }

  int turns () const {
    return data_.at("turns").as_integer();
  }

private:
  json::value data_;
};

Configuration::Configuration (const std::string & file_path) : impl_(std::make_shared<Implementation>(file_path)) {}

std::string Configuration::server () const {
  return impl_->server();
}

std::string Configuration::key () const {
  return impl_->key();
}

std::string Configuration::start_path () const {
  return impl_->start_path();
}

int Configuration::turns () const {
  return impl_->turns();
}

}

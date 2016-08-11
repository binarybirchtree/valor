#include <gtest/gtest.h>

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include <valor_client.h>

using namespace web::http::experimental::listener;
using namespace web::http;
using namespace web;

using namespace valor;

class ClientTest : public ::testing::Test {
protected:
  ClientTest () : endpoint_("http://localhost:8000/test"), listener_(endpoint_), key_("abc") {
    listener_.open().wait();
    listener_.support([] (http_request request) {
      request.reply(status_codes::OK, request.extract_json().get());
    });
  }

  ~ClientTest () {
    listener_.close().wait();
  }

  const uri endpoint_;
  http_listener listener_;
  const std::string key_;
};

TEST_F (ClientTest, CanSendStartRequest) {
  uri endpoint(endpoint_);
  Client client(endpoint.authority().to_string(), key_);
  json::value response = client.start(endpoint.path()).json();
  ASSERT_EQ(key_, response["key"].as_string());
}

TEST_F (ClientTest, CanSendMoveRequest) {
  uri endpoint(endpoint_);
  Client client(endpoint.authority().to_string(), key_);
  json::value response = client.move(endpoint.path(), Direction::STAY).json();
  ASSERT_EQ(key_, response["key"].as_string());
  ASSERT_EQ("Stay", response["dir"].as_string());
}

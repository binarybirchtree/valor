#include <glog/logging.h>

#include <vindicator_element.h>
#include <vindicator_board.h>

int main (int argc, char * argv []) {
  FLAGS_logtostderr = true;
  FLAGS_stderrthreshold = 0;
  google::InitGoogleLogging(argv[0]);
}

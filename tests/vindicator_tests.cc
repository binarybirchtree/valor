#include <gtest/gtest.h>
#include <glog/logging.h>

#include <vindicator_board.h>

namespace {

using namespace vindicator;

class BoardTest : public ::testing::Test {
protected:
  // Initialize the board with the example from http://vindinium.org/starters.
  BoardTest () : size_(18), board_(
    size_,
    "##############        ##############"
    "##############        ##############"
    "################    ################"
    "##############$4    $4##############"
    "##############  @4    ##############"
    "##########  @1##    ##    ##########"
    "##########  []        []  ##########"
    "########        ####        ########"
    "############  $4####$4  ############"
    "############  $4####$4  ############"
    "########        ####        ########"
    "##########  []        []  ##########"
    "##########  @2##    ##@3  ##########"
    "##############        ##############"
    "##############$-    $-##############"
    "################    ################"
    "##############        ##############"
    "##############        ##############"
  ) {}

  std::size_t size_;
  Board board_;
};

TEST_F (BoardTest, HasTheCorrectSize) {
  ASSERT_EQ(size_, board_.size());
}

} // namespace

int main (int argc, char * argv []) {
  google::InitGoogleLogging(argv[0]);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

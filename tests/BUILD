cc_library(
  name = 'testcases',
  srcs = glob(['*_test.cc']),
  copts = ['-Iexternal/googletest/googletest/include'],
  deps = [
    '//valor:valor',
    '@googletest//:gtest',
  ],
  visibility = ['//visibility:private'],
)

cc_test(
  name = 'tests',
  srcs = ['test_runner.cc'],
  copts = ['-Iexternal/googletest/googletest/include'],
  deps = [':testcases'],
  linkopts = [
    '-lcpprest',
    '-lssl',
    '-lcrypto',
    '-lboost_system',
    '-lglog',
    '-lstdc++',
    '-lm',
  ],
  timeout = 'short',
)

cc_library(
  name = 'gtest',
  srcs = glob(['googletest/src/*.cc'], exclude=['googletest/src/gtest-all.cc']),
  hdrs = glob(['googletest/src/*.h', 'googletest/include/**/*.h']),
  copts = [
    '-Iexternal/googletest/googletest',
    '-Iexternal/googletest/googletest/include',
  ],
  linkopts = ['-pthread'],
  visibility = ['//visibility:public'],
)

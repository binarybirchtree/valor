cc_binary(
  name = 'example',
  srcs = ['example.cc'],
  deps = ['//valor:valor'],
  linkopts = [
    '-lcpprest',
    '-lssl',
    '-lcrypto',
    '-lboost_system',
    '-lboost_program_options',
    '-lglog',
    '-lgflags',
    '-lstdc++',
    '-lm',
  ],
)

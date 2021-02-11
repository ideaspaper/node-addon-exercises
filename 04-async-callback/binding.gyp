{
  "targets": [
    {
      "target_name": "fibonacci_async",
      "sources": [
        "fibonacci_async.cc",
        "fibonacci_worker.cc"
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"]
    }
  ]
}

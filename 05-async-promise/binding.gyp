{
  "targets": [
    {
      "target_name": "fibonacci_promise",
      "sources": [
        "fibonacci_helper.cc",
        "fibonacci_worker.cc",
        "fibonacci_promise.cc"
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"]
    }
  ]
}

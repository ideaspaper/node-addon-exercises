{
  "targets": [
    {
      "target_name": "fibonacci_callback",
      "sources": [
        "fibonacci_helper.cc",
        "fibonacci_worker.cc",
        "fibonacci_callback.cc"
      ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"]
    }
  ]
}

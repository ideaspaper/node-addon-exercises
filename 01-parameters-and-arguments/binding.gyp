{
  "targets": [
    {
      "target_name": "parameters_and_arguments",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "parameters_and_arguments.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        ""
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ]
}

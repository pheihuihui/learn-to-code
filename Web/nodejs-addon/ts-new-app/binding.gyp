{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "lib/hello.cc" ],
      "include_dirs": [
      "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
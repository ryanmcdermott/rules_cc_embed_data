# rules_cc_embed_data

Bazel rule to generate C++ header files with embedded binary data.

## Pre-Requisites

* Bazel 6.0.0 or higher.
* C++ Compiler.
* Linux. _This rule has not been tested on other operating systems._

## Usage

### Workspace

```
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "rules_cc_embed_data",
    strip_prefix = "rules_cc_embed_data-0.1.0",
    urls = ["https://github.com/ryanmcdermott/rules_cc_embed_data/archive/refs/tags/0.1.0.tar.gz"],
)
```

### BUILD file

```
load("@rules_cc_embed_data/cc_embed_data:defs.bzl", "embed_data")

embed_data(
    name = "example_texts",
    srcs = ["example1.txt", "example2.txt"],
    visibility = ["//visibility:public"],
)
```

## Example

See `examples` directory in this repo.

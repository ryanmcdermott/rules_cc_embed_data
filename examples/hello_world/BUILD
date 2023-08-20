load("//cc_embed_data:defs.bzl", "embed_data")

embed_data(
    name = "example_texts",
    srcs = ["example1.txt", "example2.txt"],
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [":example_texts"],
)
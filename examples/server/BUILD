cc_library(
    name = "httplib",
    srcs = ["httplib.h"]
)

cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [":httplib", "//examples/server/data:web_data"]
)
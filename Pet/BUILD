load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
    name = "Pet",
    srcs = ["src/Pet.cpp"],
    hdrs = [
            "include/Pet.hpp", 
            "include/InMessageA.hpp", 
            "include/InMessageB.hpp",
            "include/OutMessage.hpp"
            ],
    copts = ['-IPet/include'],
    visibility = ["//visibility:public"],
)


cc_binary(
    name = "test",
    srcs = ["src/main.cpp"],
    copts = ['-IPet/include'],
    deps = [
        ":Pet",
    ],
)


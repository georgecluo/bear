load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "ATMController",
    srcs = ["ATMController.cc"],
    hdrs = ["ATMController.h"],
)

cc_binary(
    name = "ATMDriver",
    srcs = ["ATMDriver.cc"],
    deps = [
        ":ATMController",
    ],
)
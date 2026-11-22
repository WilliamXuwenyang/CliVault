cmake_minimum_required(VERSION 3.14)

project(CliVault VERSION 1.0 LANGUAGES C CXX)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF) # 保留详细日志

# 1. zlib —— 直接下载官方源码包
FetchContent_Declare(
    zlib
    URL https://ghfast.top/https://github.com/madler/zlib/releases/download/v1.3.1/zlib-1.3.1.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# 2. libsodium —— 直接下载官方源码包
FetchContent_Declare(
    libsodium
    URL https://ghfast.top/https://github.com/jedisct1/libsodium/releases/download/1.0.20-RELEASE/libsodium-1.0.20.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(SODIUM_DISABLE_TESTS ON CACHE BOOL "" FORCE)
set(SODIUM_DISABLE_EXAMPLES ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(zlib libsodium)
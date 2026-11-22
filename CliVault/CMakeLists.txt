# =============================================================================
# CliVault subfolder CMakeLists.txt
# (put this INTO the "CliVault" subfolder, the same folder that holds main.cpp)
# Defines the executable and links the dependencies declared at the top level.
# =============================================================================

add_executable(CliVault main.cpp)

# Static-link macro for libsodium (prevents unresolved DLL import symbols).
target_compile_definitions(CliVault PRIVATE SODIUM_STATIC)

# Link the libraries brought in by FetchContent:
#   zlib target   -> zlibstatic
#   sodium target -> sodium
target_link_libraries(CliVault PRIVATE zlibstatic sodium)
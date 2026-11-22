#include <iostream>
#include <vector>
#include <string>
#include <zlib.h>
#include <sodium.h>

int main() {
    // ==========================================
    // 1. Verify zlib (Test one-step compression)
    // ==========================================
    std::string originalData = "Hello, this is a test for zlib compression!";

    // Pre-allocate the maximum buffer size required for compression
    uLong cap = compressBound(originalData.size());
    std::vector<Bytef> compressedData(cap);
    uLong compressedLen = cap;

    // Execute compression (Level 6 is the default balance level)
    int ret = compress2(compressedData.data(), &compressedLen,
        (const Bytef*)originalData.data(), originalData.size(), 6);

    if (ret == Z_OK) {
        std::cout << " [zlib Verification Success] Compression completed!" << std::endl;
        std::cout << "   Original Size: " << originalData.size() << " bytes" << std::endl;
        std::cout << "   Compressed Size: " << compressedLen << " bytes" << std::endl;
    }
    else {
        std::cerr << " [zlib Verification Failed] Compression error, code: " << ret << std::endl;
        return 1;
    }

    // ==========================================
    // 2. Verify libsodium (Test initialization and random number generation)
    // ==========================================
    if (sodium_init() < 0) {
        std::cerr << " [libsodium Verification Failed] Initialization failed!" << std::endl;
        return 1;
    }

    // Generate 16 bytes of random data
    std::vector<unsigned char> randomBytes(16);
    randombytes_buf(randomBytes.data(), randomBytes.size());

    std::cout << "\n [libsodium Verification Success] Initialization completed. Generated random bytes: ";
    for (unsigned char byte : randomBytes) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl; // Restore decimal output

    std::cout << "\n Congratulations! Both zlib and libsodium are successfully configured and working properly!" << std::endl;
    return 0;
}
//! Unit Tests for MPAGSCipher CaesarCipher interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Initialize with integer key value", "[integer key]") {

    CaesarCipher caesarCipher{12};

    SECTION("Correctly encrypts input text") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "MNOPQRSTUVWXYZ");
    }

    SECTION("Correctly wraps around alphabet on encyrption") {
        std::string inputText{"MNOPQRSTUVWXYZ"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "YZABCDEFGHIJKL");
    }

    SECTION("Correctly decrypts input text") {
        std::string inputText{"MNOPQRSTUVWXYZ"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "ABCDEFGHIJKLMN");
    }

    SECTION("Correctly wraps around alphabet on decryption") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "OPQRSTUVWXYZAB");
    }

}

TEST_CASE("Initialize with valid string key value", "[string key]") {

    CaesarCipher caesarCipher{"12"};

    SECTION("Correctly encrypts input text") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "MNOPQRSTUVWXYZ");
    }

    SECTION("Correctly wraps around alphabet on encyrption") {
        std::string inputText{"MNOPQRSTUVWXYZ"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "YZABCDEFGHIJKL");
    }

    SECTION("Correctly decrypts input text") {
        std::string inputText{"MNOPQRSTUVWXYZ"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "ABCDEFGHIJKLMN");
    }

    SECTION("Correctly wraps around alphabet on decryption") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "OPQRSTUVWXYZAB");
    }

}

TEST_CASE("Initialize with invalid string key value", "[string key]") {

    CaesarCipher caesarCipher{"12a"};

    SECTION("Correctly encrypts input text with key at default value of 0") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Encrypt)};
        REQUIRE(outputText == "ABCDEFGHIJKLMN");
    }

    SECTION("Correctly decrypts input text with key at default value of 0") {
        std::string inputText{"ABCDEFGHIJKLMN"};
        std::string outputText{caesarCipher.applyCipher(inputText, CipherMode::Decrypt)};
        REQUIRE(outputText == "ABCDEFGHIJKLMN");
    }

}
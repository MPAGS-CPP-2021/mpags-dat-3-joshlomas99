//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Command line arguments edit ProgramSettings correctly", "[command line args]") {

    ProgramSettings mpagsCipherSettings{false, false, "", "", "", CipherMode::Encrypt};

    SECTION("No command line args provided") {
        const std::vector<std::string> cmdLineArgs{"argv"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!mpagsCipherSettings.helpRequested);
        REQUIRE(!mpagsCipherSettings.versionRequested);
        REQUIRE(mpagsCipherSettings.inputFile == "");
        REQUIRE(mpagsCipherSettings.outputFile == "");
        REQUIRE(mpagsCipherSettings.cipherKey == "");
        REQUIRE(mpagsCipherSettings.encrypt == CipherMode::Encrypt);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Help requested short") {
        const std::vector<std::string> cmdLineArgs{"argv", "-h"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.helpRequested);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Help requested long") {
        const std::vector<std::string> cmdLineArgs{"argv", "--help"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.helpRequested);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Version requested") {
        const std::vector<std::string> cmdLineArgs{"argv", "--version"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.versionRequested);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Input file provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-i", "input.in"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!mpagsCipherSettings.inputFile.empty());
        REQUIRE(mpagsCipherSettings.inputFile == "input.in");
        REQUIRE(cmdLineStatus);
    }

    SECTION("Input file command used but filename not provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-i"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!cmdLineStatus);
    }

    SECTION("Output file provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-o", "output.out"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!mpagsCipherSettings.outputFile.empty());
        REQUIRE(mpagsCipherSettings.outputFile == "output.out");
        REQUIRE(cmdLineStatus);
    }

    SECTION("Output file command used but filename not provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-o"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!cmdLineStatus);
    }

    SECTION("Valid Key value provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-k", "6510"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.cipherKey == "6510");
        REQUIRE(cmdLineStatus);
    }

    SECTION("Key command used but value not provided") {
        const std::vector<std::string> cmdLineArgs{"argv", "-k"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!cmdLineStatus);
    }

    SECTION("Setting Encryption mode - encrypt") {
        const std::vector<std::string> cmdLineArgs{"argv", "--encrypt"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.encrypt == CipherMode::Encrypt);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Setting Encryption mode - decrypt") {
        const std::vector<std::string> cmdLineArgs{"argv", "--decrypt"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(mpagsCipherSettings.encrypt == CipherMode::Decrypt);
        REQUIRE(cmdLineStatus);
    }

    SECTION("Invalid command line arg short") {
        const std::vector<std::string> cmdLineArgs{"argv", "-u"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!cmdLineStatus);
    }

    SECTION("Invalid command line arg long") {
        const std::vector<std::string> cmdLineArgs{"argv", "--unknown"};
        const bool cmdLineStatus{processCommandLine(cmdLineArgs, mpagsCipherSettings)};

        REQUIRE(!cmdLineStatus);
    }
}

#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

struct ProgramSettings {
    bool helpRequested; ///< Whether or not help was requested.
    bool versionRequested; ///< Whether or not the version number was requested.
    std::string inputFile; ///< Name of input file.
    std::string outputFile; ///< Name of output file.
    std::string cipherKey; ///< Cipher key.
    bool encrypt; ///< Whether to encrypt (true) or decrypt (false).
};

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& mpagsCipherSettings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
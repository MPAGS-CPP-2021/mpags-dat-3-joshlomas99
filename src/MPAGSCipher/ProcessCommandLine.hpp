#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

struct ProgramSettings {
    bool helpRequested;
    bool versionRequested;
    std::string inputFile;
    std::string outputFile;
    std::string cipherKey;
    bool encrypt;
};

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& MPAGSCipherSettings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
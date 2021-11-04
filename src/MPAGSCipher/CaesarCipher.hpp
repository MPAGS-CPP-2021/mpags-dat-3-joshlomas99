#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"
#include <string>
#include <vector>

class CaesarCipher {
    public:
        /// Initialise CaesarCipher with integer key.
        explicit CaesarCipher(const std::size_t cipherKey);
        /// Initialise CaesarCipher with string key, i.e. from command line.
        explicit CaesarCipher(const std::string cipherKey);
        
        /// Apply cipher to input text.
        std::string applyCipher(const std::string& inputText,
                                const CipherMode encrypt) const;
    
    private:
        const std::vector<char> alphabet_{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; ///< Alphabet container.
        const std::size_t alphabetSize_{alphabet_.size()}; ///< Size of alphabet.
        std::size_t key_{0}; ///< Cipher key.
};

#endif    // MPAGSCIPHER_CAESARCIPHER_HPP
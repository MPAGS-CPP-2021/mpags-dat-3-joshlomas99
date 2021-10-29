#include "CaesarCipher.hpp"

#include <iostream>
#include <string>

CaesarCipher::CaesarCipher(const std::size_t cipherKey) : key_{cipherKey}
{
}

CaesarCipher::CaesarCipher(const std::string cipherKey)
{
    if (!cipherKey.empty()){
        // Before doing the conversion we should check that the string contains a
        // valid positive integer.
        // Here we do that by looping through each character and checking that it
        // is a digit. What is rather hard to check is whether the number is too
        // large to be represented by an unsigned long, so we've omitted that for
        // the time being.
        // (Since the conversion function std::stoul will throw an exception if the
        // string does not represent a valid unsigned long, we could check for and
        // handled that instead but we only cover exceptions very briefly on the
        // final day of this course - they are a very complex area of C++ that
        // could take an entire course on their own!)
        for (const auto& elem : cipherKey) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << cipherKey
                    << ") could not be successfully converted" << std::endl;
                return;
            }
        }
        
        key_ = std::stoul(cipherKey);
    }
}
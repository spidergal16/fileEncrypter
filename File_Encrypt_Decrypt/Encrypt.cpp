#include "Encrypt.h"

std::string Encrypt::encryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key)
{
    
}

unsigned char Encrypt::encryptByte(unsigned char orgByte, const std::string& key)
{    
    int keyVal = 0;
    unsigned char encryptedByte = ' ';

    // Get value of the key
    for (char tempCh : key)
    {
        keyVal += tempCh;
    }

    // XOR the byte
    encryptedByte = orgByte ^ keyVal;

    return encryptedByte;
}

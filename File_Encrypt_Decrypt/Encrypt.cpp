#include "Encrypt.h"

std::string Encrypt::encryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key)
{
    std::ifstream fileToEncrypt(srcFile, std::ios::binary);
    char byteRead = ' ';
    char encryptedByte = ' ';
    std::string outputData = "";
    std::string dstFilePath = "";

    if (!fileToEncrypt)
    {
        throw std::invalid_argument("Error opening file!");
    }

    while (fileToEncrypt.get(byteRead))
    {
        encryptedByte = encryptByte(byteRead, key);
        outputData += encryptedByte;
    }

    if (dstFile.empty())
    {
        dstFilePath = "Encrypted_";
        dstFilePath += srcFile;
        std::ofstream outputFile(dstFilePath);
        outputFile << outputData;
    }

    else
    {
        dstFilePath = dstFile;
        std::ofstream outputFile(dstFilePath);
        outputFile << outputData;
    }

    return dstFilePath;
}

char Encrypt::encryptByte(char orgByte, const std::string& key)
{    
    int keyVal = 0;
    char encryptedByte = ' ';

    // Get value of the key
    for (char tempCh : key)
    {
        keyVal += tempCh;
    }

    // XOR the byte
    encryptedByte = orgByte ^ keyVal;

    return encryptedByte;
}

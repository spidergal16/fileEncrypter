#include "Encrypt.h"

std::string Encrypt::encryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key)
{
    int keyVal = 0;
    int i = 0;
    std::ifstream fileToEncrypt(srcFile, std::ios::binary);
    char byteRead = ' ';
    char encryptedByte = ' ';
    std::string outputData = "";
    std::string dstFilePath = "";
    
    // Get only the file name and extension from src file
    std::filesystem::path filePath(srcFile);
    std::string fileName = filePath.filename().string();

    if (!fileToEncrypt)
    {
        throw std::invalid_argument("Error opening file!");
    }

    if (key.empty())
    {
        throw std::invalid_argument("Key is empty!");
    }

    while (fileToEncrypt.get(byteRead))
    {
        keyVal = key[i % key.size()];
        encryptedByte = encryptByte(byteRead, keyVal);
        outputData += encryptedByte;
        i++;
    }

    fileToEncrypt.close();

    if (dstFile.empty())
    {
        dstFilePath = "Encrypted_";
        dstFilePath += fileName;
        std::ofstream outputFile(dstFilePath);
        outputFile << outputData;
        outputFile.close();
        
    }

    else
    {
        dstFilePath = dstFile;
        std::ofstream outputFile(dstFilePath);
        outputFile << outputData;
        outputFile.close();
    }

    return dstFilePath;
}

char Encrypt::encryptByte(char orgByte, int key)
{    
    // XOR the byte
    char encryptedByte = (orgByte ^ key) + key;

    return encryptedByte;
}

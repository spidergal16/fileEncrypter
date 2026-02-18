#include "Decrypt.h"

std::string Decrypt::decryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key)
{
    int i = 0;
    int keyVal = 0;
    std::ifstream fileToDecrypt(srcFile, std::ios::binary);
    char byteRead = ' ';
    char decryptedByte = ' ';
    std::string outputData = "";
    std::string dstFilePath = "";

    // Get only the file name and extension from src file
    std::filesystem::path filePath(srcFile);
    std::string fileName = filePath.filename().string();

    if (!fileToDecrypt)
    {
        throw std::invalid_argument("Error opening file!");
    }

    if (key.empty())
    {
        throw std::invalid_argument("Key is empty!");
    }

    while (fileToDecrypt.get(byteRead))
    {
        keyVal = key[i % key.size()];
        decryptedByte = decryptByte(byteRead, keyVal);
        outputData += decryptedByte;
    }

    fileToDecrypt.close();

    if (dstFile.empty())
    {
        dstFilePath = "Decrypted_";
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

char Decrypt::decryptByte(char orgByte, int key)
{
    // XOR the byte
    char decryptedByte = (orgByte - key) ^ key;

    return decryptedByte;
}

#include <iostream>
#include <string>

#include "Encrypt.h"
#include "Decrypt.h"

int main()
{
	std::string key = "";
	std::string filePath = "";

	std::cout << "Enter the file path to encrypt: " << std::endl;
	std::cin >> filePath;

	std::cout << "Enter the key to encrypt with: " << std::endl;
	std::cin >> key;

	Decrypt::decryptFile(Encrypt::encryptFile(filePath, "", key), "", key);

	return 0;
}
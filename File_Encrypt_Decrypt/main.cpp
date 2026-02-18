#include <iostream>
#include <fstream>
#include <string>

#include "Encrypt.h"
#include "Decrypt.h"

int main()
{
	std::string key = "";
	std::string filePath = "";
	int saveKey = 0;

	std::cout << "Enter the file path to encrypt: " << std::endl;
	std::cin >> filePath;

	std::cout << "Enter the key to encrypt with (no spaces): " << std::endl;
	std::cin >> key;	

	std::cout << "Do you want to save the key into a file? (0 - no, other number - yes): " << std::endl;	
	std::cin >> saveKey;

	Decrypt::decryptFile(Encrypt::encryptFile(filePath, "", key), "", key);

	if (saveKey)
	{
		std::ofstream keyFile("key.txt");
		keyFile << key;
		keyFile.close();
	}

	return 0;
}
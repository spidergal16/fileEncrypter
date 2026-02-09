#include <iostream>
#include <string>

#include "Encrypt.h"
#include "Decrypt.h"

int main()
{
	std::string filePath = "";

	std::cout << "Enter the file path to encrypt: " << std::endl;
	std::cin >> filePath;	

	Decrypt::decryptFile(Encrypt::encryptFile(filePath, "", "a"), "", "a");

	return 0;
}
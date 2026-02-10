#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <filesystem>


class Decrypt
{
public:
	/*
	Function to decrypt a file.
	input: srcFile - The path of the file to decrypt.
	dstFile (optional) - The path of the decrypted file.
	key - The word to use as a key for the decryption
	output: The path of the decrypted file.
	*/
	static std::string decryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key);

private:
	// Function to decrypt a single byte based on a given key.
	static char decryptByte(char orgByte, int key);


};
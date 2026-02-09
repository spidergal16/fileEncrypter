#pragma once
#include <fstream>
#include <iostream>
#include <string>

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>



class Encrypt
{
public:
	/*
	Function to encrypt a file.
	input: srcFile - The path of the file to encrypt.
	dstFile (optional) - The path of the encrypted file.
	key - The word to use as a key for the encryption
	output: The path of the encrypted file.
	*/
	static std::string encryptFile(const std::string& srcFile, const std::string& dstFile, const std::string& key);

private:
	// Function to encrypt a single byte based on a given key.
	static char encryptByte(char orgByte, int key);


};
/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#include <iostream>
#include <fstream>
#include "FileSystem/File.hpp"

FileSystem::File::File(const std::string &path)
: Path(path)
{
	if (!this->isFile())
		throw std::exception();
}

FileSystem::File::File(const FileSystem::Path &path)
	: Path(path)
{
	if (!this->isFile())
		throw std::exception();
}

/**
** Check if the Extension match
** @param find extension to find. For example "so".
** @return true when extension is found
*/
bool FileSystem::File::hasExtension(const std::string &find) const
{
	return this->getAbsolutePath().rfind(find) + find.length()
	== this->getAbsolutePath().length();
}

void FileSystem::File::create(void)
{
	std::ofstream outfile ("test.txt");
	outfile.close();
}

bool FileSystem::File::exist(void)
{
	return this->isFile();
}

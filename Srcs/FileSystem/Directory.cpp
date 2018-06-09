/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Directory
** Directory description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#include <iostream>
#include "FileSystem/Directory.hpp"

/*todo replace exception */
FileSystem::Directory::Directory(const std::string &path)
: Path(path)
{
//	if (!this->isDirectory())
//		throw std::exception();
}

FileSystem::Directory::Directory(FileSystem::Path &path)
	: Path(path)
{
//	if (!this->isDirectory())
//		throw std::exception();
}

std::vector<FileSystem::File> FileSystem::Directory::getFiles(bool recursive)
{
	std::vector<FileSystem::File>	files;

	(void)recursive;
	return files;
}

void FileSystem::Directory::_opendir(void)
{
	_dir = opendir(this->getName().c_str());
	if (!_dir)
		throw std::exception();
}

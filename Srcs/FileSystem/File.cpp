/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#include <iostream>
#include "FileSystem/File.hpp"


/*todo replace exception */
FileSystem::File::File(const std::string &path)
: Path(path)
{
	if (!this->isFile())
		throw std::exception();
}

FileSystem::File::File(FileSystem::Path &path)
	: Path(path)
{
	if (!this->isFile())
		throw std::exception();
}

/**
*
* @param find extension to find. For example "so".
* @return
*/
bool FileSystem::File::hasExtension(const std::string &find) const
{
	return _path.rfind(find) + find.length()
	== _path.length();
}

/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Path
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:24
*/

#include <string>
#include "FileSystem/Path.hpp"

FileSystem::Path::Path(const std::string &path)
: _path(path)
{}

bool FileSystem::Path::isFile(void) const
{
	FILE *file = fopen(_path.c_str(), "r");

	if (!file) {
		return false;
	}
	std::fclose(file);
	return true;
}

/**
*	todo: better casting
* @return the last element of the past
*/
std::string FileSystem::Path::getName(void) const
{
	size_t 		first;

	first = _path.find_last_of('/', _path.length() - 1);
	if (first == std::string::npos)
		return _path;
	return std::string(_path, first + 1, _path.length());
}

bool FileSystem::Path::isDirectory(void) const
{

	return false;
}

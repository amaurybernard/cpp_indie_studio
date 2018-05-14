/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <vector>
#include <dirent.h>
#include "FileSystem/Path.hpp"
#include "FileSystem/File.hpp"

namespace FileSystem {

	class Directory : public Path {
	public:
		Directory(const std::string &path);
		Directory(Path &path);

	public:
		std::vector<FileSystem::File> getFiles(bool recursive = false);

	private:
		void 	_opendir(void);

	private:
		DIR	*_dir;

	};
}

#endif /* !DIRECTORY_HPP*/

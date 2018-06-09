/*
** EPITECH PROJECT, 2017
**  cpp_arcade, File
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:59
*/

#ifndef CPP_ARCADE_FILE_HPP
#define CPP_ARCADE_FILE_HPP

#include "FileSystem/Path.hpp"
/*
** todo create exist... and system basics
**
*/
namespace FileSystem {

	class File : public Path {
	public:
		File(void) = default;
		File(const std::string &path);
		File(Path &path);

	public:
		bool	hasExtension(const std::string &find = nullptr) const;
	};
}

#endif /* !CPP_ARCADE_FILE_HPP*/

/*
** EPITECH PROJECT, 2017
**  cpp_arcade, Path
** File description:
**      Created by Amaury Bernard, the 30/03/18, at 17:24
*/

#ifndef CPP_ARCADE_PATH_HPP
#define CPP_ARCADE_PATH_HPP

#include <string>

namespace FileSystem {

	class Path {
	public:
		Path(void) = default;
		Path(const std::string &path);

	public:
		bool 		isFile(void) const;
		bool 		isDirectory(void) const;
		std::string getName(void) const;

	protected:
		std::string _path;
	};
}

#endif /* !CPP_ARCADE_PATH_HPP*/
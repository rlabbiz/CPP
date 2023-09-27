/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:30 by rlabbiz           #+#    #+#             */
/*   Updated: 2023/09/27 23:31:02 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string getNewLine(std::string line, std::string wordSearch, std::string wordReplace) {
	std::string::size_type	preindex;
	std::string::size_type	index;
	std::string::size_type	lastIndex;
	std::string				newLine;
	std::string				preWord;
	std::string				nextWord;

	index		= 0;
	preindex	= index;
	index = line.find(wordSearch, preindex);
	if (index == std::string::npos)
		return line;
	while (index != std::string::npos){
		preWord		= line.substr(preindex, index - preindex);
		newLine		+= preWord + wordReplace;
		preindex 	= index + wordSearch.length();
		lastIndex 	= index;
		index		= line.find(wordSearch, preindex);
	}
 	nextWord = line.substr(lastIndex + wordSearch.length(), line.length() - (index + wordSearch.length()));
	newLine		+= nextWord;
	return newLine;
}

int	main(int ac, char **av){
	if (ac != 4){
		std::cout << "bad arguments" << '\n';
		return 1;
	}
	std::string				fileName(av[1]);
	std::string				wordSearch(av[2]);
	std::string				wordReplace(av[3]);
	std::string				line;
	std::ifstream			file(av[1]);
	std::ofstream			newFile;

	newFile.open(fileName + ".replace", std::ios::trunc);
	if (!newFile.is_open() || !file.is_open()){
		std::cout << "can't open a file." << '\n';
		return 1;
	}
	while (std::getline(file, line)){
		newFile << getNewLine(line, wordSearch, wordReplace) << '\n';
	}
	file.close();
	newFile.close();
}

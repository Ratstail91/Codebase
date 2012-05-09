/* File Name: config_utility.cpp
 * Author: Kayne Ruse
 * Date: 4/4/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Codebase Library.
 * 
 * Codebase Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Codebase Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Codebase Library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     Load and process configuration values from a file.
*/
//#define _CRT_SECURE_NO_WARNINGS
#include <exception>
#include <fstream>
#include <string>
#include "config_utility.h"
using namespace std;

//-------------------------
//Preprocessor
//-------------------------

//BUGLIST: 1
#define RESERVED "__reserved"

//-------------------------
//Public access members
//-------------------------

void ConfigUtility::Load(const char* szFileName) {
	ifstream is(szFileName);

	if (!is.is_open()) {
		string sWhat = "Failed to open config file for reading: ";
		sWhat += szFileName;
		throw(exception(sWhat.c_str()));
	}

	string sBufferOne;
	string sBufferTwo;

	for (;;) { //forever
		//discard newlines/blank lines w/ whitespace
		while(
				is.peek() == '\r' ||
				is.peek() == '\n' ||
				is.peek() == '\t' ||
				is.peek() == ' '
			)
			is.ignore();

		//end of file
		if (is.eof())
			break;

		//skip comment lines
		if (is.peek() == '#') {
			while( !(is.peek() == '\r' || is.peek() == '\n' || is.eof()) )
				is.ignore();
			continue;
		}

		//read in the pair
		getline(is, sBufferOne,'=');
		getline(is, sBufferTwo);

		//trim the strings at the start & end
		while(sBufferOne[0] == '\t' || sBufferOne[0] == ' ')
			sBufferOne.erase(0, 1); //probably not needed
		while(sBufferTwo[0] == '\t' || sBufferTwo[0] == ' ')
			sBufferTwo.erase(0, 1);
		while(sBufferOne[sBufferOne.size()-1] == '\t' || sBufferOne[sBufferOne.size()-1] == ' ')
			sBufferOne.erase(sBufferOne.end()-1);
		while(sBufferTwo[sBufferTwo.size()-1] == '\t' || sBufferTwo[sBufferTwo.size()-1] == ' ')
			sBufferTwo.erase(sBufferTwo.end()-1);

		//save the pair
		(*this)[sBufferOne] = sBufferTwo;
	}

	is.close();
}

int ConfigUtility::Integer(const char* szKey) {
	return atoi((*this)[szKey].c_str());
}

double ConfigUtility::Real(const char* szKey) {
	return atof((*this)[szKey].c_str());
}

bool ConfigUtility::Boolean(const char* szKey) {
	if (! _stricmp( (*this)[szKey].c_str() , "true") )
		return true;

	if (! _stricmp( (*this)[szKey].c_str() , "false") )
		return false;

	string sWhat = "Incorrect boolean config argument: key: ";
	sWhat += szKey;
	sWhat += ", value: ";
	sWhat += (*this)[szKey];
	throw(exception(sWhat.c_str()));
}

//-------------------------
//Path system
//-------------------------

const char* ConfigUtility::ConcatPath(const char* szKey, const char* szFileName) {
	map<string, string>::iterator it = find(szKey);

	if (it == end()) {
		string sWhat = "Failed to find path key: ";
		sWhat += szKey;
		throw(exception(sWhat.c_str()));
	}

	//BUGLIST: 1
	(*this)[RESERVED] = it->second;
	(*this)[RESERVED] += szFileName;

	return (*this)[RESERVED].c_str();
}

const char* ConfigUtility::ConcatPathAndFile(const char* szKey1, const char* szKey2) {
	map<string, string>::iterator it1 = find(szKey1);
	map<string, string>::iterator it2 = find(szKey2);

	if (it1 == end()) {
		string sWhat = "Failed to find key: ";
		sWhat += szKey1;
		throw(exception(sWhat.c_str()));
	}

	if (it2 == end()) {
		string sWhat = "Failed to find key: ";
		sWhat += szKey2;
		throw(exception(sWhat.c_str()));
	}

	//BUGLIST: 1
	(*this)[RESERVED] = it1->second;
	(*this)[RESERVED] += it2->second;

	return (*this)[RESERVED].c_str();
}

/* File Name: config_utility.cpp
 * Author: Kayne Ruse
 * Date: 27/6/2012
 * Copyright: (c) Kayne Ruse 2012
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
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

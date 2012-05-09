/* File Name: config_utility.h
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
#ifndef KR_CONFIGUTILITY_H_
#define KR_CONFIGUTILITY_H_ 2012040401

#include <map>
#include <string>

class ConfigUtility : public std::map<std::string, std::string> {
public:
	/* Public access members */
	void Load		(const char* szFileName);
	int Integer		(const char* szKey);
	double Real		(const char* szKey);
	bool Boolean	(const char* szKey);

	/* Path system */
	const char* ConcatPath			(const char* szKey, const char* szFileName);
	const char* ConcatPathAndFile	(const char* szKey1, const char* szKey2);
};

#endif

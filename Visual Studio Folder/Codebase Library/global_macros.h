/* File Name: global_macros.h
 * Author: Kayne Ruse
 * Date: 14/5/2012
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
 *     A set of macros to automate repetitive code.
*/
#ifndef KR_GLOBALMACROS_H_
#define KR_GLOBALMACROS_H_

//usage: BP_MEMBER(GetFunction, SetFunction, dataType, variableName)
#define BP_MEMBER(GET, SET, TYPE, NAME)	\
private:								\
	TYPE NAME;							\
public:									\
	TYPE GET() { return NAME; };		\
	TYPE SET(TYPE _v) {return NAME = _v; }

//usage: dataType BP_DEPRECATED(FunctionName)(ParameterList)
#ifdef __GNUC__
//untested
#define BP_DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define BP_DEPRECATED(func) __declspec(deprecated) func
#else
//untested
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define BP_DEPRECATED(func) func
#endif

#endif

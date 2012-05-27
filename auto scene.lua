--[[

A good convention, he one that I use, is:

class nmae: "ClassName"
file name: "class_name" (note: no file extention!!)
preprocessor guard: "KR_CLASSNAME_H_"

]]--

--instructions
io.write("This generates the .h and .cpp files for codebase by Kayne Ruse. ")
io.write("It is designed specifically for decendants of BaseScene. ")
io.write("To keep it simple, the user must input the class name, file name and preprocessor guard. ")
io.write("There is little to no error checking in this script, so be careful!\n\n")

--get the input
io.write("Enter the class name: ")
className = io.read()
io.write("Enter file name: ")
fileName = io.read()
io.write("Enter preprocessor guard: ")
guard = io.read()


--open and write the header file
hFile = io.open( fileName .. ".h", "w")

if hFile == nil then print("Failed to open the header file for writing") return end



hFile:write(

"/* File Name: " .. fileName .. ".h\
 * Author: \
 * Date: \
 * Copyright: \
 * Description: \
*/\
#ifndef " .. guard .. "\
#define " .. guard .. "\
\
#include \"SDL.h\"\
#include \"base_scene.h\"\
#include \"scene_list.h\"\
\
class " .. className .. " : public BaseScene {\
public:\
	/* Public access members */\
	" .. className .. "();\
	virtual ~" .. className .. "();\
\
protected:\
	/* Frame loop members */\
	virtual void Head	();\
	virtual void Tail	();\
	virtual void Update	();\
	virtual void Render	(SDL_Surface* const);\
\
	/* Input loop members */\
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);\
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);\
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);\
	virtual void KeyDown			(SDL_KeyboardEvent const&);\
	virtual void KeyUp				(SDL_KeyboardEvent const&);\
\
	/* Members */\
	//...\
};\
\
#endif\
"

)

hFile:close()



--open and write the source file
hFile = io.open( fileName .. ".cpp", "w")

if hFile == nil then print("Failed to open the source file for writing") return end



hFile:write(

"/* File Name: " .. fileName .. ".cpp\
 * Author: \
 * Date: \
 * Copyright: \
 * Description: \
*/\
#include <iostream>\
#include \"" .. fileName .. ".h\"\
using namespace std;\
\
//-------------------------\
//Preprocessor directives\
//-------------------------\
\
#if KR_BASESCENE_H_ != 2012051601 // 16/5/2012, revision 1\
#error BaseScene version is incompatible with this scene\
#endif\
\
//-------------------------\
//Public access members\
//-------------------------\
\
" .. className .. "::" .. className .. "() {\
	//\
}\
\
" .. className .. "::~" .. className .. "() {\
	//\
}\
\
//-------------------------\
//Frame loop members\
//-------------------------\
\
void " .. className .. "::Head() {\
	//\
}\
\
void " .. className .. "::Tail() {\
	//\
}\
\
void " .. className .. "::Update() {\
	//\
}\
\
void " .. className .. "::Render(SDL_Surface* const pScreen) {\
	//\
}\
\
//-------------------------\
//Input loop members\
//-------------------------\
\
void " .. className .. "::MouseMotion(SDL_MouseMotionEvent const& rMotion) {\
	//\
}\
\
void " .. className .. "::MouseButtonDown(SDL_MouseButtonEvent const& rButton) {\
	//\
}\
\
void " .. className .. "::MouseButtonUp(SDL_MouseButtonEvent const& rButton) {\
	//\
}\
\
void " .. className .. "::KeyDown(SDL_KeyboardEvent const& rKey) {\
	switch(rKey.keysym.sym) {\
		case SDLK_ESCAPE:\
			QuitEvent();\
			break;\
\
		//...\
	};\
}\
\
void " .. className .. "::KeyUp(SDL_KeyboardEvent const& rKey) {\
	//\
}\
\
//-------------------------\
//Members\
//-------------------------\
\
//...\
\
"

)

hFile:close()

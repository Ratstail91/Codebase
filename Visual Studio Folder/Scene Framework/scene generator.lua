--instructions
io.write("Scene Generator - by Kayne Ruse\n\n")
io.write("my convention is:\n")

io.write("\tFile Name:\tscene_example (without the file extentions)\n")
io.write("\tAuthor:\t\tKayne Ruse\n")
io.write("\tGuard:\t\tKR_SCENEEXAMPLE_H_\n")
io.write("\tScene Name:\tSceneExample\n\n")

--input
io.write("Enter file name (w/o extentions): ")
fname = io.read()
io.write("Enter Author: ")
author = io.read()
io.write("Enter Guard: ")
guard = io.read()
io.write("Enter Scene Name: ")
sname = io.read()

--output the header
hFile = io.open(fname .. ".h", "w")

if hFile == nil then print("Failed to open the header file for writing") return end

hFile:write(

"/* File Name: " .. fname .. ".h\
 * Author: " .. author .. "\
 * Date (dd/mm/yyyy): " .. os.date("%d/%m/%Y") .. "\
 * Copyright: (c) " .. author .. " " .. os.date("%Y") .. "\
 *\
 * This software is provided 'as-is', without any express or implied\
 * warranty. In no event will the authors be held liable for any damages\
 * arising from the use of this software.\
 *\
 * Permission is granted to anyone to use this software for any purpose,\
 * including commercial applications, and to alter it and redistribute it\
 * freely, subject to the following restrictions:\
 *\
 * 1. The origin of this software must not be misrepresented; you must not\
 * claim that you wrote the original software. If you use this software\
 * in a product, an acknowledgment in the product documentation would be\
 * appreciated but is not required.\
 *\
 * 2. Altered source versions must be plainly marked as such, and must not be\
 * misrepresented as being the original software.\
 *\
 * 3. This notice may not be removed or altered from any source\
 * distribution.\
 *\
 * Description:\
 *     ...\
*/\
#ifndef " .. guard .. "\
#define " .. guard .. "\
\
#include \"scene.h\"\
\
class " .. sname .. " : public Scene {\
public:\
	/* Public access members */\
	" .. sname .. "();\
	virtual ~" .. sname .. "();\
\
protected:\
	/* Frame loop */\
	virtual void FrameStart();\
	virtual void FrameEnd();\
	virtual void Update();\
	virtual void Render(SDL_Surface* const);\
\
	/* Event handlers */\
	virtual void MouseMotion		(SDL_MouseMotionEvent const&);\
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);\
	virtual void MouseButtonUp		(SDL_MouseButtonEvent const&);\
	virtual void KeyDown			(SDL_KeyboardEvent const&);\
	virtual void KeyUp				(SDL_KeyboardEvent const&);\
};\
\
#endif\
"

)

hFile:close()

--output the source
hFile = io.open(fname .. ".cpp", "w")

if hFile == nil then print("Failed to open the source file for writing") return end

hFile:write(
"/* File Name: " .. fname .. ".cpp\
 * Author: " .. author .. "\
 * Date (dd/mm/yyyy): " .. os.date("%d/%m/%Y") .. "\
 * Copyright: (c) " .. author .. " " .. os.date("%Y") .. "\
 *\
 * This software is provided 'as-is', without any express or implied\
 * warranty. In no event will the authors be held liable for any damages\
 * arising from the use of this software.\
 *\
 * Permission is granted to anyone to use this software for any purpose,\
 * including commercial applications, and to alter it and redistribute it\
 * freely, subject to the following restrictions:\
 *\
 * 1. The origin of this software must not be misrepresented; you must not\
 * claim that you wrote the original software. If you use this software\
 * in a product, an acknowledgment in the product documentation would be\
 * appreciated but is not required.\
 *\
 * 2. Altered source versions must be plainly marked as such, and must not be\
 * misrepresented as being the original software.\
 *\
 * 3. This notice may not be removed or altered from any source\
 * distribution.\
 *\
 * Description:\
 *     ...\
*/\
#include \"" .. fname .. ".h\"\
\
//-------------------------\
//Public access members\
//-------------------------\
\
" .. sname .. "::" .. sname .. "() {\
	//\
}\
\
" .. sname .. "::~" .. sname .. "() {\
	//\
}\
\
//-------------------------\
//Frame loop\
//-------------------------\
\
void " .. sname .. "::FrameStart() {\
	//\
}\
\
void " .. sname .. "::FrameEnd() {\
	//\
}\
\
void " .. sname .. "::Update() {\
	//\
}\
\
void " .. sname .. "::Render(SDL_Surface* const) {\
	//\
}\
\
//-------------------------\
//Event handlers\
//-------------------------\
\
void " .. sname .. "::MouseMotion(SDL_MouseMotionEvent const& rMotion) {\
	//\
}\
\
void " .. sname .. "::MouseButtonDown(SDL_MouseButtonEvent const& rButton) {\
	//\
}\
\
void " .. sname .. "::MouseButtonUp(SDL_MouseButtonEvent const& rButton) {\
	//\
}\
\
void " .. sname .. "::KeyDown(SDL_KeyboardEvent const& rKey) {\
	switch(rKey.keysym.sym) {\
		case SDLK_ESCAPE:\
			QuitEvent();\
			break;\
	}\
}\
\
void " .. sname .. "::KeyUp(SDL_KeyboardEvent const& rKey) {\
	//\
}\
"
)

hFile:close()

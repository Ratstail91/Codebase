/* File Name: main_menu.h
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 23/09/2012
 * Copyright: ...
 * Description: ...
*/
#ifndef KR_MAINMENU_H_
#define KR_MAINMENU_H_

#include "config_utility.h"

#include "scene.h"

#include "button.h"

class MainMenu : public Scene {
public:
	/* Public access members */
	MainMenu(ConfigUtility*);
	virtual ~MainMenu();

protected:
	/* Frame loop */
	virtual void Render(SDL_Surface* const);

	/* Event handlers */
	virtual void MouseButtonDown	(SDL_MouseButtonEvent const&);
	virtual void KeyDown			(SDL_KeyboardEvent const&);

	/* Members */
	ConfigUtility* const pConfig;
	Button start;
	Button quit;
};

#endif

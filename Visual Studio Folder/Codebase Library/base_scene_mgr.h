/* File Name: base_scene_mgr.h
 * Author: Kayne Ruse
 * Date: 3/1/2012
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
 *     The base class for managing a series of classes derived from BaseScene.
*/
#ifndef KR_BASESCENEMGR_H_
#define KR_BASESCENEMGR_H_ 2012010301

#include "base_scene.h"

class BaseSceneMgr {
public:
	/* Public access members */
	virtual void Init();
	virtual void Loop();
	virtual void Quit();

protected:
	/* Protected access members */
	BaseSceneMgr();
	virtual ~BaseSceneMgr();

	/* Accessors and mutators */
	BaseScene* SetScene(BaseScene*);
	BaseScene* GetScene();
	int SetNext(int);
	int GetNext();

	/* Scene management members */
	virtual void LoadScene() =0;
	virtual void UnloadScene();

private:
	BaseScene* m_pScene;
	int m_iNext;
};

#endif

/* File Name: scene_mgr.h
 * Copyright: (c) Kayne Ruse, all rights reserved.
 * Author: Kayne Ruse
 * Date: 
 * Description: 
*/
#ifndef KR_SCENEMGR_H_
#define KR_SCENEMGR_H_

#include "singleton.h"
#include "base_scene_mgr.h"
#include "base_scene.h"
#include "scene_list.h"

class SceneMgr : public BaseSceneMgr {
public:
	/* Public access members */
//	virtual void Init();
//	virtual void Loop();
//	virtual void Quit();

protected:
	/* Protected access members */
	SceneMgr();
	virtual ~SceneMgr();

	virtual void LoadScene();

	/* Friends */
	friend class Singleton<SceneMgr>;
};

#endif

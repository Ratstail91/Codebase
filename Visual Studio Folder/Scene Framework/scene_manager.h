#ifndef KR_SCENEMANAGER_H_
#define KR_SCENEMANAGER_H_

#include "SDL.h"
#include "scene.h"
#include "scene_list.h"

class SceneManager {
public:
	/* Public access members */
	SceneManager();
	~SceneManager();

	void Init();
	void Proc();
	void Quit();

private:
	/* Private access members */
	void LoadScene(SceneList iSceneIndex);
	void UnloadScene();

	Scene* m_pActiveScene;
};

#endif

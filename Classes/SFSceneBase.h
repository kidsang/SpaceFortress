/*------------------------------------------
  Author: tuwenxiang
  File: SFSceneBase.h
  Date: 2014/05/03
------------------------------------------*/

#pragma once

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class SFSceneBase : public Scene
{

public:
	SFSceneBase(void);
	virtual ~SFSceneBase(void);

    CREATE_FUNC(SFSceneBase);

	void switchToScene(Scene* pScene);

protected:
	Node* _dragNode;
};


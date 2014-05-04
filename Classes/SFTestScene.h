/*------------------------------------------
  Author: tuwenxiang
  File: SFTestScene.h
  Date: 2014/05/03
------------------------------------------*/

#pragma once

#include "SFSceneBase.h"

class SFTestScene :	public SFSceneBase
{
public:
	SFTestScene(void);
	~SFTestScene(void);
	virtual bool init() override;
    CREATE_FUNC(SFTestScene);

    void menuCloseCallback(cocos2d::Ref* pSender);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

protected:

};


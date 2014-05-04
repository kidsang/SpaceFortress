#include "SFSceneBase.h"

SFSceneBase::SFSceneBase(void)
{
}


SFSceneBase::~SFSceneBase(void)
{
}

void SFSceneBase::switchToScene(Scene* pScene)
{
	Director* pDirector = Director::getInstance();

	if (pDirector->getRunningScene())
		pDirector->replaceScene(pScene);
	else
		pDirector->runWithScene(pScene);
}

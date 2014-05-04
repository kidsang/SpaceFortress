#include "SFTestScene.h"


SFTestScene::SFTestScene(void)
{
}


SFTestScene::~SFTestScene(void)
{
}

bool SFTestScene::init()
{
	//SFSceneBase::init();
	Scene::initWithPhysics();

	Director* pDirector = Director::getInstance();

	Layer* pLayer = Layer::create();
	addChild(pLayer);

	Size visibleSize = pDirector->getVisibleSize();
	Point origin = pDirector->getVisibleOrigin();

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(SFTestScene::menuCloseCallback, this));
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
								origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	pLayer->addChild(menu);

	auto world = getPhysicsWorld();
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	world->setGravity(Vect::ZERO);

	auto ground = Node::create();
	Point points[5];
	points[0].setPoint(50, 50);
	points[1].setPoint(visibleSize.width - 50, 50);
	points[2].setPoint(visibleSize.width - 50, visibleSize.height - 50);
	points[3].setPoint(50, visibleSize.height - 50);
	points[4].setPoint(50, 50);
	ground->setPhysicsBody(PhysicsBody::createEdgeChain(points, _countof(points)));
	pLayer->addChild(ground);

	auto ball = Sprite::create("CloseNormal.png");
	ball->setTag(100);
	ball->setPhysicsBody(PhysicsBody::createCircle(20));
	ball->setPosition(200, 200);
	pLayer->addChild(ball);
	

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(SFTestScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SFTestScene::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(SFTestScene::onTouchEnded, this);
	pDirector->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

void SFTestScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

bool SFTestScene::onTouchBegan(Touch* touch, Event* event)
{
	auto location = touch->getLocation();
	auto world = getPhysicsWorld();
	auto shape = world->getShape(location);

	if (shape == nullptr)
		return false;

	auto body = shape->getBody();
	if (body == nullptr)
		return false;

	auto node = body->getNode();
	if (node == nullptr)
		return false;

	node->setPosition(location);
	_dragNode = node;

	return true;
}

void SFTestScene::onTouchMoved(Touch* touch, Event* event)
{
	if (_dragNode == nullptr)
		return;

	auto location = touch->getLocation();
	_dragNode->setPosition(location);
}

void SFTestScene::onTouchEnded(Touch* touch, Event* event)
{
	_dragNode = nullptr;
}

#include "ZRBScene.h"

cocos2d::Scene * ZRBScene::sceneCreate( )
{
	USING_NS_CC;

	auto scene = Scene::create( );

	//auto keyboard = EventListenerKeyboard::create( );
	//keyboard->onKeyReleased = [ ] ( EventKeyboard::KeyCode key , Event * )
	//{
	//	if ( EventKeyboard::KeyCode::KEY_ESCAPE == key )
	//	{
	//		Director::getInstance( )->end( );
	//	}
	//};
	//_eventDispatcher->addEventListenerWithFixedPriority( keyboard , 1 );

	return scene;
}
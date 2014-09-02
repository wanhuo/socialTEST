
#include "ZRBScene.h"

cocos2d::Scene * ZRBScene::sceneCreate( )
{
	USING_NS_CC;

	auto scene = Scene::create( );

	// TODO: ¼ÓÔØÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadBackgroundMusic( "background.wav" );
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "gem.wav" );
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "background.caf" );

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
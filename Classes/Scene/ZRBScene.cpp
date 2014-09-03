
#include "ZRBScene.h"

cocos2d::Scene * ZRBScene::sceneCreate( )
{
	USING_NS_CC;

	auto scene = Scene::create( );

	// TODO: ¼ÓÔØÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadBackgroundMusic( "background.wav" );
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "gem.wav" );
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadEffect( "background.caf" );

	scene->addChild( ZRBHomeLayer::create() );
	
	return scene;
}
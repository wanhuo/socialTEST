
#include "ZRBScene.h"

cocos2d::Scene * ZRBScene::sceneCreate( )
{
	USING_NS_CC;

	auto scene = Scene::create( );

	// TODO: ¼ÓÔØÒôÀÖ
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance( );

	audio->preloadBackgroundMusic( ZRBLanguage::getValue( "Music_Bg" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Btclick" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Gold" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Jump" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Die" ) );

	audio->playBackgroundMusic( ZRBLanguage::getValue( "Music_Bg" ) , true );
	audio->pauseBackgroundMusic( );
	audio->pauseAllEffects( );
	
	if ( ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_MUSIC ) )
	{
		audio->resumeBackgroundMusic( );
	}


	if ( ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_SOUND ) )
	{
		audio->resumeAllEffects( );
	}


	scene->addChild( ZRBHomeLayer::create() );
	
	return scene;
}
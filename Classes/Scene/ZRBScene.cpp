
#include "ZRBScene.h"

cocos2d::Scene * ZRBScene::sceneCreate( )
{
	auto scene = Scene::create( );

	// TODO: 加载音乐
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance( );

	audio->preloadBackgroundMusic( ZRBLanguage::getValue( "Music_Bg" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Btclick" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Gold" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Jump" ) );
	audio->preloadEffect( ZRBLanguage::getValue( "Music_Die" ) );

	audio->playBackgroundMusic( ZRBLanguage::getValue( "Music_Bg" ) , true );
	audio->pauseBackgroundMusic( );
	
	if ( ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_MUSIC ) )
	{
		audio->resumeBackgroundMusic( );
	}


	scene->addChild( ZRBHomeLayer::create() );
	
	return scene;
}

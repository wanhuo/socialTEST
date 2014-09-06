
#include "ZRBHomeLayer.h"

#include "../ZRBGame/ZRBGameLayer/ZRBGameLayer.h"

ZRBHomeLayer::ZRBHomeLayer( )
{
}

ZRBHomeLayer::~ZRBHomeLayer( )
{
}


bool ZRBHomeLayer::init( )
{
	if ( !Layer::init() )
	{
		return false;
	}

	SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "homeMenu.plist" , "homeMenu.png" );
	SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "gameFinish_Layer.plist" , "gameFinish_Layer.png" );

	// 取出保存的数据
	switch ( ZRBUserDate::getInstance( )->getDateInt( KEY_CHECK_ROLE ) )
	{
		case 0:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroDragon( ) );
			break;

		case 1:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroSnail( ) );
			break;

		case 2:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroPink( ) );
			break;

		default:
			break;
	}

	this->addChild( ZRBPageView::create( ) );


	auto keyboard = EventListenerKeyboard::create( );
	keyboard->onKeyReleased = [ ] ( EventKeyboard::KeyCode key , Event * )
	{
		if ( EventKeyboard::KeyCode::KEY_ESCAPE == key )
		{
			Director::getInstance( )->end( );
		}
	};
	_eventDispatcher->addEventListenerWithFixedPriority( keyboard , 1 );


	return true;
}
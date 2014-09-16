
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
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroTropius( ) );
			break;

		case 1:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroSpinarak( ) );
			break;

		case 2:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroHoot( ) );
			break;

		case 3:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroSpoink( ) );
			break;

		case 4:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroMagcargo( ) );
			break;

		case 5:
			ZRBTheme::setCurrentHero( ZRBTheme::getHeroGrotle( ) );
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
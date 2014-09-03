
#include "ZRBHomeLayer.h"

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


	auto mes = ZRBMessageLayer::create( );
	mes->setMessageLabel( "ColorJump" );
	this->addChild( mes );



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
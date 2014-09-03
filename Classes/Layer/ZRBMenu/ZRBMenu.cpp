
#include "ZRBMenu.h"


#include "ZRBMenu.h"

extern int gGold;

bool ZRBMenu::init( )
{

	if ( !Layer::init( ) )
	{
		return false;
	}

	// Add spriteframecache
	SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "homeMenu.plist" );
	setBatchNode( SpriteBatchNode::create( "homeMenu.png" ) );
	this->addChild( getBatchNode( ) );
	//  TODO: ģʽȡ��
	// ��ȡ�û�ѡ��ģʽ
	//    pModel = UserDate::getInstance()->getDateBool(KEY_CHECK_MODEL);

	// Create button
	pSetbutten = MenuItemImage::create( );
	// Set picture
	pSetbutten->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "setbutten.png" ) );

	pKtplay = MenuItemImage::create( );
	pKtplay->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "regainbuy.png" ) );

	pBegin = MenuItemImage::create( );
	pBegin->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "begin.png" ) );

	pMarket = MenuItemImage::create( );
	pMarket->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "market.png" ) );

	pCharts = MenuItemImage::create( );
	pCharts->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "charts.png" ) );

	pAddGold = MenuItemImage::create( );
	pAddGold->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "gold_add.png" ) );
	//  TODO: ģʽȡ��    
	//    pModelEndless = MenuItemImage::create();
	//
	//    pModelTime = MenuItemImage::create();
	//    
	//    if (pModel)
	//    {
	//        pModelEndless->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_endless_checked.png"));
	//        pModelTime->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_time.png"));
	//
	//    }
	//    else
	//    {
	//        // Change the model button pictrue
	//        pModelEndless->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_endless.png"));
	//        
	//        pModelTime->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_time_checked.png"));
	//    }
	//

	// Get size of begin button
	size = pBegin->getContentSize( );

	// Set underlying menu anchorpoint (0.5, 0)
	pSetbutten->setAnchorPoint( Point( 0 , 0 ) );
	pKtplay->setAnchorPoint( Point( 0 , 0 ) );
	pBegin->setAnchorPoint( Point( 0 , 0 ) );
	pMarket->setAnchorPoint( Point( 0 , 0 ) );
	pCharts->setAnchorPoint( Point( 0 , 0 ) );
	// Set superincumbent menu anchorpoint (0.5, 1)
	//  TODO: ģʽȡ��
	//    pModelEndless->setAnchorPoint(Point(0.5, 1));
	//    pModelTime->setAnchorPoint(Point(0.5, 1));


	// Set button posintion
	pSetbutten->setPosition( 0 , 0 );
	pKtplay->setPosition( pSetbutten->getContentSize( ).width , 0 );
	pBegin->setPosition( pKtplay->getContentSize( ).width + pKtplay->getPositionX( ) , 0 );
	pMarket->setPosition( pBegin->getContentSize( ).width + pBegin->getPositionX( ) , 0 );
	pCharts->setPosition( pMarket->getContentSize( ).width + pMarket->getPositionX( ) , 0 );
	//  TODO: ģʽȡ��
	//    pModelEndless->setPosition(102, ZRB_VISIBLE_SIZE.height);
	//    pModelTime->setPosition(238.5, ZRB_VISIBLE_SIZE.height);
	pAddGold->setPosition( ZRB_VISIBLE_SIZE.width * 0.92 , ZRB_VISIBLE_SIZE.height * 0.95 );


	// Add sprite do for label background
	auto gold = Sprite::createWithSpriteFrameName( "gold_bg.png" );
	gold->setAnchorPoint( Vec2( 0 , 0 ) );
	gold->setPosition( -190 , 0 );

	// Create label 
	pGold = Label::createWithTTF( String::createWithFormat( "%d" , ZRBUserDate::getInstance( )->getDateInt( KEY_DATA_GOLDNUM ) )->getCString( ) , "customfout.otf" , 30 );
	pGold->setColor( Color3B( 0 , 0 , 0 ) );
	pGold->setPosition( 122 , 24 );

	// Add label to gold
	gold->addChild( pGold );
	// Add gold to  bautton 'pSddGold'
	pAddGold->addChild( gold , -1 );

	// Set menu button callback function
	pSetbutten->setCallback( CC_CALLBACK_0( ZRBMenu::setting , this ) );
	pKtplay->setCallback( CC_CALLBACK_0( ZRBMenu::Ktplay , this ) );
	pBegin->setCallback( CC_CALLBACK_1( ZRBMenu::begainGame , this ) );
	pMarket->setCallback( CC_CALLBACK_0( ZRBMenu::market , this ) );
	pCharts->setCallback( CC_CALLBACK_0( ZRBMenu::charts , this ) );
	//  TODO: ģʽȡ��
	//    pModelEndless->setCallback(CC_CALLBACK_0(ZRBMenu::modelEndless, this));
	//    pModelTime->setCallback(CC_CALLBACK_0(ZRBMenu::modelTime, this));
	pAddGold->setCallback( CC_CALLBACK_0( ZRBMenu::addGold , this ) );


	// pSetbutten pKtplay pBegin pMarket pCharts  add the under menu
	pMenuDown = Menu::create( pSetbutten , pKtplay , pBegin , pMarket , pCharts , nullptr );
	pMenuDown->setPosition( 0 , -200 );
	this->addChild( pMenuDown , 100 );

	// pModelEndless pModelTime pAddGold  add the up menu
	pMenuUp = Menu::create( pAddGold , NULL );
	pMenuUp->setPosition( 0 , 200 );
	this->addChild( pMenuUp , 100 );

	// ע��֪ͨ
	NotificationCenter::getInstance( )->addObserver( this , callfuncO_selector( ZRBMenu::setGold ) , "NOTIFICATION_Gold" , NULL );

	return true;
}




/**
*  Set First view button color
*/

void ZRBMenu::setButtonColor0( )
{

	pSetbutten->setColor( Color3B( 230 , 170 , 160 ) );

	pKtplay->setColor( Color3B( 235 , 230 , 190 ) );

	pBegin->setColor( Color3B( 180 , 130 , 150 ) );

	pMarket->setColor( Color3B( 115 , 190 , 205 ) );

	pCharts->setColor( Color3B( 170 , 220 , 190 ) );
	//  TODO: ģʽȡ��
	//    pModelEndless->setColor(Color3B(219, 146, 112));
	//    
	//    pModelTime->setColor(Color3B(98, 141, 164));
}

/**
*  Set Second view button color
*/
void ZRBMenu::setButtonColor1( )
{
	pSetbutten->setColor( Color3B( 178 , 154 , 189 ) );

	pKtplay->setColor( Color3B( 98 , 141 , 164 ) );

	pBegin->setColor( Color3B( 219 , 146 , 112 ) );

	pMarket->setColor( Color3B( 122 , 170 , 154 ) );

	pCharts->setColor( Color3B( 214 , 212 , 122 ) );


	//  TODO: ģʽȡ��
	//    pModelEndless->setColor(Color3B(141, 219, 254));
	//    
	//    pModelTime->setColor(Color3B(214, 141, 254));
}

/**
*  Set Third view button color
*/
void ZRBMenu::setButtonColor2( )
{
	pSetbutten->setColor( Color3B( 250 , 201 , 172 ) );

	pKtplay->setColor( Color3B( 254 , 156 , 153 ) );

	pBegin->setColor( Color3B( 255 , 64 , 94 ) );

	pMarket->setColor( Color3B( 200 , 200 , 168 ) );

	pCharts->setColor( Color3B( 132 , 175 , 155 ) );


	//  TODO: ģʽȡ��
	//    pModelEndless->setColor(Color3B(254, 214, 112));
	//    
	//    pModelTime->setColor(Color3B(254, 141, 214));
}

/**
*  Set menu position ( move down )
*
*  @param p from pageview
*/
void ZRBMenu::SetButtenPointDown( float p )
{
	// Under menu move down
	pMenuDown->setPosition( 0 , size.height * p * 2 / ZRB_VISIBLE_SIZE.width );

	// Up menu move up
	pMenuUp->setPosition( 0 , -size.height * p * 2 / ZRB_VISIBLE_SIZE.width );
}

/**
*  Set menu position ( move up )
*
*  @param p from pageview
*/
void ZRBMenu::SetButtenPointUp( float p )
{
	// Under menu move up
	pMenuDown->setPosition( 0 , -size.height * p * 2 / ZRB_VISIBLE_SIZE.width );

	// Up menu move down
	pMenuUp->setPosition( 0 , size.height * p * 2 / ZRB_VISIBLE_SIZE.width );

}


/**
*  The function callback of menu pBegin
*/
void ZRBMenu::begainGame( Ref * ref )
{
	auto move = MoveBy::create( 0.3f , Vec2( 0 , 200 ) );

	pAddGold->runAction( move );
	pBegin->runAction( Speed::create( Sequence::create( DelayTime::create( 0.4 ) , move->reverse( ) , NULL ) , 2 ) );
	pKtplay->runAction( move->reverse( ) );
	pMarket->runAction( move->reverse( ) );
	pSetbutten->runAction( Sequence::create( DelayTime::create( 0.1 ) , move->reverse( ) , NULL ) );
	pCharts->runAction( Sequence::create( DelayTime::create( 0.1 ) , move->reverse( ) , NULL ) );
	pMenuDown->setEnabled( false );
	pMenuUp->setEnabled( false );

	NotificationCenter::getInstance( )->postNotification( "Game" , __Bool::create( true ) );
	//  TODO: ģʽȡ��
	//    if (pModel)
	//    {
	//        ZRBManager::go(ZRBSceneManager::gameScene);
	//    }
	//    else
	//    {
	//        ZRBManager::go(ZRBSceneManager::timeGameScene);
	//    }
}

/**
*  The function callback of pAddGold
*/
void ZRBMenu::addGold( )
{
	//    pGold->setString("00000000");
	/*auto market = ZRBMenuMarket::create( );
	this->addChild( market , 101 );
	market->call_buy( );
*/

}


/**
*  The function callback of pModelEndless
*/
void ZRBMenu::modelEndless( )
{
	//Determine whether endless model
	//  TODO: ģʽȡ��
	//    if (!pModel)
	//    {
	//
	//        // Change the model button pictrue
	//        pModelEndless->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_endless_checked.png"));
	//        
	//        pModelTime->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_time.png"));
	//        
	//        // Set model is endless
	//        pModel = true;
	//        // ������Ϸģʽ
	//        UserDate::getInstance()->saveData(KEY_CHECK_MODEL, &pModel);
	//    }
}

/**
*  The function callback of pModelTime
*/
void ZRBMenu::modelTime( )
{

	//  TODO: ģʽȡ��
	//    //Determine whether endless model
	//    if (pModel)
	//    {
	//        
	//        // Change the model button pictrue
	//        pModelEndless->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_endless.png"));
	//        
	//        pModelTime->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("model_time_checked.png"));
	//        
	//        // Set model is time
	//        pModel = false;
	//        // ������Ϸģʽ
	//        UserDate::getInstance()->saveData(KEY_CHECK_MODEL, &pModel);
	//    }
}

/**
*  The function callback of pSetbutten
*/
void ZRBMenu::setting( )
{
	//this->addChild( ZRBMenuSet::create( ) , 101 );
}


/**
*  The function callback of pKtplay
*/
void ZRBMenu::Ktplay( )
{
	/*if ( KTPlayC::isEnabled( ) )
	{
		KTPlayC::show( );
	}
	else*/
	{
		auto mes = ZRBMessageLayer::create( );
		mes->setMessageLabel( "����������" );
		mes->setGlobalZOrder( 200 );
		this->addChild( mes );
	}
}

/**
*  The function callback of pMarket
*/
void ZRBMenu::market( )
{
	//this->addChild( ZRBMenuMarket::create( ) , 101 );
}

/**
*  The function callback of pCharts
*/
void ZRBMenu::charts( )
{
	//this->addChild( ZRBMenuChars::create( ) , 101 );
}

/**
*  Set pSsize  Save pageview index
*
*  @param x pagview index from pageview
*/
void ZRBMenu::setSsize( int x )
{
	pSsize = x;
}

/**
*  Set pGold
*
*  @param x Gold number
*/
void ZRBMenu::setGold( Ref * sender )
{
	// ��ȡ���� ��ʾ
	auto x = dynamic_cast<__Integer *>( sender );
	pGold->setString( String::createWithFormat( "%d" , x->getValue( ) )->getCString( ) );
}



ZRBMenu::ZRBMenu( )
{
	pSsize = 0;
	//  TODO: ģʽȡ��
	//    pModel = true;
}

ZRBMenu::~ZRBMenu( )
{
	// �Ƴ�֪ͨ
	NotificationCenter::getInstance( )->removeAllObservers( this );
}
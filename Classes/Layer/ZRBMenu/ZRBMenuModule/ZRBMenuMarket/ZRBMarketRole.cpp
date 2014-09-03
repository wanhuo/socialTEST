

#include "ZRBMarketRole.h"

ZRBMarketRole::ZRBMarketRole( ) 
	: pBuy( { true , false , false } )
	, pPrice( { 0 , 2000 , 2000 } )
{
}

ZRBMarketRole::~ZRBMarketRole( )
{
}

bool ZRBMarketRole::init( )
{
	if ( !Layer::init( ) )
	{
		return false;
	}

	hero.push_back( ZRBTheme::getHeroDragon( ) );
	hero.push_back( ZRBTheme::getHeroSnail( ) );
	hero.push_back( ZRBTheme::getHeroPink( ) );

	strName.push_back( ZRBLanguage::getValue( "Market_role_name_1" ) );
	strName.push_back( ZRBLanguage::getValue( "Market_role_name_2" ) );
	strName.push_back( ZRBLanguage::getValue( "Market_role_name_3" ) );

	strChar.push_back( ZRBLanguage::getValue( "Market_role_chr_1" ) );
	strChar.push_back( ZRBLanguage::getValue( "Market_role_chr_2" ) );
	strChar.push_back( ZRBLanguage::getValue( "Market_role_chr_1" ) );

	//    strIntr.push_back("小礼一份");
	//    strIntr.push_back("无意邂逅");
	//    strIntr.push_back("最强拍档");

	_color.push_back( Color3B( 246 , 173 , 100 ) );
	_color.push_back( Color3B( 91 , 141 , 53 ) );
	_color.push_back( Color3B( 189 , 67 , 147 ) );

	for ( auto p : hero )
	{
		SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( p->plist , p->png );
	}

	// 设置大小
	if ( ZRB_VISIBLE_SIZE.height > 1100 )
	{
		size = Size( 410 , 535 );
	}
	else if ( ZRB_VISIBLE_SIZE.height > 950 )
	{
		size = Size( 410 , 455 );
	}
	else
	{
		size = Size( 410 , 400 );
	}
	int x = 3;
	//    bool b = false;
	//    ZRBUserDate::getInstance()->saveData(KEY_ROLE_ONE, &b);
	//    ZRBUserDate::getInstance()->saveData(KEY_ROLE_TWO, &b);
	pBuy [ 1 ] = ZRBUserDate::getInstance( )->getDateBool( KEY_ROLE_ONE );
	pBuy [ 2 ] = ZRBUserDate::getInstance( )->getDateBool( KEY_ROLE_TWO );

	// 创建 pageView
	pageView = ui::PageView::create( );
	pageView->setSize( size );
	pageView->setPosition( Vec2( 0 , 15 ) );
	pageView->setTouchEnabled( true );
	pageView->addEventListener( CC_CALLBACK_2( ZRBMarketRole::pageSwith , this ) );


	for ( int i = 0; i < x; i++ )
	{
		auto layer = LayerColor::create( Color4B( 180 , 180 , 180 , 255 ) , 12 , 12 );
		if ( i == 0 )
		{
			layer->setColor( Color3B( 0 , 0 , 0 ) );
		}
		int k = ( x - 1 ) * 30 / 2;
		layer->setPosition( size.width / 2 - k + i * 30 , 0 );
		pageView->cocos2d::Node::addChild( layer );
		curPage.pushBack( layer );
	}

	for ( int i = 0; i < 3; i++ )
	{
		auto animation = Animation::create( );

		for ( int j = 0; j < hero.at( i )->climbAnimationImageNum; j++ )
		{
			animation->addSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( String::createWithFormat( "hero_climb_%d%s%s" , j + 1 , hero.at( i )->NameAfter.c_str( ) , ".png" )->getCString( ) ) );
		}
		animation->setDelayPerUnit( 0.3 );
		heroAnimation.pushBack( animation );
	}

	roleLayer( );

	this->addChild( pageView );

	return true;

}


void ZRBMarketRole::roleLayer( )
{
	TTFConfig ttfName( "customfout.otf" , 45 );
	TTFConfig ttfChar( "customfout.otf" , 35 );
	//    TTFConfig ttfIntr("customfout.otf", 30);

	for ( int i = 0; i < 3; i++ )
	{
		float scale = size.height / 535;
		// 创建角色名字 label
		auto layer = ui::Layout::create( );
		layer->setColor( Color3B( 210 , 234 , 254 ) );
		auto name = Label::createWithTTF( ttfName , strName.at( i ) );
		name->setPosition( size.width / 2 , size.height - name->getContentSize( ).height / 2 );
		name->setColor( Color3B( 0 , 0 , 0 ) );
		name->setScale( scale );
		layer->addChild( name );

		// 创建角色特性 label
		auto characteristic = Label::createWithTTF( ttfChar , strChar.at( i ) );
		characteristic->setPosition( size.width / 2 , size.height - name->getContentSize( ).height - characteristic->getContentSize( ).height / 2 );
		characteristic->setColor( Color3B( 0 , 0 , 0 ) );
		characteristic->setScale( scale );
		layer->addChild( characteristic );

		// 创建角色 sprite
		auto pic = Sprite::createWithSpriteFrameName( "hero" + hero.at( i )->NameAfter + ".png" );
		pic->setPosition( size.width / 2 , size.height / 2 );
		pic->setScale( scale );
		pic->runAction( RepeatForever::create( Animate::create( heroAnimation.at( i ) ) ) );
		layer->addChild( pic );

		auto pos = Vec2( pic->getPositionX( ) - pic->getContentSize( ).width * scale / 2 , pic->getPositionY( ) - pic->getContentSize( ).height * scale * 2 / 3 );

		auto tim = Sprite::createWithSpriteFrameName( "timbo_center_sweet.png" );
		tim->setAnchorPoint( Vec2( 1 , 0 ) );
		tim->setScale( scale );
		tim->setColor( _color.at( i ) );
		tim->setPosition( pos );
		layer->addChild( tim );
		auto timbo = tim;
		for ( int j = 0; j < 4; j++ )
		{
			tim = Sprite::createWithSpriteFrameName( "timbo_center_sweet.png" );
			tim->setAnchorPoint( Vec2( 1 , 0 ) );
			tim->setColor( _color.at( i ) );
			tim->setPosition( timbo->getContentSize( ).width , timbo->getContentSize( ).height - 1 );
			timbo->addChild( tim );
			timbo = tim;
		}

		//        // 创建角色特色 label
		//        auto introduction = Label::createWithTTF(ttfIntr, strIntr.at(i));
		//        introduction->setPosition(size.width / 2, (size.height - pic->getContentSize().height - introduction->getContentSize().height * 2) / 2);
		//        introduction->setColor(Color3B(0, 0, 0));
		//        layer->addChild(introduction);

		// 选中图标
		auto check = Sprite::createWithSpriteFrameName( "check.png" );
		check->setPosition( timbo->getContentSize( ).width / 2 , timbo->getContentSize( ).height );
		check->setScale( scale );
		timbo->addChild( check );
		_check.push_back( check );
		if ( i == ZRBUserDate::getInstance( )->getDateInt( KEY_CHECK_ROLE ) && pBuy [ i ] )
		{
			check->setVisible( true );
		}
		else
		{
			check->setVisible( false );
		}

		// 创建使用按钮
		auto useBuy = MenuItemImage::create( );
		useBuy->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( ZRBLanguage::getValue( "Pic_market_use" ) ) );
		useBuy->setPosition( 0 , useBuy->getContentSize( ).height * 3 / 4 + 15 );
		useBuy->setScale( scale );
		// 添加回调
		useBuy->setCallback( CC_CALLBACK_0( ZRBMarketRole::callUse , this ) );

		// 添加金币底纹
		auto bg_gold = Sprite::createWithSpriteFrameName( "gold_bg.png" );
		bg_gold->setScale( 0.7 );
		bg_gold->setPosition( useBuy->getContentSize( ).width / 2 , bg_gold->getContentSize( ).height / 2 );
		bg_gold->setVisible( false );
		// 设置金币字样
		auto pGoldNum = Label::createWithTTF( "0" , "customfout.otf" , 30 );
		pGoldNum->setPosition( bg_gold->getContentSize( ).width * 0.5 , bg_gold->getContentSize( ).height * 0.5 );
		pGoldNum->setColor( Color3B( 0 , 0 , 0 ) );
		bg_gold->addChild( pGoldNum , 2 , 2 );
		useBuy->addChild( bg_gold , 1 , 1 );

		use_buy.push_back( useBuy );


		// 创建菜单
		auto menu = Menu::create( useBuy , NULL );
		menu->setPosition( size.width / 2 , 0 );
		layer->addChild( menu );
		pageView->addPage( layer );
	}
}


void ZRBMarketRole::callUse( )
{
	auto idx = pageView->getCurPageIndex( );
	auto gold = ZRBUserDate::getInstance( )->getDateInt( KEY_DATA_GOLDNUM );
	if ( pBuy [ idx ] )
	{
		// 设置选择图标显示
		for ( auto &check : _check )
		{
			check->setVisible( false );
		}
		_check.at( idx )->setVisible( true );
		// 存储选择
		ZRBTheme::setCurrentHero( hero.at( idx ) );
		ZRBUserDate::getInstance( )->saveData( KEY_CHECK_ROLE , &idx );
		NotificationCenter::getInstance( )->postNotification( "NOTIFICATION_Hero" );
	}
	else if ( gold >= pPrice [ idx ] )
	{
		bool t = true;
		// 减去金币
		gold -= pPrice [ idx ];
		ZRBUserDate::getInstance( )->saveData( KEY_DATA_GOLDNUM , &gold );
		// 选择购买
		switch ( idx )
		{
			case 1:
				pBuy [ 1 ] = true;
				setButtenUse( idx );
				ZRBUserDate::getInstance( )->saveData( KEY_ROLE_ONE , &t );
				break;

			case 2:
				pBuy [ 2 ] = true;
				setButtenUse( idx );
				ZRBUserDate::getInstance( )->saveData( KEY_ROLE_TWO , &t );
				break;

			default:
				break;
		}

		auto mes = ZRBMessageLayer::create( );
		mes->setMessageLabel( ZRBLanguage::getValue( "Message_market_success" ) );
		mes->setPosition( -this->convertToWorldSpace( Vec2::ZERO ) );
		mes->setGlobalZOrder( 200 );
		this->addChild( mes );

		// 发送信息
		NotificationCenter::getInstance( )->postNotification( "NOTIFICATION_Gold" , __Integer::create( gold ) );
	}
	else
	{
		auto mes = ZRBMessageLayer::create( );
		mes->setMessageLabel( ZRBLanguage::getString( "Message_market_fail_1" ) + "\n" + ZRBLanguage::getString( "Message_market_fail_2" ) );
		mes->setPosition( -this->convertToWorldSpace( Vec2::ZERO ) );
		mes->setGlobalZOrder( 200 );
		this->addChild( mes );
		return;
	}
}


void ZRBMarketRole::pageSwith( cocos2d::Ref *ref , ui::PageView::EventType type )
{
	switch ( type )
	{
		case ui::PageView::EventType::TURNING:
		{
			auto idx = pageView->getCurPageIndex( );
			for ( auto layer : curPage )
			{
				if ( pageView->getCurPageIndex( ) == curPage.getIndex( layer ) )
				{
					layer->setColor( Color3B( 0 , 0 , 0 ) );
				}
				else
				{
					layer->setColor( Color3B( 180 , 180 , 180 ) );
				}
			}

			if ( !pBuy [ idx ] )
			{
				use_buy.at( idx )->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( ZRBLanguage::getValue( "Pic_market_buy" ) ) );
				use_buy.at( idx )->getChildByTag( 1 )->setVisible( true );
				auto label = dynamic_cast<Label *>( use_buy.at( idx )->getChildByTag( 1 )->getChildByTag( 2 ) );
				label->setString( String::createWithFormat( "%d" , pPrice [ pageView->getCurPageIndex( ) ] )->getCString( ) );
			}
			else
			{
				setButtenUse( idx );
			}

			if ( idx == ZRBUserDate::getInstance( )->getDateInt( KEY_CHECK_ROLE ) && pBuy [ idx ] )
			{
				_check.at( idx )->setVisible( true );
			}
			else
			{
				_check.at( idx )->setVisible( false );
			}
			break;
		}
		default:
			break;
	}
}

void ZRBMarketRole::setButtenUse( int idx )
{
	use_buy.at( idx )->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( ZRBLanguage::getValue( "Pic_market_use" ) ) );
	use_buy.at( idx )->getChildByTag( 1 )->setVisible( false );
}

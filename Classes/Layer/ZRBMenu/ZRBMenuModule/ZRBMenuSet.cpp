
#include "ZRBMenuSet.h"

#if ( CC_PLATFORM_IOS == CC_TARGET_PLATFORM )
#include "ios.h"
#endif

bool ZRBMenuSet::init( )
{
	if ( !Layer::init( ) )
	{
		return false;
	}


	// 创建背景屏蔽层 添加到菜单中屏蔽下层触摸
	auto l = LayerColor::create( Color4B( 170 , 228 , 250 , 80 ) );
	auto mi = MenuItemSprite::create( l , l );
	auto m = Menu::create( mi , NULL );
	this->addChild( m );


	// Add spriteframecache
	SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "homeMenu.plist" );
	setBatchNode( SpriteBatchNode::create( "homeMenu.png" ) );
	this->addChild( getBatchNode( ) );

	// 添加 ZRBMenuBase
	auto layer = ZRBMenuBase::create( );

	// 添加 菜单背景
	_backboard = layer->getBackGround( );
	// 设置背板大小
	_backboard->setPreferredSize( ZRB_VISIBLE_SIZE * 0.7 );
	// 设置背板位置
	_backboard->setPosition( ZRB_VISIBLE_SIZE.width / 2 , ZRB_VISIBLE_SIZE.height * 3 / 2 );
	// 添加背板
	this->addChild( _backboard , 10 );

	// 创建背板出现的动作
	createAtionIn( );
	// 执行动作
	_backboard->runAction( getActionOut( ) );

	// 向背板上添加菜单
	_backboard->addChild( setSetting( ) );


	return true;
}

/**
*  设置 Setting 按钮的弹窗
*
*  @return 返回 Menu
*/
Menu * ZRBMenuSet::setSetting( )
{

	// 获取背板图片大小
	auto size = _backboard->getContentSize( );

	//背板添加分割线
	for ( int i = 4; i > 1; i-- )
	{
		auto line = Sprite::createWithSpriteFrameName( "line.png" );
		line->setPosition( size.width / 2 , size.height / 5 * i );
		_backboard->addChild( line );
	}

	// 顶部添加设置字样
	auto fontSet = Label::createWithTTF( ZRBLanguage::getValue( "Set_set" ) , "customfout.otf" , 60 );
	fontSet->setColor( Color3B( 69 , 193 , 255 ) );
	fontSet->setPosition( Vec2( size.width / 2 , size.height * 0.9 ) );
	_backboard->addChild( fontSet );


	// 设置 about 按钮
	auto about = MenuItemImage::create( );
	about->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "about.png" ) );
	about->setPosition( size.width / 2 , size.height * 0.5 );
	about->setAnchorPoint( Vec2( 0.5 , 0 ) );
    about->setCallback([](Ref*){
        IOSRanking::getInstance()->showAbout();
    });

	// about 按钮添加 "关于我们" 字样
	auto fontAbout = Label::createWithTTF( ZRBLanguage::getValue( "Set_about" ) , "customfout.otf" , 30 );
	fontAbout->setColor( Color3B( 69 , 193 , 255 ) );
	fontAbout->setAnchorPoint( Vec2( 0.5 , 1 ) );
	fontAbout->setPosition( about->getContentSize( ).width / 2 , 0 );
	about->addChild( fontAbout );

	// 设置 sound 按钮
	auto sound_on = MenuItemImage::create( );
	sound_on->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "sound.png" ) );

	auto sound_off = MenuItemImage::create( );
	sound_off->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "sound_close.png" ) );

	auto sound = MenuItemToggle::createWithCallback( CC_CALLBACK_0( ZRBMenuSet::call_sound , this ) , sound_on , sound_off , NULL );
	sound->setPosition( size.width * 0.3 , size.height * 0.7 );

	
	if ( !ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_SOUND ) )
	{
		sound->setSelectedIndex( 1 );
	}
	// sound 按钮 添加 "音效" 字样
	auto fontSound = Label::createWithTTF( ZRBLanguage::getValue( "Set_sound" ) , "customfout.otf" , 25 );
	fontSound->setColor( Color3B( 69 , 193 , 255 ) );
	fontSound->setAnchorPoint( Vec2( 0.5 , 1 ) );
	fontSound->setPosition( sound->getContentSize( ).width / 2 , 0 );
	sound->addChild( fontSound );

	// 设置 music  按钮
	auto music_on = MenuItemImage::create( );
	music_on->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "music.png" ) );
	auto music_off = MenuItemImage::create( );
	music_off->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "music_close.png" ) );

	auto music = MenuItemToggle::createWithCallback( CC_CALLBACK_0( ZRBMenuSet::call_music , this ) , music_on , music_off , nullptr );
	music->setPosition( size.width * 0.7 , size.height * 0.7 );
	
	//音乐状态
	if ( !ZRBUserDate::getInstance(	)->getDateBool( KEY_CHECK_MUSIC) )
	{
		music->setSelectedIndex( 1 );
	}

	// music 按钮添加 " 音乐" 字样
	auto fontMusic = Label::createWithTTF( ZRBLanguage::getValue( "Set_music" ) , "customfout.otf" , 25 );
	fontMusic->setColor( Color3B( 69 , 193 , 255 ) );
	fontMusic->setAnchorPoint( Vec2( 0.5 , 1 ) );
	fontMusic->setPosition( music->getContentSize( ).width / 2 , 0 );
	music->addChild( fontMusic );

	// 设置 evaluate 按钮的 label
	auto evaluateLable = Label::createWithTTF( ZRBLanguage::getValue( "Set_appreciate" ) , "customfout.otf" , 30 );
	evaluateLable->setAnchorPoint( Vec2( 0.5 , 1 ) );
	evaluateLable->setColor( Color3B( 69 , 193 , 255 ) );

	// 设置evaluate 按钮
	auto evaluate = MenuItemImage::create( );
	evaluate->setNormalSpriteFrame( SpriteFrameCache::getInstance( )->getSpriteFrameByName( "star.png" ) );
	evaluate->setPosition( size.width * 0.5 , size.height * 0.35 );
	evaluate->setAnchorPoint( Vec2( 0.5 , 1 ) );
    evaluate->addChild( evaluateLable );

	evaluateLable->setPosition( evaluate->getContentSize( ).width / 2 , 0 );

	// 设置 back 按钮
	auto backLabel = Label::createWithTTF( ZRBLanguage::getValue( "Back" ) , "customfout.otf" , 50 );
	backLabel->setColor( Color3B( 69 , 193 , 255 ) );
	auto back = MenuItemLabel::create( backLabel );
	//    auto back = MenuItemImage::create();
	//    back->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("back_button_set.png"));
	back->setCallback( CC_CALLBACK_0( ZRBMenuSet::call_back , this ) );
	back->setPosition( size.width / 2 , size.height * 0.1 );

	// 返回添加 menuLayer, back, about, sound, music, evaluate 按钮的菜单
	auto menu = Menu::create( back , about , music , sound , evaluate , NULL );
	menu->setPosition( 0 , 0 );

	return menu;

}


/**
*  Setting
*
*  music 按钮回调函数
*/
void ZRBMenuSet::call_music( )
{

	bool _music = ZRBUserDate::getInstance()->getDateBool( KEY_CHECK_MUSIC );
	
	if ( _music )
	{
		_music = false;
		CocosDenshion::SimpleAudioEngine::getInstance( )->pauseBackgroundMusic( );
	}
	else
	{
		_music = true;
		CocosDenshion::SimpleAudioEngine::getInstance( )->resumeBackgroundMusic( );
	}

	ZRBUserDate::getInstance( )->saveData( KEY_CHECK_MUSIC , &_music );
}


/**
*  Setting
*
*  sound 按钮回调函数
*/
void ZRBMenuSet::call_sound( )
{

	if ( ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_SOUND ) )
	{
		auto sound = false;
		ZRBUserDate::getInstance( )->saveData( KEY_CHECK_SOUND , &sound );
	}
	else
	{
		auto sound = true;
		ZRBUserDate::getInstance( )->saveData( KEY_CHECK_SOUND , &sound );
		CocosDenshion::SimpleAudioEngine::getInstance( )->playEffect( ZRBLanguage::getValue( "Music_Btclick" ) );
	}
}


/**
*  Setting
*
*  about 按钮回调函数
*/
void ZRBMenuSet::call_about( )
{
}
/**
*  back 按钮回调函数
*/
void ZRBMenuSet::call_back( )
{
	if ( ZRBUserDate::getInstance( )->getDateBool( KEY_CHECK_SOUND ) )
	{
		CocosDenshion::SimpleAudioEngine::getInstance( )->playEffect( ZRBLanguage::getValue( "Music_Btclick" ) );
	}
	//创建菜单移除的动作
	createAtionOut( );
	//执行动作并调用清理函数
	_backboard->runAction( Sequence::create( dynamic_cast<FiniteTimeAction *>( getActionIn( ) ) ,
		CallFunc::create( CC_CALLBACK_0( ZRBMenuSet::call_clear , this ) ) , NULL ) );

}

// 返回后清理
void ZRBMenuSet::call_clear( )
{
	// 移除菜单 清理
	this->removeFromParentAndCleanup( true );

}

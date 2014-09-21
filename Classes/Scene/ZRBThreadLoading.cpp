/*
 * ZRBThreadLoading.cpp
 *
 *  Created on: 2014年9月19日
 *      Author: 帅锋
 */

#include "ZRBThreadLoading.h"
#include "ZRBScene.h"

ZRBThreadLoading::ZRBThreadLoading()
	: isLoad( false )
	, _mutex( )
{
	name.push_back( "homeMenu" );
	name.push_back( "gameFinish_Layer" );
	name.push_back( "blueSky_material" );
	name.push_back( "summer_material" );
	name.push_back( "sweet_material" );
}

ZRBThreadLoading::~ZRBThreadLoading()
{
}

cocos2d::Scene * ZRBThreadLoading::createScene()
{
	auto scene = cocos2d::Scene::create();

	scene->addChild(ZRBThreadLoading::create());

	return scene;
}


bool ZRBThreadLoading::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto load = Sprite::create( "load.png" );
	load->setPosition( 320 , 568 );
	this->addChild( load );


	scheduleUpdate( );

	std::thread t1(&ZRBThreadLoading::thread1, this);
	std::thread t2(&ZRBThreadLoading::thread2, this, 2);
	t1.detach( );
	t2.join( );

	log( "--------kk----------" );

	return true;
}


void ZRBThreadLoading::update( float dt )
{

	if ( isLoad )
	{
		log( "--------hh----------" );

		for ( int i = 0; i < name.size( ); i++ )
		{
			auto text = TextureCache::getInstance( )->addImage( image.at( i ) , name.at( i ) + ".png" );
			image.at( i )->release( );
			SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( name.at( i ) + ".plist" , text );
		}

		//SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "" );
		image.clear( );
		name.clear( );
		
		Director::getInstance( )->replaceScene( ZRBScene::sceneCreate( ) );
		isLoad = false;
	}
	
}


void ZRBThreadLoading::thread1( )
{
	_mutex.lock( );

	log( "--------aa----------" );


	for (int i = 0; i < name.size( ); i++)
	{
		image.push_back( new Image( ) );
		image.at( i )->initWithImageFile( name.at(i)  + ".png" );
	}
	
	// TODO: 加载音乐
	CocosDenshion::SimpleAudioEngine::getInstance( )->preloadBackgroundMusic( ZRBLanguage::getValue( "Music_Bg" ) );

	
	log( "--------ss----------" );

	isLoad = true;

	log( "---------dd---------" );

	_mutex.unlock( );
}


void ZRBThreadLoading::thread2( int a )
{
	std::lock_guard<std::mutex> lk( _mutex );

}




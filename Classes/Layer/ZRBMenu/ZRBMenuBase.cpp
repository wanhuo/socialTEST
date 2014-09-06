
#include "ZRBMenuBase.h"


bool ZRBMenuBase::init( )
{
	if ( !Layer::init( ) )
	{
		return false;
	}
	// 图片加载到内存
	SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "homeMenu.plist" , "homeMenu.png" );
	// 添加背景图片
	createBackGroud( );

	return true;
}


void ZRBMenuBase::createBackGroud( )
{
	_backGround = Scale9Sprite::createWithSpriteFrameName( "flow_bg.png" , Rect( 26 , 26 , 58 , 12 ) );
}


/**
*  创建进入的动作
*/
void ZRBMenuBase::createAtionIn( )
{

	//  在0.25秒向下移动一个屏幕的高度
	_actionOut = MoveBy::create( 0.15f , Vec2( 0 , -ZRB_VISIBLE_SIZE.height ) );

	// 设置动作
	//setActionOut( moveDown );

}


void ZRBMenuBase::createAtionOut( )
{
	// 旋转15度 时间0.15秒
	auto rotate = RotateBy::create( 0.1f , 5 );

	// 在0.5秒内下降一个屏幕的高度
	auto moveDown = MoveBy::create( 0.2f , Vec2( 0 , -ZRB_VISIBLE_SIZE.height ) );

	// 同时向下移动和旋转
	_actionIn = Spawn::create( rotate , moveDown , NULL );
	_actionIn->retain( );
	// 设置动作
	/*setActionIn( moveRotate );*/
}



#include "ZRBTableViewCell.h"


ZRBTableViewCell::ZRBTableViewCell( )
{
	_partFirst = 0;
	_partSecond = 0;
	_partThree = 0;
	_partFour = 0;

	_foutRanking = { };
	_foutName = { };
	_foutScorer = { };

	_ranking = nullptr;
	_pic = nullptr;
	_name = nullptr;
	_scorer = nullptr;
}


ZRBTableViewCell::~ZRBTableViewCell( )
{
}



bool ZRBTableViewCell::init( )
{
	if ( !TableViewCell::init( ) )
	{
		return false;
	}

	setFoutRanking( );
	setFoutName( );
	setFoutScorer( );

	setpartFirst( 1 );
	setpartSecond( 1 );
	setpartThree( 2 );
	setpartFour( 1 );

	_ranking->Label::create( );
	_pic->Sprite::create( );
	_name->Label::create( );
	_scorer->Label::create( );

	// 添加资源图片到内存
	cocos2d::SpriteFrameCache::getInstance( )->addSpriteFramesWithFile( "homeMenu.plist" , "homeMenu.png" );

	//创建分割线 设置锚点为下边缘正中
	line = cocos2d::Sprite::createWithSpriteFrameName( "line.png" );
	line->setAnchorPoint( cocos2d::Vec2( 0.5 , 0 ) );
	this->addChild( line , 10 );

	// 创建背景
	bg_layer = cocos2d::LayerColor::create( cocos2d::Color4B( 255 , 255 , 255 , 255 ) , 0 , 0 );
	this->addChild( bg_layer );

	return true;
}


// 设置排名字体的 foutInfo
void ZRBTableViewCell::setFoutRanking( int x , std::string fout , cocos2d::Color3B color )
{
	_foutRanking.foutSize = x;
	_foutRanking.fout = fout;
	_foutRanking.foutColor = color;
}

// 设置玩家名字字体的 foutInfo
void ZRBTableViewCell::setFoutName( int x , std::string fout , cocos2d::Color3B color )
{
	_foutName.foutSize = x;
	_foutName.fout = fout;
	_foutName.foutColor = color;
}

// 设置成绩字体的 foutInfo
void ZRBTableViewCell::setFoutScorer( int x , std::string fout , cocos2d::Color3B color )
{
	_foutScorer.foutSize = x;
	_foutScorer.fout = fout;
	_foutScorer.foutColor = color;
}


// 设置排名 label
void ZRBTableViewCell::setRanking( )
{

	// 获取位置
	auto pos = cocos2d::Vec2( getSize( ).height * getpartFirst( ) / 2 , getSize( ).height / 2 );

	if ( !_ranking )
	{
		// 创建 _ranking label
		_ranking = cocos2d::Label::createWithTTF( "" , _foutRanking.fout , _foutRanking.foutSize );

		//设置锚点  正中
		_ranking->setAnchorPoint( cocos2d::Vec2( 0.5 , 0.5 ) );
		// 设置位置
		_ranking->setPosition( pos );
		// 设置颜色
		_ranking->setColor( _foutRanking.foutColor );
		// 设置 Tag
		_ranking->setTag( frist );

	}

}

// 设置头像 sprite
void ZRBTableViewCell::setPic( )
{
	// 获取位置
	auto pos = cocos2d::Vec2( getSize( ).height * ( getpartFirst( ) + getpartSecond( ) / 2 ) , getSize( ).height / 2 );

	if ( !_pic )
	{

		// 创建 _pic spiter
		_pic = cocos2d::Sprite::create( );

		// 设置锚点  正中
		_pic->setAnchorPoint( cocos2d::Vec2( 0.5 , 0.5 ) );
		// 设置位置
		_pic->setPosition( pos );
		// 设置 Tag
		_pic->setTag( scound );
	}


}

// 设置名字 label
void ZRBTableViewCell::setName( )
{
	// 获取位置
	auto pos = cocos2d::Vec2( getSize( ).height * ( getpartFirst( ) + getpartSecond( ) ) , getSize( ).height / 2 );

	if ( !_name )
	{
		// 创建 _name label
		_name = cocos2d::Label::createWithTTF( "" , _foutName.fout , _foutName.foutSize );

		//设置锚点  左对齐 水平居中
		_name->setAnchorPoint( cocos2d::Vec2( 0 , 0.5 ) );
		// 设置位置
		_name->setPosition( pos );
		// 设置颜色
		_name->setColor( _foutName.foutColor );
		// 设置 Tag
		_name->setTag( three );
	}

}

// 设置成绩 label
void ZRBTableViewCell::setScorer( )
{

	// 获取位置
	auto pos = cocos2d::Vec2( getSize( ).height * ( getpartFirst( ) + getpartSecond( ) + getpartThree( ) ) , getSize( ).height / 2 );

	if ( !_scorer )
	{
		// 创建 _scorer label
		_scorer = cocos2d::Label::createWithTTF( "" , _foutScorer.fout , _foutScorer.foutSize );

		//设置锚点  左对齐 垂直居中
		_scorer->setAnchorPoint( cocos2d::Vec2( 0 , 0.5 ) );
		// 设置位置
		_scorer->setPosition( pos );
		// 设置颜色
		_scorer->setColor( _foutScorer.foutColor );
		// 设置 Tag
		_scorer->setTag( four );
	}
}

// 设置背景颜色
void ZRBTableViewCell::setBackgroundColor( cocos2d::Color3B color )
{
	bg_layer->setColor( color );
}


/**
*  加载时调用
*  设置 ZRBTableViewCell 中各子节点的属性
*  第一次加载时添加到 ZRBTableViewCell 中
*/
void ZRBTableViewCell::onEnter( )
{
	Node::onEnter( );

	// 设置分割线在 ZRBTableViewCell 下方边缘
	line->setPosition( getSize( ).width / 2 , 0 );

	//  ZRBTableViewCell 背景设置大小
	bg_layer->setContentSize( getSize( ) );

	//设置 各子节点的属性
	setRanking( );
	setPic( );
	setName( );
	setScorer( );

	// 判断  ZRBTableViewCell 中是否已添加子节点,    没有则添加
	if ( getRanking( ) && !this->getChildByTag( frist ) )
	{
		this->addChild( getRanking( ) );
	}

	if ( getPic( ) && !this->getChildByTag( scound ) )
	{
		this->addChild( getPic( ) );
	}

	if ( getname( ) && !this->getChildByTag( three ) )
	{
		this->addChild( getname( ) );
	}

	if ( getScorer( ) && !this->getChildByTag( four ) )
	{
		this->addChild( getScorer( ) );
	}
}

void ZRBTableViewCell::onEixt( )
{
	Node::onExit( );

}
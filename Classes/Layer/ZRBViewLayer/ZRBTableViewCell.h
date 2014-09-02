
#ifndef __ZRBTableViewCell_H__
#define __ZRBTableViewCell_H__

#include "cocos-ext.h"

USING_NS_CC_EXT;

/**
*  创建  TableViewCell  包含四个部分 排名, 头像, 名字, 成绩
*  排名, 名字, 成绩的字体可设置字体大小, 颜色,字体
*  各部分占有 TableViewCell 的多少以 TableViewCell 的高度乘以各自对应的因子
*  注: 各部分的顺序不能改变
*/
class ZRBTableViewCell : public TableViewCell
{
public:

	// TableViewCell 中各子节点的 Tag
	enum Flag
	{
		frist = 0 ,
		scound ,
		three ,
		four
	};

private:

	// 排行榜文字的字体, 大小, 颜色信息
	struct foutInfo
	{
		int foutSize;

		std::string fout;

		cocos2d::Color3B foutColor;
	};

	// 添加分割线
	cocos2d::Sprite * line;
	// 添加 ZRBTableViewCell 背景
	cocos2d::LayerColor * bg_layer;

	/**
	*   定义排名, 玩家名字, 成绩的字体信息
	*/
	CC_SYNTHESIZE( foutInfo , _foutRanking , FoutRanking );
	CC_SYNTHESIZE( foutInfo , _foutName , FoutName );
	CC_SYNTHESIZE( foutInfo , _foutScorer , FoutScorer );

	/**
	*  定义TableViewCell 中包含的信息
	*  并定义默认的 get 方法
	*/
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _ranking , Ranking );
	CC_SYNTHESIZE_READONLY( cocos2d::Sprite * , _pic , Pic );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _name , name );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _scorer , Scorer );


	/**
	*  TableViewCell 从左到右分区放置排名, 头像, 名字, 成绩
	*  垂直位置居中, 水平位置用 TableViewCell 的宽度乘以分区的大小因子
	*  下面定义各分区的大小因子并定义默认set, get方法
	*/
	CC_SYNTHESIZE( float , _partFirst , partFirst );
	CC_SYNTHESIZE( float , _partSecond , partSecond );
	CC_SYNTHESIZE( float , _partThree , partThree );
	CC_SYNTHESIZE( float , _partFour , partFour );


	/**
	*  定义从 TableView 中接收的 size 信息
	*  并定义默认的set . get 方法
	*/
	CC_SYNTHESIZE( cocos2d::Size , _size , Size );

public:

	// 成员变量赋初始值
	ZRBTableViewCell( );
	~ZRBTableViewCell( );

	// 初始化成员
	virtual bool init( );
	// 加载时设置成员属性
	virtual void onEnter( );
	virtual void onEixt( );

	// 从 foutInfo 获取字体
	std::string getFout( foutInfo info ) { return info.fout; }
	// 从 foutInfo 获取字体大小
	int getFoutSize( foutInfo info ) { return info.foutSize; }
	// 从 foutInfo 获取字体颜色
	cocos2d::Color3B getFoutColor( foutInfo info ) { return info.foutColor; }

	// 设置排名字体的 foutInfo
	void setFoutRanking( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	// 设置玩家名字字体的 foutInfo
	void setFoutName( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	// 设置成绩字体的 foutInfo
	void setFoutScorer( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );

	// 设置背景颜色
	void setBackgroundColor( cocos2d::Color3B color );

	CREATE_FUNC( ZRBTableViewCell );

private:

	// 设置排名 label
	void setRanking( );
	// 设置头像 sprite
	void setPic( );
	// 设置名字 label
	void setName( );
	// 设置成绩 label
	void setScorer( );

};


#endif

#ifndef __ZRBTableViewCell_H__
#define __ZRBTableViewCell_H__

#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

class ZRBTableViewCell : public TableViewCell
{
public:

	enum Flag
	{
		frist = 0 ,
		scound ,
		three ,
		four
	};

private:

	struct foutInfo
	{
		int foutSize;

		std::string fout;

		cocos2d::Color3B foutColor;
	};

	 
	cocos2d::Sprite * line;
	cocos2d::LayerColor * bg_layer;

	
	CC_SYNTHESIZE( foutInfo , _foutRanking , FoutRanking );
	CC_SYNTHESIZE( foutInfo , _foutName , FoutName );
	CC_SYNTHESIZE( foutInfo , _foutScorer , FoutScorer );


	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _ranking , Ranking );
	CC_SYNTHESIZE_READONLY( cocos2d::Sprite * , _pic , Pic );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _name , name );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _scorer , Scorer );


	
	CC_SYNTHESIZE( float , _partFirst , partFirst );
	CC_SYNTHESIZE( float , _partSecond , partSecond );
	CC_SYNTHESIZE( float , _partThree , partThree );
	CC_SYNTHESIZE( float , _partFour , partFour );


	CC_SYNTHESIZE( cocos2d::Size , _size , Size );

public:

	ZRBTableViewCell( );
	~ZRBTableViewCell( );

	virtual bool init( );
	virtual void onEnter( );
	virtual void onEixt( );

	
	std::string getFout( foutInfo info ) { return info.fout; }
	int getFoutSize( foutInfo info ) { return info.foutSize; }
	cocos2d::Color3B getFoutColor( foutInfo info ) { return info.foutColor; }

	void setFoutRanking( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	void setFoutName( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	void setFoutScorer( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );

	void setBackgroundColor( cocos2d::Color3B color );

	CREATE_FUNC( ZRBTableViewCell );

private:

	void setRanking( );
	void setPic( );
	void setName( );
	void setScorer( );

};


#endif

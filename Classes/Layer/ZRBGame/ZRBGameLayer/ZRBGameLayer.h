

#ifndef __ZRBGameLayer_H__
#define __ZRBGameLayer_H__

#include "ZRBBaseGameLayer.h"

class ZRBGameLayer : public ZRBBaseGameLayer
{
private:

	/* Todo ktplay
	static void reportScoreCallBack( bool isSuccess , const char *leaderboardId , long long score , KTErrorC *error );*/

public:
	static const int top = 0x1111;

	ZRBGameLayer( );
	~ZRBGameLayer( );

	virtual bool init( );
	CREATE_FUNC( ZRBGameLayer );

	virtual void onEnter( );
	virtual void update( float delta );
	
	void initTimbos( );

	void replenishtimbosAndAddItem( );

	void gameBegain( Ref * sender );
	/// 游戏结束
	void showGameFinish( ) override;
	/// 暂停游戏
	virtual void pauseItemClick( Ref *ref );

	///带有随机金币的藤条
	Sprite * createTimboRandomPosHaveGold( );
	// 添加藤的顶部 (以后添加小怪
	Sprite * createTimbo( float length , Point pos );
	// 添加首页显示的藤
	void addTimboCall( float dt );

	// 更换主题
	void changePic( int idx );
	// 更换角色
	void changeHero( Ref *sender );
	// 重新开始游戏
	void resume( Ref * ref );
private:
	// 游戏开始 结束
	CC_SYNTHESIZE( bool , _begainGame , BegainGame );
	// 添加个数
	int count;

	// 保存页面 idx
	int _idx;

	// 实时高度 进入游戏
	float curHeight;
	// 开始游戏时的高度 
	float pBegainHeight;
};


#endif
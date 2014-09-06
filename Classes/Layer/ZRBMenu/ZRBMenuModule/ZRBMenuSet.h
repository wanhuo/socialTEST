

#ifndef __ZRBMenuSet_H__
#define __ZRBMenuSet_H__

#include <iostream>
#include "../ZRBMenuBase.h"


class ZRBMenuSet : public ZRBMenuBase
{

private:
	// 创建 _backboard 接收 menubase中的点九图
	CC_SYNTHESIZE_RETAIN( Scale9Sprite * , _backboard , Backboard );

public:

	virtual bool init( );

	// 设置各个按钮对应弹窗菜单
	Menu * setSetting( );

	// Setting 回调函数
	void call_music( );
	void call_sound( );
	void call_about( );
	void call_back( );
	void call_clear( );


	CC_SYNTHESIZE( SpriteBatchNode * , pBatchNode , BatchNode );

	CREATE_FUNC( ZRBMenuSet );

};

#endif
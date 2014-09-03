
#ifndef __ZRBMenuBase_H__
#define __ZRBMenuBase_H__


#include "cocos2d.h"
#include "cocos-ext.h"

#include "Utilities/ZRBConfig.h"
#include "Utilities/ZRBUserDate/ZRBUserDate.h"
#include "Utilities/ZRBLanguage/ZRBLanguage.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ZRBMenuBase : public Layer
{
private:

	// 添加拉伸的背景图片
	CC_SYNTHESIZE_READONLY( Scale9Sprite * , _backGround , BackGround );

	// 添加菜单进入的动作
	CC_SYNTHESIZE_RETAIN( Action * , _actionOut , ActionOut );

	// 添加菜单退出的动作
	CC_SYNTHESIZE_RETAIN( Action * , _actionIn , ActionIn );

public:

	virtual bool init( );

	// 创建退出的动作
	void createAtionOut( );

	// 创建进入的动作
	void createAtionIn( );

	// 创建背景
	void createBackGroud( );

	CREATE_FUNC( ZRBMenuBase );

};


#endif


#ifndef __ZRBGameMenuLayer_H__
#define __ZRBGameMenuLayer_H__

#include "cocos-ext.h"


#include "../../ZRBAuxiliary/ZRBLoadingLayer.h"
//#include "Scene/ZRBScene.h"

#include "Utilities/ZRBLanguage/ZRBLanguage.h"
#include "Utilities/ZRBUserDate/ZRBUserDate.h"

class ZRBGameMenuLayer :public Layer
{
public:

	virtual bool init( );
	CREATE_FUNC( ZRBGameMenuLayer );
	// Todo : 跳转的场景
	void setScene( ZRBSceneManager _manager );

private:

	int times;
	Label * countdown;
	void scheduleCall( float dt );

	void initObject( );
	// 返回游戏回调
	void backGameItemClick( Ref *ref );
	// 返回菜单回调
	void backHomeItemClick( Ref *ref );
	// 重新开始游戏回调
	void restartGameItemClick( Ref *ref );
	// 音乐开关回调
	void musicItemClick( Ref *ref );
	// 音效开关回调
	void soundEffectItemClick( Ref *ref );
	// 菜单
	Menu *pMenu;
	// Todo: 跳转场景
	ZRBSceneManager pSceneManager;

};

#endif
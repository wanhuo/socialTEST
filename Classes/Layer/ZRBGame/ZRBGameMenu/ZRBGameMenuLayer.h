

#ifndef __ZRBGameMenuLayer_H__
#define __ZRBGameMenuLayer_H__

#include "extensions/cocos-ext.h"


#include "../../ZRBAuxiliary/ZRBLoadingLayer.h"

#include "Utilities/ZRBLanguage/ZRBLanguage.h"
#include "Utilities/ZRBUserDate/ZRBUserDate.h"

class ZRBGameMenuLayer :public Layer
{
public:

	virtual bool init( );
	CREATE_FUNC( ZRBGameMenuLayer );

private:

	int times;
	Label * countdown;
	void scheduleCall( float dt );

	void initObject( );
	
	void backGameItemClick( Ref *ref );
	
	void backHomeItemClick( Ref *ref );
	
	void restartGameItemClick( Ref *ref );
	
	void musicItemClick( Ref *ref );
	
	void soundEffectItemClick( Ref *ref );
	
	Menu *pMenu;

};

#endif

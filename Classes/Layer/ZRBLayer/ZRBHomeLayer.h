

#ifndef __ZRBHomeLayer_H__
#define __ZRBHomeLayer_H__

#include "../ZRBAuxiliary/ZRBMessageLayer.h"

#include "ZRBPageView.h"


class ZRBHomeLayer : public Layer
{
public:
	ZRBHomeLayer( ) ;
	~ZRBHomeLayer( );

public:
	
	bool init( );


	CREATE_FUNC( ZRBHomeLayer );
};




#endif
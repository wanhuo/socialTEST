
#ifndef __ZRB_PageView_H__
#define __ZRB_PageView_H__

#include "ui/UIPageView.h"

USING_NS_CC;

class ZRB_PageView : public ui::PageView
{
public:

	virtual bool init( );

	void scrollToPage( ssize_t idx );

	CREATE_FUNC( ZRB_PageView );
};



#endif
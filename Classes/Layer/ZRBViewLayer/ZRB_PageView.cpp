
#include "ZRB_PageView.h"


bool ZRB_PageView::init( )
{
	if ( !ui::PageView::init( ) )
	{
		return false;
	}

	return true;
}

void ZRB_PageView::scrollToPage( ssize_t idx )
{
	if ( idx < 0 || idx >= _pages.size( ) )
	{
		return;
	}
	_curPageIdx = idx;
	Widget* curPage = _pages.at( idx );
	_autoScrollDistance = -( curPage->getPosition( ).x );
	_autoScrollSpeed = fabs( _autoScrollDistance ) / 0.002f;
	_autoScrollDirection = _autoScrollDistance > 0 ? AutoScrollDirection::RIGHT : AutoScrollDirection::LEFT;
	_isAutoScrolling = true;
}


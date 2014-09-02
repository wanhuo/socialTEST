

#ifndef __ZRBLanguage_H__
#define __ZRBLanguage_H__

#include "cocos2d.h"

class ZRBLanguage
{
public:
	ZRBLanguage( );
	~ZRBLanguage( );

	static const char * getValue( const std::string& key );
	static std::string getString( const std::string& key );
};


#endif
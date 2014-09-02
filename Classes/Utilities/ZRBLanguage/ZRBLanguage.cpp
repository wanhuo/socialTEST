
#include "ZRBLanguage.h"


ZRBLanguage::ZRBLanguage( )
{
}

ZRBLanguage::~ZRBLanguage( )
{
}

const char * ZRBLanguage::getValue( const std::string &key )
{
	const char * value;

	switch ( cocos2d::Application::getInstance( )->getCurrentLanguage( ) )
	{
		case cocos2d::LanguageType::CHINESE:
			value = cocos2d::__Dictionary::createWithContentsOfFile( "zh.plist" )->valueForKey( key )->getCString( );
			break;

		case cocos2d::LanguageType::ENGLISH:
			value = cocos2d::__Dictionary::createWithContentsOfFile( "en.plist" )->valueForKey( key )->getCString( );
			break;

		default:
			break;
	}

	return value;
}

std::string ZRBLanguage::getString( const std::string &key )
{
	const char * value;

	switch ( cocos2d::Application::getInstance( )->getCurrentLanguage( ) )
	{
		case cocos2d::LanguageType::CHINESE:
			value = cocos2d::__Dictionary::createWithContentsOfFile( "zh.plist" )->valueForKey( key )->getCString( );
			break;

		case cocos2d::LanguageType::ENGLISH:
			value = cocos2d::__Dictionary::createWithContentsOfFile( "en.plist" )->valueForKey( key )->getCString( );
			break;

		default:
			break;
	}

	return std::string( value );
}
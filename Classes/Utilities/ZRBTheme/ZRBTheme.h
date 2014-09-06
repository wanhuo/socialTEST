
#ifndef __ZRBTheme_H__
#define __ZRBTheme_H__


#include <iostream>
#include "string.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

struct sMaterial
{
	string plist;
	string png;
	string NameAfter;
	int bg2ImageNum;
	bool isRanPos;
	vector<Color3B> colors;
};
struct sHero
{
	string plist;
	string png;
	string NameAfter;
	int climbAnimationImageNum;
	int jumpAnimationImageNum;
};


class ZRBTheme
{
public:
	static sMaterial* getMaterialSummer( );
	static sMaterial* getMaterialSweet( );
	static sMaterial* getMaterialBlueSky( );
	static sHero* getHeroDragon( );
	static sHero* getHeroPink( );
	static sHero* getHeroSnail( );

	static void setCurrentMaterial( sMaterial *_material );
	static sMaterial* getCurrentMaterial( );
	static void setCurrentHero( sHero *_hero );
	static sHero* getCurrentHero( );
};

#endif
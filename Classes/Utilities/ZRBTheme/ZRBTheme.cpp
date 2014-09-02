
#include "ZRBTheme.h"

static sHero *gCurrentHero;
static sMaterial *gCurrrentMaterial;

sMaterial* ZRBTheme::getMaterialSummer( )
{
	vector<Color3B> _colors;
	_colors.push_back( Color3B( 84 , 145 , 105 ) );
	_colors.push_back( Color3B( 244 , 106 , 136 ) );
	_colors.push_back( Color3B( 212 , 185 , 124 ) );
	_colors.push_back( Color3B( 219 , 143 , 116 ) );
	_colors.push_back( Color3B( 87 , 154 , 183 ) );
	return new sMaterial { "summer_material.plist" , "summer_material.png" , "_summer" , 7 , false , _colors };
};

sMaterial* ZRBTheme::getMaterialSweet( )
{
	vector<Color3B> _colors;
	_colors.push_back( Color3B( 255 , 64 , 94 ) );
	_colors.push_back( Color3B( 254 , 156 , 153 ) );
	_colors.push_back( Color3B( 251 , 205 , 172 ) );
	_colors.push_back( Color3B( 200 , 199 , 168 ) );
	_colors.push_back( Color3B( 132 , 175 , 155 ) );
	return new sMaterial { "sweet_material.plist" , "sweet_material.png" , "_sweet" , 5 , false , _colors };
};

sMaterial* ZRBTheme::getMaterialBlueSky( )
{
	vector<Color3B> _colors;
	//    _colors.push_back(Color3B(178, 154, 189));
	//    _colors.push_back(Color3B( 98, 141, 164));
	//    _colors.push_back(Color3B(219, 146, 112));
	//    _colors.push_back(Color3B(122, 170, 154));
	//    _colors.push_back(Color3B(214, 212, 122));

	_colors.push_back( Color3B( 230 , 170 , 160 ) );
	_colors.push_back( Color3B( 235 , 230 , 190 ) );
	_colors.push_back( Color3B( 180 , 130 , 150 ) );
	_colors.push_back( Color3B( 115 , 190 , 205 ) );
	_colors.push_back( Color3B( 170 , 220 , 190 ) );

	return new sMaterial { "blueSky_material.plist" , "blueSky_material.png" , "_blueSky" , 1 , true , _colors };
}


sHero* ZRBTheme::getHeroDragon( )
{
	return new sHero { "dragon_hero.plist" , "dragon_hero.png" , "_dragon" , 2 , 1 };
};

sHero * ZRBTheme::getHeroPink( )
{
	return new sHero { "pink_heor.plist" , "pink_heor.png" , "_pink" , 2 , 0 };
}

sHero * ZRBTheme::getHeroSnail( )
{
	return new sHero { "snail_heor.plist" , "snail_heor.png" , "_snail" , 2 , 0 };
}

void ZRBTheme::setCurrentMaterial( sMaterial *_material )
{
	gCurrrentMaterial = _material;
};

sMaterial* ZRBTheme::getCurrentMaterial( )
{
	return gCurrrentMaterial;
};

void ZRBTheme::setCurrentHero( sHero *_hero )
{
	gCurrentHero = _hero;
};

sHero* ZRBTheme::getCurrentHero( )
{
	return gCurrentHero;
};

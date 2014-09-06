


#include "ZRBLoadingLayer.h"

bool ZRBLoadingLayer::init( )
{
	if ( !Layer::init( ) )
	{
		return false;
	}



	auto listener = EventListenerTouchOneByOne::create( );
	listener->setSwallowTouches( true );
	listener->onTouchBegan = [ ] ( Touch* , Event* ) { return true; };
	_eventDispatcher->addEventListenerWithSceneGraphPriority( listener , this );


	return true;
}

void ZRBLoadingLayer::setLoading( float radius , float cycle , float livetime , DirectionOfRotation Direction )
{
	auto bg = LayerColor::create( Color4B( 255 , 255 , 255 , 120 ) );
	this->addChild( bg );

	auto path = bezierCircle( radius , cycle );

	auto sprite = Sprite::create( "star.png" );
	sprite->setScale( 0.5 );
	sprite->setPosition( ZRB_VISIBLE_SIZE.width / 2 , ZRB_VISIBLE_SIZE.height / 2 - 55 );
	bg->addChild( sprite , 100 );
	sprite->setGlobalZOrder( 10 );

	auto _emitter = particleInit( livetime );
	_emitter->setPosition( sprite->getPosition( ) );

	sprite->runAction( RepeatForever::create( Spawn::create( path , RotateBy::create( cycle , 360 ) , NULL ) ) );

	_emitter->runAction( RepeatForever::create( path->clone( ) ) );
}


ParticleSystem * ZRBLoadingLayer::particleInit( float time )
{
	auto _emitter = ParticleSystemQuad::createWithTotalParticles( 50 );
	addChild( _emitter );
	_emitter->setTexture( Director::getInstance( )->getTextureCache( )->addImage( "point.png" ) );
	//    _emitter->setAnchorPoint(Vec2::ZERO);

	// duration
	_emitter->setDuration( ParticleSystem::DURATION_INFINITY );
	// radius mode
	_emitter->setEmitterMode( ParticleSystem::Mode::RADIUS );
	// radius mode: star and end radius in pixels
	_emitter->setStartRadius( 4 );
	_emitter->setStartRadiusVar( 1 );
	_emitter->setEndRadius( ParticleSystem::START_RADIUS_EQUAL_TO_END_RADIUS );
	_emitter->setEndRadiusVar( 0 );

	// radius mode: degrees per second
	_emitter->setRotatePerSecond( 100 );
	_emitter->setRotatePerSecondVar( 0 );

	// angle
	_emitter->setAngle( 90 );
	_emitter->setAngleVar( 0 );

	// emitter position
	_emitter->setPosVar( Vec2::ZERO );

	// life of particles
	_emitter->setLife( time );
	_emitter->setLifeVar( 0 );

	// spin of particles
	_emitter->setStartSpin( 0 );
	_emitter->setStartSpinVar( 0 );
	_emitter->setEndSpin( 0 );
	_emitter->setEndSpinVar( 0 );

	// color of particles
	_emitter->setStartColor( Color4F( 0.0f , 0.8f , 0.9f , 1.0f ) );
	_emitter->setStartColorVar( Color4F( 0 , 0 , 0 , 1.0f ) );
	_emitter->setEndColor( Color4F( 1.0f , 1.0f , 1.0f , 1.0f ) );
	_emitter->setEndColorVar( Color4F( 0 , 0 , 0 , 0 ) );

	// size, in pixels
	_emitter->setStartSize( 20 );
	_emitter->setStartSizeVar( 1 );
	_emitter->setEndSize( 0 );

	// emits per sound
	_emitter->setEmissionRate( _emitter->getTotalParticles( ) / _emitter->getLife( ) );

	// additive
	_emitter->setBlendAdditive( false );

	return _emitter;
}

Sequence * ZRBLoadingLayer::bezierCircle( float radius , float time , DirectionOfRotation direction )
{
	CCASSERT( radius > 0 , "半径应大于 0 " );
	CCASSERT( time > 0 , "时间应大于 0" );

	const float magicNumber = 0.551784;
	auto t = time / 4;

	ccBezierConfig bezier1;
	bezier1.controlPoint_1 = Vec2( magicNumber * radius , 0 );
	bezier1.controlPoint_2 = Vec2( radius , ( 1 - magicNumber ) * radius );
	bezier1.endPosition = Vec2( radius , radius );

	ccBezierConfig bezier2;
	bezier2.controlPoint_1 = Vec2( 0 , magicNumber * radius );
	bezier2.controlPoint_2 = Vec2( -( 1 - magicNumber )* radius , radius );
	bezier2.endPosition = Vec2( -radius , radius );

	ccBezierConfig bezier3;
	bezier3.controlPoint_1 = Vec2( -magicNumber * radius , 0 );
	bezier3.controlPoint_2 = Vec2( -radius , -( 1 - magicNumber ) * radius );
	bezier3.endPosition = Vec2( -radius , -radius );

	ccBezierConfig bezier4;
	bezier4.controlPoint_1 = Vec2( 0 , -magicNumber* radius );
	bezier4.controlPoint_2 = Vec2( ( 1 - magicNumber ) * radius , -radius );
	bezier4.endPosition = Vec2( radius , -radius );


	switch ( direction )
	{
		case CounterClockwise:

			return Sequence::create( BezierBy::create( t , bezier1 ) ,
									 BezierBy::create( t , bezier2 ) ,
									 BezierBy::create( t , bezier3 ) ,
									 BezierBy::create( t , bezier4 ) , NULL );

			break;

		case Clockwise:

			return Sequence::create( BezierBy::create( t , bezier1 ) ,
									 BezierBy::create( t , bezier2 ) ,
									 BezierBy::create( t , bezier3 ) ,
									 BezierBy::create( t , bezier4 ) ,
									 NULL )->reverse( );

		default:
			break;
	}
}
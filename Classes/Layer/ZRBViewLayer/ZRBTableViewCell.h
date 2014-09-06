
#ifndef __ZRBTableViewCell_H__
#define __ZRBTableViewCell_H__

#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

/**
*  ����  TableViewCell  �����ĸ����� ����, ͷ��, ����, �ɼ�
*  ����, ����, �ɼ�����������������С, ��ɫ,����
*  ������ռ�� TableViewCell �Ķ����� TableViewCell �ĸ߶ȳ��Ը��Զ�Ӧ������
*  ע: �����ֵ�˳���ܸı�
*/
class ZRBTableViewCell : public TableViewCell
{
public:

	// TableViewCell �и��ӽڵ�� Tag
	enum Flag
	{
		frist = 0 ,
		scound ,
		three ,
		four
	};

private:

	// ���а����ֵ�����, ��С, ��ɫ��Ϣ
	struct foutInfo
	{
		int foutSize;

		std::string fout;

		cocos2d::Color3B foutColor;
	};

	// ��ӷָ���
	cocos2d::Sprite * line;
	// ��� ZRBTableViewCell ����
	cocos2d::LayerColor * bg_layer;

	/**
	*   ��������, �������, �ɼ���������Ϣ
	*/
	CC_SYNTHESIZE( foutInfo , _foutRanking , FoutRanking );
	CC_SYNTHESIZE( foutInfo , _foutName , FoutName );
	CC_SYNTHESIZE( foutInfo , _foutScorer , FoutScorer );

	/**
	*  ����TableViewCell �а�������Ϣ
	*  ������Ĭ�ϵ� get ����
	*/
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _ranking , Ranking );
	CC_SYNTHESIZE_READONLY( cocos2d::Sprite * , _pic , Pic );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _name , name );
	CC_SYNTHESIZE_READONLY( cocos2d::Label * , _scorer , Scorer );


	/**
	*  TableViewCell �����ҷ�����������, ͷ��, ����, �ɼ�
	*  ��ֱλ�þ���, ˮƽλ���� TableViewCell �Ŀ�ȳ��Է����Ĵ�С����
	*  ���涨��������Ĵ�С���Ӳ�����Ĭ��set, get����
	*/
	CC_SYNTHESIZE( float , _partFirst , partFirst );
	CC_SYNTHESIZE( float , _partSecond , partSecond );
	CC_SYNTHESIZE( float , _partThree , partThree );
	CC_SYNTHESIZE( float , _partFour , partFour );


	/**
	*  ����� TableView �н��յ� size ��Ϣ
	*  ������Ĭ�ϵ�set . get ����
	*/
	CC_SYNTHESIZE( cocos2d::Size , _size , Size );

public:

	// ��Ա��������ʼֵ
	ZRBTableViewCell( );
	~ZRBTableViewCell( );

	// ��ʼ����Ա
	virtual bool init( );
	// ����ʱ���ó�Ա����
	virtual void onEnter( );
	virtual void onEixt( );

	// �� foutInfo ��ȡ����
	std::string getFout( foutInfo info ) { return info.fout; }
	// �� foutInfo ��ȡ�����С
	int getFoutSize( foutInfo info ) { return info.foutSize; }
	// �� foutInfo ��ȡ������ɫ
	cocos2d::Color3B getFoutColor( foutInfo info ) { return info.foutColor; }

	// ������������� foutInfo
	void setFoutRanking( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	// ���������������� foutInfo
	void setFoutName( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );
	// ���óɼ������ foutInfo
	void setFoutScorer( int x = 30 , std::string fout = "Marker Felt.ttf" , cocos2d::Color3B color = cocos2d::Color3B( 0 , 0 , 0 ) );

	// ���ñ�����ɫ
	void setBackgroundColor( cocos2d::Color3B color );

	CREATE_FUNC( ZRBTableViewCell );

private:

	// �������� label
	void setRanking( );
	// ����ͷ�� sprite
	void setPic( );
	// �������� label
	void setName( );
	// ���óɼ� label
	void setScorer( );

};


#endif

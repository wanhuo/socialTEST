
#ifndef __ZRBBaseGameLayer_H__
#define __ZRBBaseGameLayer_H__

#include "../ZRBHeroSprite.h"
#include "../ZRBGameMenu/ZRBGameFinishLayer.h"
#include "../ZRBGameMenu/ZRBGameMenuLayer.h"


#define PAUSE_ITEM_TAG 1000
#define COLOR_ITEM_1_TAG 1001
#define COLOR_ITEM_2_TAG 1002
#define COLOR_ITEM_3_TAG 1003
#define COLOR_ITEM_4_TAG 1004
#define COLOR_ITEM_5_TAG 1005
#define GOLD_ICON_TAG 1006
#define BG2_TAG 10001

enum layerBatchNodeBaseGame { batchNode1 , batchNode2 , batchNode3 , menuItem };
enum layerBaseGame { bg1BaseGame , bg2BaseGame , TimboBaseGame , itemBaseGame , labelBaseGame };

class ZRBBaseGameLayer : public Layer
{
public:
	//    enum menu
	//    {
	//        pause = 0x1000,
	//    };

	ZRBBaseGameLayer( );
	~ZRBBaseGameLayer( );

	virtual bool init( );
	CREATE_FUNC( ZRBBaseGameLayer );

protected:
	virtual void onEnter( );
	virtual void update( float delta ) override;

	///���������ҵ�����
	virtual Sprite * createTimboRandomPosHaveGold( );


	/**
	*  �����������ȵ�����
	*
	*  @param length �����ĳ���
	*  @param pos    ������λ��
	*
	*  @return ��������
	*/
	virtual Sprite * createTimbo( float length , Point pos );

	//��ʼ����
	virtual void initTimbos( );
	/// �����ٺ����Ӳ˵���ť
	virtual void replenishtimbosAndAddItem( );
	/// ��ť����ص�
	void colorItemClick( Ref *ref );
	/// ��ͣ��Ϸ
	virtual void pauseItemClick( Ref *ref );
	/// ������������
	void setBg1( std::string fileNameOrFrameFileName );
	/**
	*  ����������� ����ƶ�
	*
	*  @param ImageNum  ����ͼƬ����
	*  @param _isRanPos λ���Ƿ����
	*/
	void setBg2( int ImageNum , bool _isRanPos );
	///  ������ת���� pSceneManage
	void setModeScene( ZRBSceneManager _manager );
	/// ����ʵ��
	virtual void createTimboRandomPosHaveGoldOtherFunc( Sprite *preSp , Sprite *sp );
	/// return pHero;
	ZRBHeroSprite* getHero( );

protected:

	/// �����ɼ�
	const int standard = 50;
	/// ��ʼ������
	void initObject( );
	///    pCanJump=true;
	void setCanJump( );
	/// ������ɫ��ť �����˳�
	void createMenuItem( );
	/// ������һ����
	void heroJumpNext( );
	///  ��ť�������ֶ���
	void resetItemPos( );
	/// ��Ϸ����
	virtual void showGameFinish( );

	///  ��ǰ��ɫ����
	int pColorNum;
	/// ��ǰ�߶�
	float pCurrentHeight;
	/// �����߶�
	float pUpdateHeight;
	/// ʧ��
	bool pIsLost;
	/// �ܷ���Ծ
	bool pCanJump;
	// �������
	int pGoldNum;
	/// �ز���
	std::string pNameAfterStr;

	/// ��Ϸ��ť
	Menu *pMenu;
	/// ��ǰ�ɼ�
	Label *pScoreLabel;
	/// ��ǰ���
	Label *pGoldNumLabel;
	///��ǰվ�ŵ���
	Sprite *pCurrentTimbo;
	/// ��������
	Sprite *pBg1;
	/// �����
	SpriteBatchNode *pBatchNode;
	//����
	ZRBHeroSprite *pHero;
	/// ��ťԭʼ��С
	Size pItemDefaultSize;
	/// ��ת����
	ZRBSceneManager pSceneManager;

	///5����ɫ
	Color3B pAllColors [ 5 ];
	//��s
	Vector<Sprite *> pTimbos;
	Vector<Sprite *> pGolds;
	/// �˵�
	Vector<MenuItemSprite *> pItems;
	///��ͷ���ϵ��ٶ�
	CC_SYNTHESIZE( int , pUpSpeed , UpSpeed );
	/// ��Ļ�߶ȵ�����
	CC_SYNTHESIZE( int , pDisplayItemHeight , DisplayItemHeight );
	///  ��ҳ��ָ��� 2 / X
	CC_SYNTHESIZE( int , _goldChance , GoldChance );
};


#endif
//
//  GameLayer.h
//  FlappyBird
//
//  Created by DoubleHH on 14-3-13.
//
//

#ifndef __FlappyBird__GameLayer__
#define __FlappyBird__GameLayer__

#include "FBHeaders.h"
#include "BarPipe.h"
#include "BBButton.h"


class GameLayer : public CCLayer {
public:
    GameLayer():groundSpeed(3.5), roleConstYSpeed(10), roleYSpeed(0), roleAccelerate(0.6), groundHeight(0), isPaused(true), mScoreLabel(NULL), score(0) {};
    ~GameLayer();
    
    virtual bool init();
    void extraInit();
    static CCScene *scene();
    CREATE_FUNC(GameLayer);
    void update(float fDelta);
    virtual void registerWithTouchDispatcher(void);
    virtual void onExit();
    
    // default implements are used to call script callback if exist
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void gameOver();
    void restart();
    
private:
    void resetRole();
    void resetCollisions();
    float getStartCollsionX();
    
private:
    CC_PROPERTY(int , score, Score);
    CCLabelTTF *mScoreLabel;
    void updateScore();
    
private:
    CC_SYNTHESIZE(int, countdownNum, CountdownNum);
    void preCountdown();
    void beginCountdown(int second);
    void countdownSeconds();
    void countdonwDone();
    
public:
    CC_SYNTHESIZE(float, groundHeight, GroundHeight);
    CC_SYNTHESIZE(bool, isPaused, IsPaused);
    
private:
    void initRole();
    CC_PROPERTY(ROLE_STATE, roleState, RoleState);
    CC_SYNTHESIZE(float, roleConstYSpeed, RoleConstYSpeed);
    CC_SYNTHESIZE(float, roleYSpeed, RoleYSpeed);
    CC_SYNTHESIZE(float, roleAccelerate, RoleAccelerate);
    
private:
    CCSprite *mRole;
    CCArray *mGrounds;
    
    CC_SYNTHESIZE(float, groundSpeed, GroundSpeed);
    
private:
    void roleUpdate(float dt);
    void roleJumpUpLogic();
    void roleJumpDownLogic();
    
private:
    void initGround();
    void updateGround(float dt);
    
private:
    // 碰撞检测
    bool isCollisionArea(COLL_STATE state, CCRect roleBox, CCRect collisionBox);
    bool isCollisionLeft(CCRect roleBox, CCRect collisionBox);
    bool isCollisionRight(CCRect roleBox, CCRect collisionBox);
    bool isCollisionTop(CCRect roleBox, CCRect collisionBox);
    bool isCollisionBottom(CCRect roleBox, CCRect collisionBox);
    // 碰撞修复
    void fixCollision(COLL_STATE state, CCNode *role, cocos2d::CCRect collisionBox);

    
    void initCollisions();
    CCArray *mCollisionArray;
    void updateCollisions(float dt);
    
    bool isCollisionWithBar(COLL_STATE state, BarPipe *barPipe);
    BarPipe *getWillCollisionBar();
};

#endif /* defined(__FlappyBird__GameLayer__) */

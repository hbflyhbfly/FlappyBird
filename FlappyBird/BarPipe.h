//
//  BarPipe.h
//  FlappyBird
//
//  Created by Syuuhi on 14-3-19.
//
//

#ifndef __FlappyBird__BarPipe__
#define __FlappyBird__BarPipe__

#include <iostream>
#include "FBHeaders.h"

class BarPipe : public CCObject {
public:
    BarPipe():upBar(NULL), downBar(NULL), barPositionX(0), mParent(NULL), barInterval(150), isPassed(false) {};
    ~BarPipe();
    
    virtual bool init();
    static BarPipe *randomCreate(CCNode *parent);
    void setParentNode(CCNode *parent);
    void setRandomY();
    
    static CCSize getSize();
    
public:
    CC_SYNTHESIZE_RETAIN(CCSprite *, upBar, UpBar);
    CC_SYNTHESIZE_RETAIN(CCSprite *, downBar, DownBar);
    CC_PROPERTY(float, barPositionX, BarPositionX);
    CC_SYNTHESIZE(float, barInterval, BarInterval);
    
    /**
     小鸟是否已经经过了这个柱子, 用于计算分数
     **/
    CC_SYNTHESIZE(bool, isPassed, IsPassed);
    
    CCNode *mParent;
    
};

#endif /* defined(__FlappyBird__BarPipe__) */

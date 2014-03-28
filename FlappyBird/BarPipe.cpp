//
//  BarPipe.cpp
//  FlappyBird
//
//  Created by Syuuhi on 14-3-19.
//
//

#include "BarPipe.h"
#include "GameLayer.h"

#pragma mark - BarPipe

BarPipe::~BarPipe() {
    
    CC_SAFE_RELEASE_NULL(upBar);
    CC_SAFE_RELEASE_NULL(downBar);
}

bool BarPipe::init() {
    
    upBar = CCSprite::create("up_bar.png");
    downBar = CCSprite::create("down_bar.png");
    CC_SAFE_RETAIN(upBar);
    CC_SAFE_RETAIN(downBar);
    
    upBar->setAnchorPoint(ccp(0, 0));
    downBar->setAnchorPoint(upBar->getAnchorPoint());
    
    upBar->setPositionX(0);
    downBar->setPositionX(upBar->getPositionX());
    
    return true;
}

void BarPipe::setRandomY() {
    if (!mParent) {
        return;
    }
    GameLayer *layer = (GameLayer *)mParent;
    float groundHeight = layer->getGroundHeight();
    // 计算出管道最多能上下的最大值
    float randomTotal = upBar->getContentSize().height + downBar->getContentSize().height + getBarInterval() - (mParent->getContentSize().height - groundHeight);
    float randomY = CCRANDOM_0_1() * randomTotal;
    downBar->setPositionY(-randomY + groundHeight);
    upBar->setPositionY(downBar->getPositionY() + getHeight(downBar) + getBarInterval());
}

BarPipe *BarPipe::randomCreate(CCNode *parent) {
    
    BarPipe *pBarPipe = new BarPipe();
    if (pBarPipe && pBarPipe->init()) {
        
        pBarPipe->setParentNode(parent);
        pBarPipe->setRandomY();
        pBarPipe->autorelease();
        return pBarPipe;
    }
    CC_SAFE_DELETE(pBarPipe);
    return NULL;
}

void BarPipe::setParentNode(cocos2d::CCNode *parent) {
    
    if (!parent) {
        return;
    }
    mParent = parent;
    if (upBar) {
        parent->addChild(upBar, ZORDER_COLLISION);
    }
    if (downBar) {
        parent->addChild(downBar, ZORDER_COLLISION);;
    }
}

void BarPipe::setBarPositionX(float var) {
    if (upBar) {
        upBar->setPositionX(var);
    }
    if (downBar) {
        downBar->setPositionX(var);
    }
}

float BarPipe::getBarPositionX() {
    if (upBar) {
        return upBar->getPositionX();
    }
    if (downBar) {
        return downBar->getPositionX();
    }
    return 0;
}

CCSize BarPipe::getSize() {
    return CCSize(52, 319);
}

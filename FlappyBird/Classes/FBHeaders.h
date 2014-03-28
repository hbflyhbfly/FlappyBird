//
//  FBHeaders.h
//  FlappyBird
//
//  Created by DoubleHH on 14-3-13.
//
//

#ifndef FlappyBird_FBHeaders_h
#define FlappyBird_FBHeaders_h

#import "cocos2d.h"
#import "FrameUtil.h"

USING_NS_CC;

const int ZORDER_GROUND = 2;
const int ZORDER_COLLISION = 1;
const int ZORDER_ROLE = 10;
const int ZORDER_COUNTDOWN = 11;
const float INTERVAL_COLLISION = 150.0f;

// 主角状态
typedef enum {
    ROLE_STATE_JUMP_UP, // 跳起
    ROLE_STATE_JUMP_DOWN,//跳起后下落抛物线
}ROLE_STATE;
//碰撞方向
typedef enum {
    COLL_STATE_INVALID = 0,
    COLL_STATE_LEFT,
    COLL_STATE_RIGHT,
    COLL_STATE_TOP,
    COLL_STATE_BOTTOM,
}COLL_STATE;

#endif

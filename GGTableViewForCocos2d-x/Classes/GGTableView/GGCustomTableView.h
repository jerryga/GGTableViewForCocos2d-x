//
//  GGCustomTableView.h
//  MagicCardGame
//
//  Created by Static Ga on 13-7-17.
//
//

#ifndef __MagicCardGame__GGCustomTableView__
#define __MagicCardGame__GGCustomTableView__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

class GGCustomTableView :public cocos2d::extension::CCTableView{
    
private:
    cocos2d::CCPoint startLocation;
    cocos2d::CCPoint endLocation;
    float dis;
public:
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    static GGCustomTableView* create(cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::CCSize size);
    static GGCustomTableView* create(cocos2d::extension::CCTableViewDataSource* dataSource, cocos2d::CCSize size, CCNode *container);
    float getDis (){return dis;}
    bool isDraging() {return dis == 0? false:true;}
};


#endif /* defined(__MagicCardGame__GGCustomTableView__) */

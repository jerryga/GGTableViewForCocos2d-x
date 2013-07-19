//
//  GGCustomMenu.h
//  MagicCardGame
//
//  Created by Static Ga on 13-7-17.
//
//

#ifndef __MagicCardGame__GGCustomMenu__
#define __MagicCardGame__GGCustomMenu__

#include <iostream>
#include "cocos2d.h"

class GGCustomMenu :public cocos2d::CCMenu{
    
public:
    virtual void registerWithTouchDispatcher();
    static GGCustomMenu * create(cocos2d::CCMenuItem* item, ...);
    static GGCustomMenu* createWithItems(cocos2d::CCMenuItem* item, va_list args);
    static GGCustomMenu *createWithArray(cocos2d::CCArray* pArrayOfItems);
};


#endif /* defined(__MagicCardGame__GGCustomMenu__) */

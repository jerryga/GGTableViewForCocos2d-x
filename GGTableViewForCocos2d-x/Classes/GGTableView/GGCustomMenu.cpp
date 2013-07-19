//
//  GGCustomMenu.cpp
//  MagicCardGame
//
//  Created by Static Ga on 13-7-17.
//
//

#include "GGCustomMenu.h"

#define tMenuTouchPriority 1

using namespace cocos2d;

GGCustomMenu* GGCustomMenu::createWithArray(CCArray* pArrayOfItems)
{
    GGCustomMenu *pRet = new GGCustomMenu();
    if (pRet && pRet->initWithArray(pArrayOfItems))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}


void GGCustomMenu::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, tMenuTouchPriority, false);
}

GGCustomMenu * GGCustomMenu::create(CCMenuItem* item, ...)
{
    va_list args;
    va_start(args,item);
    
    GGCustomMenu *pRet = GGCustomMenu::createWithItems(item, args);
    
    va_end(args);
    
    return pRet;
}
GGCustomMenu* GGCustomMenu::createWithItems(CCMenuItem* item, va_list args)
{
    CCArray* pArray = NULL;
    if( item )
    {
        pArray = CCArray::create(item, NULL);
        CCMenuItem *i = va_arg(args, CCMenuItem*);
        while(i)
        {
            pArray->addObject(i);
            i = va_arg(args, CCMenuItem*);
        }
    }
    
    return GGCustomMenu::createWithArray(pArray);
}


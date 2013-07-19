//
//  GGCustomCell.cpp
//  GGTableViewForCocos2d-x
//
//  Created by Static Ga on 13-7-19.
//
//

#include "GGCustomCell.h"
#include "GGCustomMenu.h"
#include "GGCustomTableView.h"

#define kCardCellBG "menuBG.png"

using namespace cocos2d;
using namespace extension;

bool GGCustomCell::init() {
    if (!CCTableViewCell::init()) {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite *bg = CCSprite::create(kCardCellBG);
    CCMenuItemSprite *item = CCMenuItemSprite::create(bg, NULL, this, menu_selector(GGCustomCell::itemClicked));
    item->setPosition(CCPointMake(winSize.width/2, bg->getContentSize().height/2));
    
    GGCustomMenu *menu = GGCustomMenu::create(item,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    return true;
}

GGCustomCell *GGCustomCell::create() {
    GGCustomCell *cell = new GGCustomCell();
    if (cell && cell->init()) {
        cell->autorelease();
        return cell;
    }
    CC_SAFE_DELETE(cell);
    return NULL;
}

void GGCustomCell::itemClicked(cocos2d::CCObject *pObj) {

    //judge if the tableView is dragging
    
    GGCustomTableView *pNode = dynamic_cast< GGCustomTableView* >((this->getParent()->getParent()));
    if (pNode && pNode->isDraging()) {
        return;
    }
    //handle the menu clicked event
    
    CCLog("itemClcked");
}

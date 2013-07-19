#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GGCustomTableView.h"
#include "GGCustomCell.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace extension;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    GGCustomTableView *tableView = GGCustomTableView::create(this, CCSizeMake(winSize.width, winSize.height));
    this->addChild(tableView);
    
    return true;
}

#pragma mark - CCTableViewDataSource

CCSize HelloWorld::tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx) {
    return CCSizeMake(table->getContentSize().width, 100);
}

CCTableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx) {
    GGCustomCell *cell = (GGCustomCell *)table->dequeueCell();
    if (!cell) {
        cell = GGCustomCell::create();
    }
    return cell;
}

unsigned int HelloWorld::numberOfCellsInTableView(cocos2d::extension::CCTableView *table) {
    return 10;
}


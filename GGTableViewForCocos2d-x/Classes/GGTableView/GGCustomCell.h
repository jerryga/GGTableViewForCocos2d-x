//
//  GGCustomCell.h
//  GGTableViewForCocos2d-x
//
//  Created by Static Ga on 13-7-19.
//
//

#ifndef __GGTableViewForCocos2d_x__GGCustomCell__
#define __GGTableViewForCocos2d_x__GGCustomCell__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

class GGCustomCell :public cocos2d::extension::CCTableViewCell{
    
public:
    bool init();
    static GGCustomCell *create();
private:
    void itemClicked(cocos2d::CCObject *pObj);
};

#endif /* defined(__GGTableViewForCocos2d_x__GGCustomCell__) */

//
//  GGCustomTableView.cpp
//  MagicCardGame
//
//  Created by Static Ga on 13-7-17.
//
//

#include "GGCustomTableView.h"

using namespace cocos2d;
using namespace extension;

GGCustomTableView* GGCustomTableView::create(CCTableViewDataSource* dataSource, CCSize size)
{
    return GGCustomTableView::create(dataSource, size, NULL);
}

GGCustomTableView* GGCustomTableView::create(CCTableViewDataSource* dataSource, CCSize size, CCNode *container)
{
    GGCustomTableView *table = new GGCustomTableView();
    table->initWithViewSize(size, container);
    table->autorelease();
    table->setDataSource(dataSource);
    table->_updateCellPositions();
    table->_updateContentSize();
    return table;
}


void GGCustomTableView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    endLocation = this->getContainer()->convertTouchToNodeSpace(pTouch);
    dis = ccpDistance(startLocation, endLocation);

    if (!this->isVisible()) {
        return;
    }
    
    if (m_pTouchedCell){
		CCRect bb = this->boundingBox();
		bb.origin = m_pParent->convertToWorldSpace(bb.origin);
        
		if (bb.containsPoint(pTouch->getLocation()) && m_pTableViewDelegate != NULL)
        {
            m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
            m_pTableViewDelegate->tableCellTouched(this, m_pTouchedCell);
        }
        
        m_pTouchedCell = NULL;
    }
    
    CCScrollView::ccTouchEnded(pTouch, pEvent);
}


bool GGCustomTableView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    startLocation = CCPointZero;
    if (!this->isVisible()) {
        return false;
    }
    bool touchResult = CCScrollView::ccTouchBegan(pTouch, pEvent);
    
    if(m_pTouches->count() == 1) {
        unsigned int        index;
        CCPoint           point;
        
        point = this->getContainer()->convertTouchToNodeSpace(pTouch);
        startLocation = point;
        index = this->_indexFromOffset(point);
		if (index == CC_INVALID_INDEX)
		{
			m_pTouchedCell = NULL;
		}
        else
		{
			m_pTouchedCell  = this->cellAtIndex(index);
		}
        
        if (m_pTouchedCell && m_pTableViewDelegate != NULL) {
            m_pTableViewDelegate->tableCellHighlight(this, m_pTouchedCell);
        }
    
        
    }
    else if(m_pTouchedCell) {
        if(m_pTableViewDelegate != NULL) {
            m_pTableViewDelegate->tableCellUnhighlight(this, m_pTouchedCell);
        }
        
        m_pTouchedCell = NULL;
    }
    
   
    
    return touchResult;
}

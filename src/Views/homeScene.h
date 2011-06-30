//
//  homeScene.h
//  collectionsZone
//
//  Created by Thitiphong on 6/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "mnhBaseScene.h"
#include "baseButton.h"
#include "mnhBottomMenu.h"

enum {
    MNH_HOME_SCENE_FIRST,
    MNH_HOME_SCENE_SECOND,
    MNH_HOME_SCENE_TOTAL
};

class homeScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
        void activate();
        
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
    
        baseButton button;
    private:
        ofImage homeScreen1;
        ofImage homeScreen2;
};
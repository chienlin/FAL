//
//  activityScene.h
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "mnhBaseScene.h"
#include "baseButton.h"

enum {
    MNH_ACTIVITY_SCENE_FIRST,
    MNH_ACTIVITY_SCENE_SECOND,
    MNH_ACTIVITY_SCENE_THIRD,
    MNH_ACTIVITY_SCENE_FOURTH,
    MNH_ACTIVITY_SCENE_TOTAL
};


class activityScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
        void activate();
    void deactivate();
        
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
        //set up for subscene
        ofImage activity1;
        ofImage activity2;
        ofImage activity3;
        ofImage levelup;
        baseButton levelupB;
        baseButton startoverB;
        baseButton next;
        baseButton back;
        baseButton mail;
    
};
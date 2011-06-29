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
//#include "ofxMail.h"

enum {
    MNH_ACTIVITY_SCENE_FIRST,
    MNH_ACTIVITY_SCENE_SECOND,
    MNH_ACTIVITY_SCENE_THIRD,
    MNH_ACTIVITY_SCENE_FOURTH,
    MNH_ACTIVITY_SCENE_FIVE,
    MNH_ACTIVITY_SCENE_SIX,
    MNH_ACTIVITY_SCENE_SEVEN,
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
    
        //for activity1
        baseButton act1B1;
        baseButton act1B2;
        baseButton act1B3;
        
        ofImage act1B1Img;
        ofImage act1B2Img;
        ofImage act1B3Img;
        ofImage act1B1PreImg;
        ofImage act1B2PreImg;
        ofImage act1B3PreImg;
        ofImage act1c1Img;
        ofImage act1w1Img;
        ofImage act1w2Img;


    
        // for levelup
        baseButton levelupB;
        baseButton startoverB;
        baseButton next;
        baseButton back;
        baseButton mail;
        //for back to resource
        baseButton backtoresourceB;
        bool from_act;
        int location;
    
//        ofxMail theMail;
    
};
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
#include "ofxMail.h"

enum {
    MNH_ACTIVITY_SCENE_AC1,//activity1            #0
    MNH_ACTIVITY_SCENE_AC1C1,//activity1 correct1 #1
    MNH_ACTIVITY_SCENE_AC1W1,//activity1 wrong1   #2
    MNH_ACTIVITY_SCENE_AC1W2,//activity1 wrong2   #3
    
    
    MNH_ACTIVITY_SCENE_AC2,//activity2            #4
    MNH_ACTIVITY_SCENE_AC2C1,//activity2 correct1 #5
    MNH_ACTIVITY_SCENE_AC2W1,//activity2 wrong1   #6
    MNH_ACTIVITY_SCENE_AC2W2,//activity2 wrong2   #7
    
    MNH_ACTIVITY_SCENE_AC3,//activity3            #8
    MNH_ACTIVITY_SCENE_AC3C1,//activity3 correct1 #9
    MNH_ACTIVITY_SCENE_AC3W1,//activity3 wrong1   #10
    
    MNH_ACTIVITY_SCENE_SUM,//summary              #11
    MNH_ACTIVITY_SCENE_LEVELUP,//levelup          #12
    MNH_ACTIVITY_SCENE_TOTAL
};


class activityScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
        void activate();
        void deactivate();
        bool notice();
            
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
        
    private:
        baseButton back;
        baseButton next;
        baseButton back_to_resource;
        int location;
        bool reset;
    
        ofImage backImg_off;
        ofImage backImg_on;
        ofImage nextImg_off;
        ofImage nextImg_on;

    
        // for activity1
        ofImage ac1;
        ofImage ac1c1;
        ofImage ac1w1;
        ofImage ac1w2;
    
        baseButton ac1b1;
        ofImage ac1b1_off;
        ofImage ac1b1_on;
        baseButton ac1b2;
        ofImage ac1b2_off;
        ofImage ac1b2_on;
        baseButton ac1b3;
        ofImage ac1b3_off;
        ofImage ac1b3_on;
     
        // for activity2
        ofImage ac2;
        ofImage ac2c1;
        ofImage ac2w1;
        ofImage ac2w2;
    
        baseButton ac2b1;
        ofImage ac2b1_off;
        ofImage ac2b1_on;
        baseButton ac2b2;
        ofImage ac2b2_off;
        ofImage ac2b2_on;
        baseButton ac2b3;
        ofImage ac2b3_off;
        ofImage ac2b3_on;
        
        //for activity3
        ofImage ac3;
        ofImage ac3c1;
        ofImage ac3w1;
    
        baseButton ac3b1;
        baseButton ac3b2;
        ofImage ac3b1_off;
        ofImage ac3b1_on;
        ofImage ac3b2_off;
        ofImage ac3b2_on;
        
        //for summary 
        ofImage levelupBImg;
        ofImage summary;
        baseButton levelupB;
        //for levelup
        ofImage levelup;
        ofImage startoverImg;
        ofImage inviteImg;
        baseButton invite;
        baseButton startover;
        
        ofxMail theMail;
    
    
    
//        ofxMail theMail;
    
};
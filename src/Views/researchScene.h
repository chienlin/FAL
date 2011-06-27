//
//  researchScene.h
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "mnhBaseScene.h"
#include "ofx3DModelLoader.h"
#include "baseButton.h"

enum {
    MNH_RESEARCH_SCENE_FIRST,
    MNH_RESEARCH_SCENE_SECOND,
    MNH_RESEARCH_SCENE_THIRD,
    MNH_RESEARCH_SCENE_FOURTH,
    MNH_RESEARCH_SCENE_FIFTH,
    MNH_RESEARCH_SCENE_TOTAL
};

enum traumaType {
    MNH_FAL_ANTEMORTEM,
    MNH_FAL_PERIMORTEM,
    MNH_FAL_POSTMORTEM
};


class researchScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
    
        void activate();
        void deactivate();
    
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
        void touchDoubleTap(ofTouchEventArgs &touch);
    
    private:
        ofImage researchScreen;
        
        //set up for subButton
        ofImage caseI;
        ofImage infoI;
        ofImage hintI;
        
        
        baseButton caseB;
        baseButton infoB;
        baseButton hintB;
        
        //set up back and restart button
        baseButton back;
        baseButton start;
        
        //set up for t button
        ofImage anteI;
        ofImage periI;
        ofImage postI;
        
        baseButton anteB;
        baseButton periB;
        baseButton postB;
        baseButton backtoinfo;        
        
        //set up for subscene
        ofImage caseP;
        ofImage infoP;
        ofImage hintP;
                
        //setup for 3dmodel 
        ofx3DModelLoader *boneModel;
        
        float touchID;
        float touchX, touchY;
        float modelXPos, modelYPos;
        
        bool firstDoubleTap, isTouchDown;
        
        traumaType t;
        
        void init3DViewer(traumaType trauma);
        void drawModel();
    
        
};
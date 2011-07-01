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
#include "ofxVectorMath.h"
#include "ofx3DModelLoader.h"
#include "baseButton.h"
#include "mnhBottomMenu.h"
#include "activityScene.h"



enum {
    MNH_RESEARCH_SCENE_FIRST,
    MNH_RESEARCH_SCENE_SECOND,
    MNH_RESEARCH_SCENE_THIRD,
    MNH_RESEARCH_SCENE_FOURTH,
    MNH_RESEARCH_SCENE_FIFTH,
    MNH_RESEARCH_SCENE_SIX,
    MNH_RESEARCH_SCENE_SEVEN,
    MNH_RESEARCH_SCENE_TOTAL
};

enum traumaType {
    MNH_FAL_ANTEMORTEM1,
    MNH_FAL_ANTEMORTEM2,
    MNH_FAL_PERIMORTEM1,
    MNH_FAL_PERIMORTEM2,
    MNH_FAL_POSTMORTEM
};


class researchScene : public mnhBaseScene {
	public:
		void setup();
		void update();
		void draw();
    
        void activate();
        void deactivate();
       // bool notice();
        bool getnotice(bool A);
    
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
        void touchDoubleTap(ofTouchEventArgs &touch);
    
    private:
        bool reset;
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
        
        //set up for 3D button
        ofImage anteI;
        ofImage periI;
        ofImage postI;
        
        baseButton anteB;
        baseButton periB;
        baseButton postB;
        baseButton backtoinfo;
        baseButton backtoact;

        
        //set up for subscene
        ofImage caseP;
        ofImage infoP;
        ofImage hintP;
    
        ofImage anteP;
        ofImage periP;
        ofImage postP;
    
        //setup for 3dmodel 
        ofx3DModelLoader *boneModel;
        ofxVec3f posCord;
        
        
        float touchID;
        float touchX, touchY;
        float modelXPos, modelYPos;
        float modelSpaceWidth;
        float theta;
        float sphereRadius;
        float stopMomentum;
        
        bool firstDoubleTap, isTouchDown;
        bool bTouchMove;
        bool bFirstRun;
        bool a;
    
        int bonescale;
        //try to track
        int location_at_act;

        baseButton swap;

        ofxVec3f prevSpherePt, currSpherePt;
        ofxVec3f axis;
        ofxVec3f firstPt;
        GLfloat modelMatrix[16];
        
        ofxVec3f screenToSphere(ofxVec2f p);
        void matrixCapture();
        void init3DViewer(traumaType trauma);
        void drawModel();
        
};
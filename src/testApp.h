#pragma once

#ifndef _testApp
#define _testApp

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "ofxTweenzor.h"

#include "mnhSceneManager.h"

#include "homeScene.h"
#include "researchScene.h"
#include "activityScene.h"

#include "mnhBottomMenu.h"

class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);

	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
    
    mnhBaseScene* scenes[MNH_TOTAL_SCENES];
    
    //Managers
    mnhSceneManager* mnhSM;
    mnhAssetManager* mnhAssets;
    
    //Menu
    mnhBottomMenu menu;
};

#endif

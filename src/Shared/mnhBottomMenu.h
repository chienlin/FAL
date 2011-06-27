//
//  mnhBottomMenu.h
//  mnhPrototype
//
//  Created by Stephen Varga on 6/15/11.
//  Copyright 2011 Vargatron. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "baseButton.h"
#include "mnhAssetManager.h"
#include "mnhSceneManager.h"
#include "Tweenzor.h"

enum buttonTypes {
    MNH_BTM_MENU_HOME,
    MNH_BTM_MENU_RESEARCH,
    MNH_BTM_MENU_ACTIVITY,
    MNH_BTM_MENU_TOTAL
};


#define MNH_BTM_MENU_BTN_W 125
#define MNH_BTM_MENU_BTN_H 60

class mnhBottomMenu : public baseButton {
	public:
		void setup();
		void update();
		void draw();
    
        int drawSeparatorLine(int x);
    
        void show();
        void hide();
    
        void touchDown(ofTouchEventArgs &touch);
        void touchMoved(ofTouchEventArgs &touch);
        void touchUp(ofTouchEventArgs &touch);
    
        string labels[MNH_BTM_MENU_TOTAL];
        baseButton buttons[MNH_BTM_MENU_TOTAL];
    
        mnhAssetManager* mnhAssets;
        mnhSceneManager* mnhSM;
    private:
        bool bShowing;
        int showingY;
    
        ofImage bgImage;
};
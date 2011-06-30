//
//  mnhBaseScene.h
//  collectionsZone
//
//  Created by Stephen Varga on 6/8/11.
//  Copyright 2011 Parsons the New School for Design. All rights reserved.
//

#pragma once
#include "mnhSceneManager.h"
#include "mnhAssetManager.h"
#include "ofxSceneManagerScene.h"

class mnhSceneManager;

class mnhBaseScene : public ofxSceneManagerScene {
	public:
        mnhBaseScene();
		virtual void setup();
		virtual void update();
		virtual void draw();
    
        string sceneName;
        
        mnhSceneManager* mnhSM;
        mnhAssetManager* mnhAssets;
    
    
        ofxSceneManager2 mgr;
    protected:
        void drawGrid();
};
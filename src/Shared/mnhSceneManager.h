//
//  mnhSceneManager.h
//  collectionsZone
//
//  Created by Stephen Varga on 6/8/11.
//  Copyright 2011 Parsons the New School for Design. All rights reserved.
//

#pragma once
#include "ofxSceneManager2.h"

enum scene {
    MNH_SCENE_HOME,
    MNH_SCENE_RESEARCH,
    MNH_SCENE_ACTIVITY,
//    MNH_SCENE_LEVELUP,
    MNH_TOTAL_SCENES //Always keep this one in here and keep it last!
};

class mnhSceneManager : public ofxSceneManager2 {
	public:
        static mnhSceneManager* getInstance();
    private:
        mnhSceneManager();
        ~mnhSceneManager();
        
        static mnhSceneManager* pmnhSceneManager;
};
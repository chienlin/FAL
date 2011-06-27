//
//  homeScene.cpp
//  collectionsZone
//
//  Created by Thitiphong on 6/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "homeScene.h"

//------------------------------------------------------------------
void homeScene::setup() {
   
    button.setSize(100, 50);
    button.setPos(ofGetWidth()/2 - button.rect.width/2,500);
    button.setLabel("Next Scene!", &mnhAssets->whitneySemiBold22);
    sceneName = "Home";
    
    homeScreen1.loadImage("images/screens/home.png");
    homeScreen2.loadImage("images/screens/memo.png");
    
    
    
    mgr.setCurScene(MNH_HOME_SCENE_FIRST);
}



//------------------------------------------------------------------
void homeScene::update() {
    switch(mgr.getCurScene()) {
        case MNH_HOME_SCENE_FIRST:
            //Do stuff
            break;
        case MNH_HOME_SCENE_SECOND:
             //Do stuff
            break;
       
    }
}



//------------------------------------------------------------------
void homeScene::draw() {
    ofEnableAlphaBlending();
    drawGrid();
    
    string sceneName = "";
    switch(mgr.getCurScene()) {
        case MNH_HOME_SCENE_FIRST:
            
            sceneName = "First Sub Scene!";
            ofSetColor(255, 255, 255);
            homeScreen1.draw(0,0);
             break;
        case MNH_HOME_SCENE_SECOND:
            sceneName = "Second Sub Scene!";
            ofSetColor(255, 255, 255);
            homeScreen2.draw(0,0);
            break;
       
    }
    ofDisableAlphaBlending();
    

    button.draw();

}





//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void homeScene::touchDown(ofTouchEventArgs &touch){
    button.touchDown(touch);
}


//--------------------------------------------------------------
void homeScene::touchMoved(ofTouchEventArgs &touch){
    button.touchMoved(touch);
}


//--------------------------------------------------------------
void homeScene::touchUp(ofTouchEventArgs &touch){
    //Switch Scenes
    if(button.isPressed()) {
        if(mgr.getCurScene() < MNH_HOME_SCENE_TOTAL-1) {
            mgr.setCurScene(mgr.getCurScene() + 1);
        } else {
            mnhSM->setCurScene(MNH_SCENE_RESEARCH);
            mgr.setCurScene(0);

        }
    }
    button.touchUp(touch);
}
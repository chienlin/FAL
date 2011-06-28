//
//  activityScene.cpp
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "activityScene.h"

//------------------------------------------------------------------
void activityScene::setup() {
    //set up for subscene
    activity1.loadImage("images/screens/activity1.png");
    activity2.loadImage("images/screens/activity2.png");
    activity3.loadImage("images/screens/activity3.png");
    levelup.loadImage("images/screens/levelup.png");
    
    //level up button
    levelupB.setSize(100, 50);
    levelupB.setPos(ofGetWidth()/2 - levelupB.rect.width/2,ofGetHeight()-levelupB.rect.height);
    levelupB.setLabel("Level Up!", &mnhAssets->whitneySemiBold22);
    
    //start over button
    startoverB.setSize(100, 50);
    startoverB.setPos(startoverB.rect.width/2,startoverB.rect.height);
    startoverB.setLabel("Back to Activity!", &mnhAssets->whitneySemiBold22);
    
    next.setSize(100, 50);
    next.setPos(next.rect.width/2,next.rect.height);
    next.setLabel("Next", &mnhAssets->whitneySemiBold22);
    
    //mail button for levelup page
    mail.setSize(100, 50);
    mail.setPos(mail.rect.width/2,mail.rect.height);
    mail.setLabel("Mail", &mnhAssets->whitneySemiBold22);

}



//------------------------------------------------------------------
void activityScene::update() {
}
//------------------------------------------------------------------
void activityScene::activate() {
    
    mgr.setCurScene(MNH_ACTIVITY_SCENE_FIRST);
    cout << "Activate Activity" << endl;
}

//------------------------------------------------------------------
void activityScene::deactivate() {

    cout << "Deactivate Activity" << endl;
}




//------------------------------------------------------------------
void activityScene::draw() {
    ofEnableAlphaBlending();
    drawGrid();
    
    string sceneName = "";
    switch(mgr.getCurScene()) {
        case MNH_ACTIVITY_SCENE_FIRST:
            activity1.draw(0,0);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-50-next.rect.height);
            sceneName = "First Sub Scene!";
            
            break;
        case MNH_ACTIVITY_SCENE_SECOND:
            activity2.draw(0,0);
//            startoverB.draw(0,ofGetHeight()-50-startoverB.rect.height);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-50-next.rect.height);

            sceneName = "Second Sub Scene!";
            
            break;
        case MNH_ACTIVITY_SCENE_THIRD:
            activity3.draw(0,0);
            startoverB.draw(ofGetWidth()-startoverB.rect.width,ofGetHeight()-50-startoverB.rect.height);
            levelupB.draw(ofGetWidth()-levelupB.rect.width,ofGetHeight()-50-levelupB.rect.height-startoverB.rect.height-20);
            sceneName = "Third Sub Scene!";
            
            break;
        case MNH_ACTIVITY_SCENE_FOURTH:
            levelup.draw(0,0);
            startoverB.draw(0,ofGetHeight()-50-startoverB.rect.height);
           // mail.draw(MNH_GRID_CELL_SIZE*2,MNH_GRID_CELL_SIZE*3);
            sceneName = "Fourth Sub Scene!";
            
            break;

    }
    ofDisableAlphaBlending();
}


//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void activityScene::touchDown(ofTouchEventArgs &touch){
    if (mgr.getCurScene() < 2) {
        
        next.touchDown(touch);
        
    }else if (mgr.getCurScene() == 2) {
        
        levelupB.touchDown(touch);
        startoverB.touchDown(touch);
        
    }else if (mgr.getCurScene() == 3) {
        
        startoverB.touchDown(touch);
       // mail.touchDown(touch);
    }
 
    
}


//--------------------------------------------------------------
void activityScene::touchMoved(ofTouchEventArgs &touch){
}


//--------------------------------------------------------------
void activityScene::touchUp(ofTouchEventArgs &touch){
    //Switch Scenes
    
    switch(mgr.getCurScene()) {
        case MNH_ACTIVITY_SCENE_FIRST:
            if (next.isPressed()) {
                mgr.setCurScene(1);
            }
            cout<<"we are in screen 0"<<endl;
            
            break;
        case MNH_ACTIVITY_SCENE_SECOND:
            if (next.isPressed()) {
                mgr.setCurScene(2);
            }
            
            break;
        case MNH_ACTIVITY_SCENE_THIRD:
            if (levelupB.isPressed()) {
                mgr.setCurScene(3);
            }
            
            if (startoverB.isPressed()) {
                mgr.setCurScene(0);
            }
                        
            break;
        case MNH_ACTIVITY_SCENE_FOURTH:
            if (startoverB.isPressed()) {
                mgr.setCurScene(0);
            }else if (mail.isPressed()){
                //mail box jump
                
                ofSetColor(255,0,0);
                ofRectangle(100,100,100,100);
            }
            
            break;
            
    }//switch
}
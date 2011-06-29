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
    //set up for first activity subscene
        activity1.loadImage("images/screens/activity1.png");
    
        //set up for activity1 button
        act1B1Img.loadImage("images/screens/activity/ori1.png");
        act1B2Img.loadImage("images/screens/activity/ori2.png");
        act1B3Img.loadImage("images/screens/activity/ori3.png");
        
        act1B1PreImg.loadImage("images/screens/activity/press1.png");
        act1B2PreImg.loadImage("images/screens/activity/press2.png");
        act1B3PreImg.loadImage("images/screens/activity/press3.png");
        
        
        act1B1.setImage(&act1B1Img,&act1B1PreImg);
        act1B2.setImage(&act1B2Img,&act1B2PreImg);
        act1B3.setImage(&act1B3Img,&act1B3PreImg);
        
        // three answer pages
        act1c1Img.loadImage("images/screens/activity/correct.png");;
        act1w1Img.loadImage("images/screens/activity/wrong1.png");;
        act1w2Img.loadImage("images/screens/activity/wrong2.png");;

        
    //set up for second activity subscene   
        activity2.loadImage("images/screens/activity2.png");
    
    
    
    //set up for third activity subscene 
        activity3.loadImage("images/screens/activity3.png");
    
    
    //set up for level up page
        levelup.loadImage("images/screens/levelup.png");
        
        //level up button
        levelupB.setSize(100, 50);
        levelupB.setPos(ofGetWidth()/2 - levelupB.rect.width/2,ofGetHeight()-levelupB.rect.height);
        levelupB.setLabel("Level Up!", &mnhAssets->whitneySemiBold22);
        //mail button for levelup page
        mail.setSize(100, 50);
        mail.setPos(mail.rect.width/2,mail.rect.height);
        mail.setLabel("Mail", &mnhAssets->whitneySemiBold22);

    //set up for all scene
        //start over button
        startoverB.setSize(100, 50);
        startoverB.setPos(startoverB.rect.width/2,startoverB.rect.height);
        startoverB.setLabel("Back to Activity!", &mnhAssets->whitneySemiBold22);
        
        next.setSize(100, 50);
        next.setPos(next.rect.width/2,next.rect.height);
        next.setLabel("Next", &mnhAssets->whitneySemiBold22);
        
           
        //backtoresearch button for activity page
        backtoresourceB.setSize(100, 50);
        backtoresourceB.setPos(mail.rect.width/2,mail.rect.height);
        backtoresourceB.setLabel("Back to Resources", &mnhAssets->whitneySemiBold22);

    
       
    
    from_act = false;
    location = 0;
    
    

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
        //first activity    
        case MNH_ACTIVITY_SCENE_FIRST:
            activity1.draw(0,0);
            
            act1B1.draw(ofGetWidth()/6-act1B1.rect.width/2,MNH_GRID_CELL_SIZE*3.5);
            act1B2.draw(ofGetWidth()/6*3-act1B2.rect.width/2,MNH_GRID_CELL_SIZE*3.5);
            act1B3.draw(ofGetWidth()/6*5-act1B3.rect.width/2,MNH_GRID_CELL_SIZE*3.5);
                       
                       
            break;
        case MNH_ACTIVITY_SCENE_SECOND:
            activity2.draw(0,0);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-50-next.rect.height);

            sceneName = "Second Sub Scene!";
            
            break;
        case MNH_ACTIVITY_SCENE_THIRD:
            activity3.draw(0,0);
//            startoverB.draw(ofGetWidth()-startoverB.rect.width,ofGetHeight()-50-startoverB.rect.height);
            levelupB.draw(ofGetWidth()-levelupB.rect.width,ofGetHeight()-50-levelupB.rect.height-startoverB.rect.height-20);
            sceneName = "Third Sub Scene!";
            
            break;
        case MNH_ACTIVITY_SCENE_FOURTH:
            levelup.draw(0,0);
            startoverB.draw(0,ofGetHeight()-50-startoverB.rect.height);
           // mail.draw(MNH_GRID_CELL_SIZE*2,MNH_GRID_CELL_SIZE*3);
            sceneName = "Fourth Sub Scene!";
            
            break;
        //correct answer for activity1
        case MNH_ACTIVITY_SCENE_FIVE:
            act1c1Img.draw(0,0);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-50-next.rect.height);
            
            break;
        //wrong answer    
        case MNH_ACTIVITY_SCENE_SIX:
            act1w1Img.draw(0,0);
            sceneName = "Fourth Sub Scene!";
            
            break;
        //wrong answer    
        case MNH_ACTIVITY_SCENE_SEVEN:
            act1w2Img.draw(0,0);
            startoverB.draw(0,ofGetHeight()-50-startoverB.rect.height);
            // mail.draw(MNH_GRID_CELL_SIZE*2,MNH_GRID_CELL_SIZE*3);
            sceneName = "Fourth Sub Scene!";
            
            break;

    }
    backtoresourceB.draw(ofGetWidth()-backtoresourceB.rect.width,0);
    ofDisableAlphaBlending();
}


//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void activityScene::touchDown(ofTouchEventArgs &touch){
    
    backtoresourceB.touchDown(touch);
    switch(mgr.getCurScene()) {
        case MNH_ACTIVITY_SCENE_FIRST:
            act1B1.touchDown(touch);
            act1B2.touchDown(touch);
            act1B3.touchDown(touch);

            backtoresourceB.touchDown(touch);
            break;
        case MNH_ACTIVITY_SCENE_SECOND:
            next.touchDown(touch);
            
            break;
        case MNH_ACTIVITY_SCENE_THIRD:
            levelupB.touchDown(touch);   
//            startoverB.touchDown(touch);

            
            break;
        case MNH_ACTIVITY_SCENE_FOURTH:
             startoverB.touchDown(touch);
            
            break;
        case MNH_ACTIVITY_SCENE_FIVE:
            next.touchDown(touch);
            
            break;
            
    }//switch
   
        
}


//--------------------------------------------------------------
void activityScene::touchMoved(ofTouchEventArgs &touch){
}


//--------------------------------------------------------------
void activityScene::touchUp(ofTouchEventArgs &touch){
    
    
    if (backtoresourceB.isPressed()) {
        
        location = mgr.getCurScene();
        cout<< "we are at "<<location<<endl;;
        mnhSM->setCurScene(MNH_SCENE_RESEARCH);
        from_act = TRUE;
        
    }

    
    
    switch(mgr.getCurScene()) {
        case MNH_ACTIVITY_SCENE_FIRST:
            if (next.isPressed()) {
                mgr.setCurScene(1);
            }else if (act1B1.isPressed()) {
                //correct
                mgr.setCurScene(4);
                act1B1.isPressed(false);
            }
            else if (act1B2.isPressed()) {
                //wrong
                mgr.setCurScene(0);
                
            }else if (act1B3.isPressed()) {
                //wrong
                mgr.setCurScene(0);
            }
            
            
                       
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
            
//            if (startoverB.isPressed()) {
//                mgr.setCurScene(0);
//            }
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
        case MNH_ACTIVITY_SCENE_FIVE:
            if (next.isPressed()) {
                mgr.setCurScene(1);
            } 
            
            break;
    
    }//switch
}
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
    location = 0;
    reset = 0;
    
    //back button
    backImg_off.loadImage("images/screens/activity/back_off.png");
    backImg_on.loadImage("images/screens/activity/back_on.png");
    back.setImage(&backImg_off,&backImg_on);
 
    
    //next button
    nextImg_off.loadImage("images/screens/activity/next_off.png");
    nextImg_on.loadImage("images/screens/activity/next_on.png");
    next.setImage(&nextImg_off,&nextImg_on);
    
    //back to resource button
    back_to_resource.setSize(100, 50);
    back_to_resource.setPos(ofGetWidth()-back_to_resource.rect.width,0);
    back_to_resource.setLabel("Back to Resources", &mnhAssets->whitneySemiBold22);
    
   
    
    
    //set up for first activity subscene
    ac1.loadImage("images/screens/activity1.png");
    ac1c1.loadImage("images/screens/ac1c1.png");
    ac1w1.loadImage("images/screens/ac1w1.png");
    ac1w2.loadImage("images/screens/ac1w2.png");
    
    ac1b1_off.loadImage("images/screens/activity/ac1b1_off.png");
    ac1b1_on.loadImage("images/screens/activity/ac1b1_on.png");
    ac1b1.setImage(&ac1b1_off,&ac1b1_on);
    
    ac1b2_off.loadImage("images/screens/activity/ac1b2_off.png");
    ac1b2_on.loadImage("images/screens/activity/ac1b2_on.png");
    ac1b2.setImage(&ac1b2_off,&ac1b2_on);

    ac1b3_off.loadImage("images/screens/activity/ac1b3_off.png");
    ac1b3_on.loadImage("images/screens/activity/ac1b3_on.png");
    ac1b3.setImage(&ac1b3_off,&ac1b3_on);

    
    //set up for second activity subscene
    ac2.loadImage("images/screens/activity2.png");
    ac2c1.loadImage("images/screens/ac2c1.png");
    ac2w1.loadImage("images/screens/ac2w1.png");
    ac2w2.loadImage("images/screens/ac2w2.png");
    
    ac2b1_off.loadImage("images/screens/activity/ac2b1_off.png");
    ac2b1_on.loadImage("images/screens/activity/ac2b1_on.png");
    ac2b1.setImage(&ac2b1_off,&ac2b1_on);
    
    ac2b2_off.loadImage("images/screens/activity/ac2b2_off.png");
    ac2b2_on.loadImage("images/screens/activity/ac2b2_on.png");
    ac2b2.setImage(&ac2b2_off,&ac2b2_on);
    
    ac2b3_off.loadImage("images/screens/activity/ac2b3_off.png");
    ac2b3_on.loadImage("images/screens/activity/ac2b3_on.png");
    ac2b3.setImage(&ac2b3_off,&ac2b3_on);

    //set up for third acctivity subscene
    ac3.loadImage("images/screens/activity3.png");
    ac3c1.loadImage("images/screens/ac3c1.png");
    ac3w1.loadImage("images/screens/ac3w1.png");

    ac3b1_off.loadImage("images/screens/activity/ac3b1_off.png");
    ac3b1_on.loadImage("images/screens/activity/ac3b1_on.png");
    ac3b1.setImage(&ac3b1_off,&ac3b1_on);
    
    ac3b2_off.loadImage("images/screens/activity/ac3b2_off.png");
    ac3b2_on.loadImage("images/screens/activity/ac3b2_on.png");
    ac3b2.setImage(&ac3b2_off,&ac3b2_on);

    //summary page
    summary.loadImage("images/screens/summary.png");
    levelupBImg.loadImage("images/screens/activity/levelupb.png");
    levelupB.setImage(&levelupBImg,&levelupBImg);
   // levelupB.setSize(MNH_GRID_CELL_SIZE*2, MNH_GRID_CELL_SIZE*1);
    
    //level up page 
    levelup.loadImage("images/screens/levelup.png");
    
    startoverImg.loadImage("images/screens/activity/startover.png");
    startover.setImage(&startoverImg,&startoverImg);
    
    inviteImg.loadImage("images/screens/activity/invite.png");
    invite.setImage(&inviteImg,&inviteImg);
    
    theMail.setup();

}



//------------------------------------------------------------------
void activityScene::update() {
//    cout<<"bPressed"<<back_to_resource.bPressed<<endl;

    if(mgr.getCurSceneChanged())
    {
        
        switch(mgr.getCurScene()) {
                //first activity    
            case MNH_ACTIVITY_SCENE_AC1:
                ac1b1.touchReset();
                ac1b2.touchReset();
                ac1b3.touchReset();
                break;
/*
            case MNH_ACTIVITY_SCENE_AC1C1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
            case MNH_ACTIVITY_SCENE_AC1W1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
            case MNH_ACTIVITY_SCENE_AC1W2:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
                //second activity
 */
            case MNH_ACTIVITY_SCENE_AC2:
                ac2b1.touchReset();
                ac2b2.touchReset();
                ac2b3.touchReset();
                break;
/*
            case MNH_ACTIVITY_SCENE_AC2C1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
            case MNH_ACTIVITY_SCENE_AC2W1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
                
            case MNH_ACTIVITY_SCENE_AC2W2:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
 */               
                //third activity    
            case MNH_ACTIVITY_SCENE_AC3:
                ac3b1.touchReset();
                ac3b2.touchReset();
                break;
                
 /*           case MNH_ACTIVITY_SCENE_AC3C1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                
            case MNH_ACTIVITY_SCENE_AC3W1:
                back.touchDown(touch);
                next.touchDown(touch);
                break;
                //level up
                
            case MNH_ACTIVITY_SCENE_SUM:
                
                break;
                
            case MNH_ACTIVITY_SCENE_LEVELUP:
                
                break;
*/
    
        }
    }
    switch (theMail.getResult()) {
        case 0:
            break;
        case 1:
            printf("saved\n");
            break;
        case 2:
            printf("sent\n");
            break;
        case -1:
            printf("canceled\n");
            break;
        case -2:
            printf("failed\n");
            break;
        default:
            break;
    }

    
    
}
//------------------------------------------------------------------
void activityScene::activate() {
    cout<< "rest in activate"<<reset<<endl;
    cout<< "location in activate"<<location<<endl;
    if(reset)
    {
    
        mgr.setCurScene(location);
       
        
    }else{
        mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1);
         
    }
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
        case MNH_ACTIVITY_SCENE_AC1:
            ac1.draw(0,0);
            back_to_resource.draw(ofGetWidth()-back_to_resource.rect.width,0);

            ac1b1.draw(ofGetWidth()/6-ac1b1.rect.width/2,ofGetHeight()-back.rect.height+25);
            ac1b2.draw(ofGetWidth()/6*3-ac1b2.rect.width/2,ofGetHeight()-back.rect.height+25);
            ac1b3.draw(ofGetWidth()/6*5-ac1b3.rect.width/2,ofGetHeight()-back.rect.height+25);
            
            break;
        case MNH_ACTIVITY_SCENE_AC1C1:
            ac1.draw(0,0);
            ac1c1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);
            back.draw(0,ofGetHeight()-back.rect.height);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-next.rect.height);
            break;
        case MNH_ACTIVITY_SCENE_AC1W1:
            ac1.draw(0,0);
            ac1w1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);
            back.draw(0,ofGetHeight()-back.rect.height);

            
            break;
        case MNH_ACTIVITY_SCENE_AC1W2:
            ac1.draw(0,0);
            ac1w2.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);
            back.draw(0,ofGetHeight()-back.rect.height);

            
            break;
        //second activity
        case MNH_ACTIVITY_SCENE_AC2:
            ac2.draw(0,0);
            back_to_resource.draw(ofGetWidth()-back_to_resource.rect.width,0);

            ac2b1.draw(ofGetWidth()/6-ac2b1.rect.width/2,ofGetHeight()-back.rect.height+25);
            ac2b2.draw(ofGetWidth()/6*3-ac2b2.rect.width/2,ofGetHeight()-back.rect.height+25);
            ac2b3.draw(ofGetWidth()/6*5-ac2b3.rect.width/2,ofGetHeight()-back.rect.height+25);
            
            break;
        case MNH_ACTIVITY_SCENE_AC2C1:
            ac2.draw(0,0);
            ac2c1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);

            back.draw(0,ofGetHeight()-back.rect.height);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-next.rect.height);

            break;
            
        case MNH_ACTIVITY_SCENE_AC2W1:
            ac2.draw(0,0);
            ac2w1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);

            back.draw(0,ofGetHeight()-back.rect.height);
            
            break;

            
        case MNH_ACTIVITY_SCENE_AC2W2:
            ac2.draw(0,0);
            ac2w2.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);

            back.draw(0,ofGetHeight()-back.rect.height);
           
            break;
            
        //third activity    
        case MNH_ACTIVITY_SCENE_AC3:
            ac3.draw(0,0);
            ac3b1.draw(ofGetWidth()/6-ac3b1.rect.width/2,ofGetHeight()-back.rect.height+25);
            ac3b2.draw(ofGetWidth()/6*3-ac3b2.rect.width/2,ofGetHeight()-back.rect.height+25);
            back_to_resource.draw(ofGetWidth()-back_to_resource.rect.width,0);

            break;
            
        case MNH_ACTIVITY_SCENE_AC3C1:
            ac3.draw(0,0);
            ac3c1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);
            back.draw(0,ofGetHeight()-back.rect.height);
            next.draw(ofGetWidth()-next.rect.width,ofGetHeight()-next.rect.height);

            break;
            
        case MNH_ACTIVITY_SCENE_AC3W1:
            ac3.draw(0,0);
            ac3w1.draw(back.rect.width*2,ofGetHeight()-back.rect.height+25);
            back.draw(0,ofGetHeight()-back.rect.height);
        
            break;
        //level up
            
        case MNH_ACTIVITY_SCENE_SUM:
            summary.draw(0,0);
            levelupB.draw(ofGetWidth()-levelupB.rect.width,ofGetHeight()-levelupB.rect.height-55);
            
            break;
            
        case MNH_ACTIVITY_SCENE_LEVELUP:
            levelup.draw(0,0);
            startover.draw(ofGetWidth()/2+startover.rect.width/2+10,MNH_GRID_CELL_SIZE*2.5);
           invite.draw(MNH_GRID_CELL_SIZE,MNH_GRID_CELL_SIZE*2.5);

            break;
    }
    
  
    
    
    ofDisableAlphaBlending();
}


//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void activityScene::touchDown(ofTouchEventArgs &touch){
   
    
    switch(mgr.getCurScene()) {
            //first activity    
        case MNH_ACTIVITY_SCENE_AC1:
            ac1b1.touchDown(touch);
            ac1b2.touchDown(touch);
            ac1b3.touchDown(touch);
            back_to_resource.touchDown(touch);


            break;
        case MNH_ACTIVITY_SCENE_AC1C1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
        case MNH_ACTIVITY_SCENE_AC1W1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
        case MNH_ACTIVITY_SCENE_AC1W2:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
            //second activity
        case MNH_ACTIVITY_SCENE_AC2:
            ac2b1.touchDown(touch);
            ac2b2.touchDown(touch);
            ac2b3.touchDown(touch);
            back_to_resource.touchDown(touch);


            break;
        case MNH_ACTIVITY_SCENE_AC2C1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
        case MNH_ACTIVITY_SCENE_AC2W1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
            
        case MNH_ACTIVITY_SCENE_AC2W2:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
            //third activity    
        case MNH_ACTIVITY_SCENE_AC3:
            ac3b1.touchDown(touch);
            ac3b2.touchDown(touch);
            back_to_resource.touchDown(touch);

            break;
            
        case MNH_ACTIVITY_SCENE_AC3C1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            
        case MNH_ACTIVITY_SCENE_AC3W1:
            back.touchDown(touch);
            next.touchDown(touch);
            break;
            //level up
            
        case MNH_ACTIVITY_SCENE_SUM:
            levelupB.touchDown(touch);
            break;
            
        case MNH_ACTIVITY_SCENE_LEVELUP:
            startover.touchDown(touch);
            invite.touchDown(touch);
            

            
            break;
    }

       
        
}


//--------------------------------------------------------------
void activityScene::touchMoved(ofTouchEventArgs &touch){
}


//--------------------------------------------------------------
void activityScene::touchUp(ofTouchEventArgs &touch){

    switch(mgr.getCurScene()) {
            //first activity    
        case MNH_ACTIVITY_SCENE_AC1:
            if (ac1b1.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1W1);
            }else if(ac1b2.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1C1);
            }else if(ac1b3.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1W2);

            }else if(back_to_resource.isPressed()){
                location = mgr.getCurScene();
                reset = true;

                mnhSM->setCurScene(MNH_SCENE_RESEARCH);

            }


            break;
        case MNH_ACTIVITY_SCENE_AC1C1:
//            cout<<"AC1C1"<<back.bPressed<<endl;
           
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1);
            }else if(next.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
            }
            
            break;
        case MNH_ACTIVITY_SCENE_AC1W1:
//            cout<<"AC1W1";

            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1);
            }
//            else{
//                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
//            }

            break;
        case MNH_ACTIVITY_SCENE_AC1W2:
//            cout<<"AC1W2";

            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC1);
            }
//            else{
//                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
//            }

            break;
            
            
            
            
            //second activity
        case MNH_ACTIVITY_SCENE_AC2:
            if (ac2b1.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2C1);
            }else if(ac2b2.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2W1);
            }else if(ac2b3.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2W2);
                
            }else if(back_to_resource.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_RESEARCH);
                location = mgr.getCurScene();
                reset = TRUE;
                cout<< location;
            }


            break;
        case MNH_ACTIVITY_SCENE_AC2C1:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
            }else if(next.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3);
            }

            break;
            
        case MNH_ACTIVITY_SCENE_AC2W1:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
            }
//            else{
//                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3);
//            }

            break;
            
            
        case MNH_ACTIVITY_SCENE_AC2W2:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC2);
            }
//            else{
//                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3);
//            }

            break;
            
            //third activity    
        case MNH_ACTIVITY_SCENE_AC3:
            if (ac3b1.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3W1);
            }else if(ac3b2.isPressed()){
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3C1);
            }else if(back_to_resource.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_RESEARCH);
                location = mgr.getCurScene();
                reset = 1;
                cout<< location;
            }
            break;
            
        case MNH_ACTIVITY_SCENE_AC3C1:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3);
            }else{
                mgr.setCurScene(MNH_ACTIVITY_SCENE_SUM);
            }

            break;
            
        case MNH_ACTIVITY_SCENE_AC3W1:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_AC3);
            } break;
            //level up
            
        case MNH_ACTIVITY_SCENE_SUM:
            if (levelupB.isPressed()) {
                mgr.setCurScene(MNH_ACTIVITY_SCENE_LEVELUP);
            }
            break;
            
        case MNH_ACTIVITY_SCENE_LEVELUP:
            if (startover.isPressed()) {
                mnhSM->setCurScene(MNH_SCENE_HOME);
                reset = 0;
            }else if(invite.isPressed()){
             
                theMail.show();
            
            }

            break;
    }
    back_to_resource.touchUp(touch);    
    back.touchUp(touch);
    next.touchUp(touch);
   
    
    

}

bool activityScene::notice(){

    return reset;
}
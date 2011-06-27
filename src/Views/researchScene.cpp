//
//  researchScene.cpp
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "researchScene.h"

//------------------------------------------------------------------
void researchScene::setup() {
    //set up for main scene
    researchScreen.loadImage("images/screens/research.png");
    
    //set up for subscene
    caseP.loadImage("images/screens/case.png");
    infoP.loadImage("images/screens/info.png");
    hintP.loadImage("images/screens/hint.png");
    
    threeD.loadImage("images/screens/3D.png");

    
    //set up for buttons
    caseI.loadImage("images/screens/research/case.png");
    infoI.loadImage("images/screens/research/info.png");
    hintI.loadImage("images/screens/research/hint.png");
    
    caseB.setImage(&caseI,&caseI);
    infoB.setImage(&infoI,&infoI);
    hintB.setImage(&hintI,&hintI);
    
    caseB.setPos(ofGetWidth()/6-caseB.rect.width/2,450);
    infoB.setPos(ofGetWidth()/6*3-infoB.rect.width/2,450);
    hintB.setPos(ofGetWidth()/6*5-hintB.rect.width/2,450);

    //set up for t buttons
    anteI.loadImage("images/screens/bone/ante.png");
    periI.loadImage("images/screens/bone/peri.png");
    postI.loadImage("images/screens/bone/post.png");
    
    anteB.setImage(&anteI,&anteI);
    periB.setImage(&periI,&periI);
    postB.setImage(&postI,&postI);
    
    anteB.setPos(ofGetWidth()/6-anteB.rect.width/2,450);
    periB.setPos(ofGetWidth()/6*3-periB.rect.width/2,450);
    postB.setPos(ofGetWidth()/6*5-postB.rect.width/2,450);

    
    
    //back to research button
    back.setSize(100, 50);
    back.setPos(ofGetWidth()/2 - back.rect.width/2,ofGetHeight()-back.rect.height);
    back.setLabel("Back to Research!", &mnhAssets->whitneySemiBold22);
    //back to info
    backtoinfo.setSize(100, 50);
    backtoinfo.setPos(ofGetWidth()/2 - back.rect.width/2,ofGetHeight()-back.rect.height);
    backtoinfo.setLabel("Back to Find the Trauma!", &mnhAssets->whitneySemiBold22);

    //start activity button
    start.setSize(100, 50);
    start.setPos(back.rect.width/2,back.rect.height);
    start.setLabel("Start Activity!", &mnhAssets->whitneySemiBold22);
    
    
    

}



//------------------------------------------------------------------
void researchScene::update() {
    //Check if scene has been updated
//    if(mgr.getCurSceneChanged()) {
//        switch(mgr.getCurScene()) {
//            case MNH_RESEARCH_SCENE_FIRST:
//                cout << "Doing Setup Stuff for Scene One!" << endl;
//                break;
//            case MNH_RESEARCH_SCENE_SECOND:
//                cout << "Doing Setup Stuff for Scene Two!" << endl;
//                break;
//            case MNH_RESEARCH_SCENE_THIRD:
//                cout << "Doing Setup Stuff for Scene Three!" << endl;
//                break;
//        }
//    }
    
     
}

//------------------------------------------------------------------
void researchScene::activate() {
    
    mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
    
    cout << "Activate Research" << endl;
}

//------------------------------------------------------------------
void researchScene::deactivate() {
    cout << "Deactivate Research" << endl;
}


//------------------------------------------------------------------
void researchScene::draw() {
    
    ofEnableAlphaBlending();
    drawGrid();    
       
    string sceneName = "";
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            researchScreen.draw(0,0);
            caseB.draw();
            infoB.draw();
            hintB.draw();

            sceneName = "First Sub Scene!";
            break;
            
        case MNH_RESEARCH_SCENE_SECOND:
            caseP.draw(0,0);
            back.draw(0,ofGetHeight()-back.rect.height-50);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
            sceneName = "Second Sub Scene!";
            break;
        case MNH_RESEARCH_SCENE_THIRD:
            infoP.draw(0,0);
            
            anteB.draw();
            periB.draw();
            postB.draw();
            
            back.draw(0,ofGetHeight()-back.rect.height-50);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
            sceneName = "Third Sub Scene!";
            break;
            
        case MNH_RESEARCH_SCENE_FOURTH:
            hintP.draw(0,0);
            back.draw(0,ofGetHeight()-back.rect.height-50);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
            sceneName = "Third Sub Scene!";
            break;
        case MNH_RESEARCH_SCENE_FIFTH:
            threeD.draw(0,0);
            backtoinfo.draw(0,ofGetHeight()-backtoinfo.rect.height-50);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
            sceneName = "Third Sub Scene!";
            break;
    }
    ofDisableAlphaBlending();
}



//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void researchScene::touchDown(ofTouchEventArgs &touch){
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            caseB.touchDown(touch);
            infoB.touchDown(touch);
            hintB.touchDown(touch);
            break;
            
        case MNH_RESEARCH_SCENE_SECOND:
            back.touchDown(touch);
            start.touchDown(touch);
            break;
        case MNH_RESEARCH_SCENE_THIRD:
            anteB.touchDown(touch);
            periB.touchDown(touch);
            postB.touchDown(touch);
            back.touchDown(touch);
            start.touchDown(touch);
            break;
            
        case MNH_RESEARCH_SCENE_FOURTH:
            back.touchDown(touch);
            start.touchDown(touch);
            break;
        case MNH_RESEARCH_SCENE_FIFTH:
            backtoinfo.touchDown(touch);
            start.touchDown(touch);

            break;
    }
 //    //active the buttons only for the first scene
//    if(mgr.getCurScene() == 0) 
//    {
//        caseB.touchDown(touch);
//        infoB.touchDown(touch);
//        hintB.touchDown(touch);
//    }
//    if(mgr.getCurScene() == 2) 
//    {
//        anteB.touchDown(touch);
//        periB.touchDown(touch);
//        postB.touchDown(touch);
//    }
//    back.touchDown(touch);
//    start.touchDown(touch);
}


//--------------------------------------------------------------
void researchScene::touchMoved(ofTouchEventArgs &touch){

    caseB.touchMoved(touch);
    infoB.touchMoved(touch);
    hintB.touchMoved(touch); 
    back.touchMoved(touch);
    backtoinfo.touchMoved(touch);
    start.touchDown(touch);


}


//--------------------------------------------------------------
void researchScene::touchUp(ofTouchEventArgs &touch){
    
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            if (caseB.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_SECOND);
            }else if(infoB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
                
            }else if(hintB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_FOURTH);
            }

            break;
            
        case MNH_RESEARCH_SCENE_SECOND:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
            }else if(start.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
            break;
        case MNH_RESEARCH_SCENE_THIRD:
            if (anteB.isPressed())
            {
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIFTH);
                cout<<"anteB";
            }else if (periB.isPressed())
            {
                cout<<"periB";
            }else if(postB.isPressed())
            {
                cout<<"postB";
            }
            if (back.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
            }else if(start.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
            break;
            
        case MNH_RESEARCH_SCENE_FOURTH:
            if (back.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
            }else if(start.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
            break;
        case MNH_RESEARCH_SCENE_FIFTH:
            if (backtoinfo.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
            }else if(start.isPressed()){
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
            
            break;
    }

    
    
    
    
    
    
    
    
    
//    
//    
//    
//    
//    
//    
//    
//    if (back.isPressed()) {
//        mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
//    }else if(start.isPressed()){
//        mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
//        
//        cout<<"start is pressed"<<endl;
//        
//    // for the research subscenes    
//    }else if (caseB.isPressed()) {
//        mgr.setCurScene(MNH_RESEARCH_SCENE_SECOND);
//    }else if(infoB.isPressed()){
//        mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
//
//    }else if(hintB.isPressed()){
//        mgr.setCurScene(MNH_RESEARCH_SCENE_FOURTH);
//    }
//    
//    
//    // for the info subscenes
//    if(mgr.getCurScene() == 2) 
//    {
//        if (anteB.isPressed())
//        {
//            mgr.setCurScene(MNH_RESEARCH_SCENE_FIFTH);
//            cout<<"anteB";
//        }else if (periB.isPressed())
//        {
//            cout<<"periB";
//        }else if(postB.isPressed())
//        {
//            cout<<"postB";
//        }
//    }

}
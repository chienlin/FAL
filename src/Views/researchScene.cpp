//
//  researchScene.cpp
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "researchScene.h"

GLfloat lightOnePosition[] = {80.0, -1540, 100.0, 0.0};
GLfloat lightOneColor[] = {0.82, 0.88, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-80.0, 1540, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.74, 0.32, 1.0};

//------------------------------------------------------------------
void researchScene::setup() {
    //set up for main scene
    researchScreen.loadImage("images/screens/research.png");
    
    //set up for subscene
    caseP.loadImage("images/screens/case.png");
    infoP.loadImage("images/screens/info.png");
    hintP.loadImage("images/screens/hint.png");

    
    //set up for resource page buttons
    caseI.loadImage("images/screens/research/case.png");
    infoI.loadImage("images/screens/research/info.png");
    hintI.loadImage("images/screens/research/hint.png");
    
    caseB.setImage(&caseI,&caseI);
    infoB.setImage(&infoI,&infoI);
    hintB.setImage(&hintI,&hintI);
    
    caseB.setPos(ofGetWidth()/6-caseB.rect.width/2,MNH_GRID_CELL_SIZE*3);
    infoB.setPos(ofGetWidth()/6*3-infoB.rect.width/2,MNH_GRID_CELL_SIZE*3);
    hintB.setPos(ofGetWidth()/6*5-hintB.rect.width/2,MNH_GRID_CELL_SIZE*3);
    
    //set up for checked resource page buttons
    checkmark.loadImage("images/screens/research/checkmark.png");
    casechecked = false;  
    infochecked = false;
    hintchecked = false;
    
    

    //set up for 3D model buttons
    anteI.loadImage("images/screens/bone/ante.png");
    periI.loadImage("images/screens/bone/peri.png");
    postI.loadImage("images/screens/bone/post.png");
    
    anteB.setImage(&anteI,&anteI);
    periB.setImage(&periI,&periI);
    postB.setImage(&postI,&postI);
    
    anteB.setPos(ofGetWidth()/6-anteB.rect.width/2,MNH_GRID_CELL_SIZE*3);
    periB.setPos(ofGetWidth()/6*3-periB.rect.width/2,MNH_GRID_CELL_SIZE*3);
    postB.setPos(ofGetWidth()/6*5-postB.rect.width/2,MNH_GRID_CELL_SIZE*3);

    
    
    //back to research button
    back.setSize(100, 50);
    back.setPos(ofGetWidth()/2 - back.rect.width/2,ofGetHeight()-back.rect.height);
    back.setLabel("Back to Resources", &mnhAssets->whitneySemiBold22);
    
    //back to find trauma
    backtoinfo.setSize(100, 50);
    backtoinfo.setPos(ofGetWidth()/2 - back.rect.width/2,ofGetHeight()-back.rect.height);
    backtoinfo.setLabel("Back to Find the Trauma", &mnhAssets->whitneySemiBold22);

    //start activity button
    start.setSize(100, 50);
    start.setPos(back.rect.width/2,back.rect.height);
    start.setLabel("Start Activity", &mnhAssets->whitneySemiBold22);
    
    //back to continue activity
    backtoact.setSize(100, 50);
    backtoact.setPos(backtoact.rect.width/2,backtoact.rect.height);
    backtoact.setLabel("back to Activity", &mnhAssets->whitneySemiBold22);

    location_at_act = 0;
    
    
    //double tap
    firstDoubleTap = false;
    isTouchDown = false;
    touchX = 0;
    touchY = 0;
    dTouchX = 0;
    dTouchY = 0;
    bTouchMove = false;
    orbitSpeed = .2;
    
    //set origin position vector for model
    
}



//------------------------------------------------------------------
void researchScene::update() {

}

//------------------------------------------------------------------
void researchScene::activate() {
    init3DViewer(t);
    mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
//    init3DViewer(t);
    cout << "Activate Research" << endl;
}

//------------------------------------------------------------------
void researchScene::deactivate() {
    cout << "Deactivate Research" << endl;
    delete boneModel;
    boneModel = NULL;
}


//------------------------------------------------------------------
void researchScene::draw() {
    
   
    ofEnableAlphaBlending();
    drawGrid();    
       
    string sceneName = "";
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            researchScreen.draw(0,0);
            // for showing this page are already checked
            if (casechecked) {
                checkmark.draw(ofGetWidth()/6-caseB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
            }
            if (infochecked) {
                checkmark.draw(ofGetWidth()/6*3-infoB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
            }
            if (hintchecked) {
                cout<<"hi"<<endl;
                checkmark.draw(ofGetWidth()/6*5-hintB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
            }
            //
            
            caseB.draw();
            infoB.draw();
            hintB.draw();

            sceneName = "Resource page!";
            break;
            
        case MNH_RESEARCH_SCENE_SECOND:
            caseP.draw(0,0);
            back.draw(ofGetWidth()-back.rect.width,0);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
//            backtoact.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);

            sceneName = "Case info page!";
            break;
        case MNH_RESEARCH_SCENE_THIRD:
            infoP.draw(0,0);
            
            anteB.draw();
            periB.draw();
            postB.draw();
            
            back.draw(ofGetWidth()-back.rect.width,0);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
//            backtoact.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);

            sceneName = "Find the trauma";
            break;
            
        case MNH_RESEARCH_SCENE_FOURTH:
            hintP.draw(0,0);
            back.draw(ofGetWidth()-back.rect.width,0);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
//            backtoact.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);

            sceneName = "Hint";
            break;
        case MNH_RESEARCH_SCENE_FIFTH:
            
            backtoinfo.draw(ofGetWidth()-backtoinfo.rect.width,0);
            
            sceneName = "3D!";
            
            drawModel();
                        
            break;
    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void researchScene::init3DViewer(traumaType trauma){
    modelXPos = 720;
    modelYPos = 395;
    
    //set gl settings
    //glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    
    //init lighting
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    
    //load model
    string boneFileName;
    switch (trauma) {
        case MNH_FAL_ANTEMORTEM:
            boneFileName = "3dmodels/Skull_321498_aka_843-reduced10k-annontated.3ds";
            break;
        case MNH_FAL_PERIMORTEM:
            boneFileName = "3dmodels/Cranium_209434-reduced10k.3ds";
            break;
        default:
            break;
    }
    cout << "Loading 3D Model Viewer" << endl;
    boneModel = new ofx3DModelLoader();
    boneModel->loadModel(boneFileName, 3);
    model3DS* model = (model3DS*)boneModel->model;
    
    //set model to right-side-up
    boneModel->setRotation(0, 180.0, 0, 0, 1);
    //set initial scale
    boneModel->setScale(0.75, 0.75, 0.75);
    //set initial pos
    boneModel->setPosition(modelXPos, modelYPos, 0);
}

//--------------------------------------------------------------
void researchScene::drawModel(){
    glPushMatrix();
        glEnable (GL_LIGHTING);
        //draw in middle of the screen
        glTranslatef(modelXPos,modelYPos,0);
        //tumble according to mouse
        //glRotatef(-touchY/2,1,0,0);
        //glRotatef(touchX/2,0,1,0);
        if (isTouchDown) {
            currentModelRotationY += ofMap(touchY, 0, 768, 0, 360);
            currentModelRotationX += ofMap(touchX, 0, 1024, 0, 360);
        }
        
        if (currentModelRotationX > 360) {
            currentModelRotationX -= 360;    
        }
            
        
        if (currentModelRotationY > 360)
            currentModelRotationY -= 360;
        
        cout << "model rotation: " << currentModelRotationX << " , " << currentModelRotationY << endl;
        boneModel->setRotation(1, -currentModelRotationY, 1, 0, 0);
                
        boneModel->setRotation(2, currentModelRotationX, 0, 1, 0); 
        glTranslatef(-modelXPos,-modelYPos,0);
        
        ofSetColor(254, 254, 254, 255);
        boneModel->draw();
        glDisable(GL_LIGHTING);
    glPopMatrix();
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
            backtoact.touchDown(touch);
            break;
        case MNH_RESEARCH_SCENE_THIRD:
            anteB.touchDown(touch);
            periB.touchDown(touch);
            postB.touchDown(touch);
            back.touchDown(touch);
            start.touchDown(touch);
            backtoact.touchDown(touch);

            break;
            
        case MNH_RESEARCH_SCENE_FOURTH:
            back.touchDown(touch);
            start.touchDown(touch);
            backtoact.touchDown(touch);

            break;
        case MNH_RESEARCH_SCENE_FIFTH:
            backtoinfo.touchDown(touch);
            start.touchDown(touch);

            break;
    }
    
    isTouchDown = true;
}


//--------------------------------------------------------------
void researchScene::touchMoved(ofTouchEventArgs &touch){

    caseB.touchMoved(touch);
    infoB.touchMoved(touch);
    hintB.touchMoved(touch); 
    back.touchMoved(touch);
    backtoinfo.touchMoved(touch);
    start.touchDown(touch);
    
    touchX = touch.x;
    touchY = touch.y;
}


//--------------------------------------------------------------
void researchScene::touchUp(ofTouchEventArgs &touch){

    isTouchDown = false;
       
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            if (caseB.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_SECOND);
                casechecked = true;
                
            }else if(infoB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
                infochecked = true;

                
            }else if(hintB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_FOURTH);
                hintchecked = true;
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
                t = MNH_FAL_ANTEMORTEM;
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIFTH);
                cout<<"anteB";
            }else if (periB.isPressed())
            {
                 t = MNH_FAL_PERIMORTEM;
                cout<<"periB";
            }else if(postB.isPressed())
            {
                t = MNH_FAL_POSTMORTEM;
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
}

//--------------------------------------------------------------
void researchScene::touchDoubleTap(ofTouchEventArgs &touch){
    if(!firstDoubleTap) {
        boneModel->setScale(1.0, 1.0, 1.0);
    }
    
    if(firstDoubleTap) {
        boneModel->setScale(0.75, 0.75, 0.75);
    }
    
    firstDoubleTap = !firstDoubleTap;
}

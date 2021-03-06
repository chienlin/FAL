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

GLfloat lightTwoPosition[] = {-80.0, 2540, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.74, 0.32, 1.0};

float epsilonTransform = 1e-7;


//------------------------------------------------------------------
void researchScene::setup() {
    //set up for main scene
    researchScreen.loadImage("images/screens/research.png");
    
    //set up for subscene
    caseP.loadImage("images/screens/case.png");
    infoP.loadImage("images/screens/info.png");
    hintP.loadImage("images/screens/hint.png");
    
    anteP.loadImage("images/screens/ante.png");
    periP.loadImage("images/screens/peri.png");
    postP.loadImage("images/screens/post.png");

    
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
//    checkmark.loadImage("images/screens/research/checkmark.png");
//    casechecked = false;  
//    infochecked = false;
//    hintchecked = false;
    
    

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
    backtoinfo.setLabel("Back to Time of Trauma", &mnhAssets->whitneySemiBold22);

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
    bFirstRun = false;
    bTouchMove = false;
    touchX = 0;
    touchY = 0;
    stopMomentum = 0.83;
    modelSpaceWidth = 544; //black sq from illustrator where model sits
    prevSpherePt.set(0,0,0);
    currSpherePt.set(0,0,0);
    sphereRadius = modelSpaceWidth/2;

    
    //3d swap
    //back to research button
    swap.setSize(100, 100);
    swap.setPos(1.5*MNH_GRID_CELL_SIZE,ofGetHeight()-50-swap.rect.height*2);
    swap.setLabel("Swap Models", &mnhAssets->whitneySemiBold22);
    a = false;
    
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
        case MNH_FAL_ANTEMORTEM1:
            boneFileName = "3dmodels/Skull_321498_aka_843-reduced10k-tex-annotated.3ds";
            bonescale = 3;
            break;
        case MNH_FAL_ANTEMORTEM2:
            boneFileName = "3dmodels/Femur_169_reduced20k_annotated.3ds";
            bonescale = 2.0;
            break;
        case MNH_FAL_PERIMORTEM1:
            boneFileName = "3dmodels/Cranium_209434-reduced10k_annotated.3ds";
             bonescale = 3;
            break;
        case MNH_FAL_PERIMORTEM2:
            boneFileName = "3dmodels/Femur_170R_Knee_Final_reduced25k_annotated.3ds";
            bonescale = 3.00;
            break;
        default:
            break;
    }

    cout << "Loading 3D Model Viewer" << endl;
    boneModel = new ofx3DModelLoader();
    boneModel->loadModel(boneFileName, bonescale);
    
    //set model to right-side-up
    boneModel->setRotation(0, 180.0, 0, 0, 1);
    //set initial scale
    boneModel->setScale(0.75, 0.75, 0.75);
    //set initial pos
    boneModel->setPosition(modelXPos, modelYPos, 0);
}



//------------------------------------------------------------------
void researchScene::update() {
     
    if (reset) {
        start.setLabel("Resume Activity", &mnhAssets->whitneySemiBold22);
    }
    
    theta *= stopMomentum;
    if(theta < epsilonTransform) theta = 0; // stop theta from becoming ridiculously small
    
/* 
    if (mgr.getCurSceneChanged()) {
        delete boneModel;
        boneModel = NULL;
    }
 */   
}

//------------------------------------------------------------------
void researchScene::activate() {
    mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
    cout << "Activate Research" << endl;
}

//------------------------------------------------------------------
void researchScene::deactivate() {
    cout << "Deactivate Research" << endl;
    delete boneModel;
    boneModel = NULL;
    bFirstRun = false;
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
//            if (casechecked) {
//                checkmark.draw(ofGetWidth()/6-caseB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
//            }
//            if (infochecked) {
//                checkmark.draw(ofGetWidth()/6*3-infoB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
//            }
//            if (hintchecked) {
//                cout<<"hi"<<endl;
//                checkmark.draw(ofGetWidth()/6*5-hintB.rect.width/2-checkmark.width/2,MNH_GRID_CELL_SIZE*3);
//            }
//            //
            
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
            anteP.draw(0,0);
            swap.draw();
            backtoinfo.draw(ofGetWidth()-backtoinfo.rect.width,0);
            sceneName = "3D for ante";
            drawModel();
                        
            break;
        case MNH_RESEARCH_SCENE_SIX:
            periP.draw(0,0);
            swap.draw();
            backtoinfo.draw(ofGetWidth()-backtoinfo.rect.width,0);
            sceneName = "3D for peri";
            drawModel();
            
            break;
        case MNH_RESEARCH_SCENE_SEVEN:
            postP.draw(0,0);
            backtoinfo.draw(ofGetWidth()-backtoinfo.rect.width,0);
            sceneName = "3D for post";
             
            break;

    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void researchScene::drawModel(){
    glPushMatrix();
        glEnable (GL_LIGHTING);
        
        if(!bFirstRun) {
            matrixCapture();
            bFirstRun = true;;
        }
    
        glLoadMatrixf(modelMatrix);
            
        //draw in middle of the screen
        glTranslatef(modelXPos,modelYPos,0);
        //rotate model acording to our arcball rotation
        glRotatef(-theta, axis.x, axis.y, axis.z);
        glTranslatef(-modelXPos,-modelYPos,0);
        
        //save maxtrix transform
        matrixCapture();
    
        ofSetColor(255, 254, 254, 255);
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
            swap.touchDown(touch);
            backtoinfo.touchDown(touch);
            start.touchDown(touch);

            break;
        case MNH_RESEARCH_SCENE_SIX:
            swap.touchDown(touch);
            backtoinfo.touchDown(touch);
            start.touchDown(touch);
            
            break;
        case MNH_RESEARCH_SCENE_SEVEN:
            backtoinfo.touchDown(touch);
            start.touchDown(touch);
            
            break;
    }
    
    isTouchDown = true;
    prevSpherePt = screenToSphere(ofxVec2f(touch.x, touch.y));
}


//--------------------------------------------------------------
void researchScene::touchMoved(ofTouchEventArgs &touch){

    caseB.touchMoved(touch);
    infoB.touchMoved(touch);
    hintB.touchMoved(touch); 
    back.touchMoved(touch);
    backtoinfo.touchMoved(touch);
    start.touchDown(touch);
    
    float x = touch.x;
    float y = touch.y;
    
    currSpherePt = screenToSphere(ofxVec2f(x, y));
    
    if(currSpherePt == prevSpherePt) return;
    
    axis = currSpherePt.crossed(prevSpherePt);
    axis.normalize();
    
    currSpherePt.normalize();
    prevSpherePt.normalize();
    
    theta = acos(currSpherePt.dot(prevSpherePt));
    theta *= RAD_TO_DEG;
    
    prevSpherePt = currSpherePt;
    
    touchX = x;
    touchY = y;
}


//--------------------------------------------------------------
void researchScene::touchUp(ofTouchEventArgs &touch){

    isTouchDown = false;
       
    switch(mgr.getCurScene()) {
        case MNH_RESEARCH_SCENE_FIRST:
            if (caseB.isPressed()) {
                mgr.setCurScene(MNH_RESEARCH_SCENE_SECOND);
//                casechecked = true;
                
            }else if(infoB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
//                infochecked = true;

                
            }else if(hintB.isPressed()){
                mgr.setCurScene(MNH_RESEARCH_SCENE_FOURTH);
//                hintchecked = true;
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
                init3DViewer(MNH_FAL_ANTEMORTEM1); 
                mgr.setCurScene(MNH_RESEARCH_SCENE_FIFTH);
              

            }else if (periB.isPressed())
            {
                 mgr.setCurScene(MNH_RESEARCH_SCENE_SIX);
                init3DViewer(MNH_FAL_PERIMORTEM1);

            }else if(postB.isPressed())
            {
                 mgr.setCurScene(MNH_RESEARCH_SCENE_SEVEN);
     

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
            
            if (swap.isPressed()) {
                delete boneModel;
                boneModel = NULL;
                a =! a;
                if(a){
                    init3DViewer(MNH_FAL_ANTEMORTEM2);
                }else{
                    init3DViewer(MNH_FAL_ANTEMORTEM1);
                }
            }
                        
            
            if (backtoinfo.isPressed()) {
                delete boneModel;
                boneModel = NULL;
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
            }else if(start.isPressed()){
                delete boneModel;
                boneModel = NULL;
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
            
            
            break;
        case MNH_RESEARCH_SCENE_SIX:
           
            if (swap.isPressed()) {
                 a =! a;
                delete boneModel;
                boneModel = NULL;
                bFirstRun = false;

                if(a){
                    init3DViewer(MNH_FAL_PERIMORTEM2);
                }else{
                    init3DViewer(MNH_FAL_PERIMORTEM1);
                }
            }
            
            if (backtoinfo.isPressed()) {
                delete boneModel;
                boneModel = NULL;
                bFirstRun = false;
                
                mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);
            }else if(start.isPressed()){
                delete boneModel;
                boneModel = NULL;
                bFirstRun = false;
                mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
            }
         
            break;
        case MNH_RESEARCH_SCENE_SEVEN:
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
//-------------------------------
bool researchScene::getnotice(bool A){
    if (A) {
        reset = true;
    }
}

//--------------------------------------------------------------
ofxVec3f researchScene::screenToSphere(ofxVec2f p){
    //http://viewport3d.com/trackball.htm
    ofxVec3f sphereCenter = ofxVec3f(modelXPos, modelYPos);

    p = p - sphereCenter;
    
    float val = sphereRadius*sphereRadius - p.x*p.x - p.y*p.y;
    if (val < 0) 
        val *= -1;
    
    p.z = sqrt(val);

    return p;
}

//--------------------------------------------------------------
void researchScene::matrixCapture() {
    //glGetDoublev( GL_MODELVIEW_MATRIX, modelMatrix );
    glGetFloatv(GL_MODELVIEW_MATRIX, modelMatrix );
}


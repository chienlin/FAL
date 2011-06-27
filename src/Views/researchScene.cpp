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
    //start activity button
    start.setSize(100, 50);
    start.setPos(back.rect.width/2,back.rect.height);
    start.setLabel("Start Activity!", &mnhAssets->whitneySemiBold22);
    
    firstDoubleTap = false;
    isTouchDown = false;
    touchX = 0;
    touchY = 0;
    

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
    
    if (!isTouchDown)
        boneModel.setRotation(1, 270 + ofGetElapsedTimef() * 30, 0, 1, 0); 
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
            init3DViewer(t);
            drawModel();
            //threeD.draw(0,0);
            
            back.draw(0,ofGetHeight()-back.rect.height-50);
            start.draw(ofGetWidth()-start.rect.width,ofGetHeight()-start.rect.height-50);
            sceneName = "Third Sub Scene!";
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
            boneFileName = "Skull_321498_aka_843-reduced10k-tex.3ds";
            break;
        case MNH_FAL_PERIMORTEM:
            boneFileName = "Cranium_209434-reduced10k.3ds";
            break;
        default:
            break;
    }
    
    boneModel.loadModel(boneFileName, 3);
    model3DS* model = (model3DS*)boneModel.model;
    
    //boneModel info 
    for (int i=0; i<model->m_meshes.size(); i++) {
        mesh3DS* m3ds = &model->m_meshes[i];
        cout << endl;
        cout << "# of model verts "  << m3ds->m_vertices.size() << endl;
        cout << "# of model normals " << m3ds->m_normals.size() << endl;
        cout << "# of model faces " << m3ds->m_faces.size() << endl;
    }
    
    //set model to right-side-up
    boneModel.setRotation(0, 180.0, 0, 0, 1);
    //set initial scale
    boneModel.setScale(0.75, 0.75, 0.75);
    //set initial pos
    boneModel.setPosition(modelXPos, modelYPos, 0);
}

//--------------------------------------------------------------
void researchScene::drawModel(){
    glPushMatrix();
        glEnable (GL_LIGHTING);
        //draw in middle of the screen
        glTranslatef(modelXPos,modelYPos,0);
        //tumble according to mouse
        glRotatef(-touchY,1,0,0);
        glRotatef(touchX,0,1,0);
        glTranslatef(-modelXPos,-modelYPos,0);
        
        ofSetColor(254, 254, 254, 255);
        boneModel.draw();
        glDisable(GL_LIGHTING);
    glPopMatrix();
}

//--------------------------------------------------------------
//Event Listeners

//--------------------------------------------------------------
void researchScene::touchDown(ofTouchEventArgs &touch){
     isTouchDown = true;
    
    //active the buttons only for the first scene
    if(mgr.getCurScene() == 0) 
    {
        caseB.touchDown(touch);
        infoB.touchDown(touch);
        hintB.touchDown(touch);
    }
    if(mgr.getCurScene() == 2) 
    {
        anteB.touchDown(touch);
        periB.touchDown(touch);
        postB.touchDown(touch);
    }
    back.touchDown(touch);
    start.touchDown(touch);
}


//--------------------------------------------------------------
void researchScene::touchMoved(ofTouchEventArgs &touch){

    caseB.touchMoved(touch);
    infoB.touchMoved(touch);
    hintB.touchMoved(touch); 
    back.touchMoved(touch);
    start.touchDown(touch);
    
    touchX = touch.x;
    touchY = touch.y;


}


//--------------------------------------------------------------
void researchScene::touchUp(ofTouchEventArgs &touch){
    isTouchDown = false;
    
    if (back.isPressed()) {
        mgr.setCurScene(MNH_RESEARCH_SCENE_FIRST);
    }else if(start.isPressed()){
        mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
        
        cout<<"start is pressed"<<endl;
        
    // for the research subscenes    
    }else if (caseB.isPressed()) {
        mgr.setCurScene(MNH_RESEARCH_SCENE_SECOND);
    }else if(infoB.isPressed()){
        mgr.setCurScene(MNH_RESEARCH_SCENE_THIRD);

    }else if(hintB.isPressed()){
        mgr.setCurScene(MNH_RESEARCH_SCENE_FOURTH);
    }
    
    
    // for the info subscenes
    if(mgr.getCurScene() == 2) 
    {
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
    }
}

//--------------------------------------------------------------
void researchScene::touchDoubleTap(ofTouchEventArgs &touch){
    if(!firstDoubleTap) {
        boneModel.setScale(1.0, 1.0, 1.0);
    }
    
    if(firstDoubleTap) {
        boneModel.setScale(0.75, 0.75, 0.75);
    }
    
    firstDoubleTap = !firstDoubleTap;
}

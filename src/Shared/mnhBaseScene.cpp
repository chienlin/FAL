//
//  mnhBaseScene.cpp
//  collectionsZone
//
//  Created by Stephen Varga on 6/8/11.
//  Copyright 2011 Parsons the New School for Design. All rights reserved.
//

#include "mnhBaseScene.h"
//------------------------------------------------------------------
mnhBaseScene::mnhBaseScene() {
    this->mnhSM = mnhSceneManager::getInstance();
    this->mnhAssets = mnhAssetManager::getInstance();
    
    sceneName = "Scene Name not Set!";
}


//------------------------------------------------------------------
void mnhBaseScene::setup() {
}



//------------------------------------------------------------------
void mnhBaseScene::update() {
}



//------------------------------------------------------------------
void mnhBaseScene::draw() {
}


//------------------------------------------------------------------
void mnhBaseScene::drawGrid() {
    ofBackground(255, 255, 255);
    int gridWidth = ofGetWidth() + MNH_GRID_CELL_SIZE;
    int gridHeight = ofGetHeight() + MNH_GRID_CELL_SIZE;
    
    glPushMatrix();
    glTranslatef(-MNH_GRID_CELL_SIZE/2, -MNH_GRID_CELL_SIZE/2, 0);
    
    //Draw Vertical Lines
    for(int i=1; i<ceil(gridHeight/MNH_GRID_CELL_SIZE); i++) {
        ofSetColor(235, 235, 235);
        ofLine(0, MNH_GRID_CELL_SIZE * i, gridWidth, MNH_GRID_CELL_SIZE * i);
    }
    
    //Draw Horizontal Lines
    for(int i=1; i<ceil(gridWidth/MNH_GRID_CELL_SIZE); i++) {
        ofSetColor(235, 235, 235);
        ofLine(MNH_GRID_CELL_SIZE * i, 0, MNH_GRID_CELL_SIZE * i, gridHeight);
    }
    
    glPopMatrix();
}



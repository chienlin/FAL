//
//  mnhBottomMenu.cpp
//  mnhPrototype
//
//  Created by Stephen Varga on 6/15/11.
//  Copyright 2011 Vargatron. All rights reserved.
//

#include "mnhBottomMenu.h"

//------------------------------------------------------------------
void mnhBottomMenu::setup() {
    //Get Managers
    mnhAssets   = mnhAssetManager::getInstance();
    mnhSM       = mnhSceneManager::getInstance();
    
    rect.width  = ofGetWidth();
    rect.height = 50;
    
    rect.x = 0;
    rect.y = ofGetHeight();
    
    bShowing = false;
    showingY = ofGetHeight() - rect.height;
    
    //Menu BG
    disableBG();
    bgImage.loadImage("images/menu/menuBG.png");
    
    
    //Set Labels
    labels[MNH_BTM_MENU_HOME]       = "Home";
    labels[MNH_BTM_MENU_RESEARCH]   = "Resources";
    labels[MNH_BTM_MENU_ACTIVITY]   = "Activity";
    
    //Create Buttons
    
    ofColor bgOffColor, bgOnColor;
    bgOffColor.r = bgOffColor.g = bgOffColor.b = 0;
    bgOffColor.a = 0;
    bgOnColor = bgOffColor;
    bgOnColor.a = 50;
    
    for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
        buttons[i].setLabel(labels[i], &mnhAssets->whitneySemiBold22);
        buttons[i].setSize(MNH_BTM_MENU_BTN_W, rect.height);
        buttons[i].setColor(bgOffColor, bgOnColor);
        disableBG();
    }
}


//------------------------------------------------------------------
void mnhBottomMenu::show() {
    Tweenzor::add(rect.y, rect.y, showingY, 0, 30, EASE_OUT_QUAD);
    bShowing = true;
}


//------------------------------------------------------------------
void mnhBottomMenu::hide() {
    Tweenzor::add(rect.y, rect.y, ofGetHeight(), 0, 30, EASE_OUT_QUAD);
    bShowing = false;
}


//------------------------------------------------------------------
void mnhBottomMenu::update() {
}



//------------------------------------------------------------------
void mnhBottomMenu::draw() {
    baseButton::draw();
    
    //Draw BG Image (Flip Vertical to use same BG as top menu)
    glPushMatrix();
        glTranslatef(0, rect.y + rect.height, 0);
        glRotatef(180, 1, 0, 0);
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255);
        bgImage.draw(0,0,ofGetWidth(), bgImage.height);
        ofDisableAlphaBlending();   
    glPopMatrix();
    
    //Draw buttons relative to overall menu, with line before each
    int startX = rect.width/2 - (MNH_BTM_MENU_BTN_W * MNH_BTM_MENU_TOTAL)/2;
    int curX = startX;
    for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
        curX = drawSeparatorLine(curX);
        
        buttons[i].setPos(curX, rect.y);
        buttons[i].draw();
        
        curX += buttons[i].rect.width;
    }
    
    //Draw final line
    drawSeparatorLine(curX);
}


//------------------------------------------------------------------
int mnhBottomMenu::drawSeparatorLine(int x) {
    //Draw First Line
    ofSetColor(195, 195, 195);
    ofLine(x, rect.y, x, rect.y+rect.height);
    
    ofSetColor(145, 145, 145);
    ofLine(x+1, rect.y, x+1, rect.y+rect.height);
    
    return x+2;
}


//--------------------------------------------------------------
void mnhBottomMenu::touchDown(ofTouchEventArgs &touch){
    if(bShowing) {
        baseButton::touchDown(touch);
        for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
            buttons[i].touchDown(touch);
        }
    }
}


//--------------------------------------------------------------
void mnhBottomMenu::touchMoved(ofTouchEventArgs &touch){
    if(bShowing) {
        baseButton::touchMoved(touch);
        for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
            buttons[i].touchMoved(touch);
        }
    }
}


//--------------------------------------------------------------
void mnhBottomMenu::touchUp(ofTouchEventArgs &touch){
    if(bShowing) {
        for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
            if(buttons[i].isPressed()) {
                switch (i) {
                    case MNH_BTM_MENU_HOME:
                        mnhSM->setCurScene(MNH_SCENE_HOME);
                        break;
                    case MNH_BTM_MENU_RESEARCH:
                        mnhSM->setCurScene(MNH_SCENE_RESEARCH);
                        break;
                    case MNH_BTM_MENU_ACTIVITY:
                        mnhSM->setCurScene(MNH_SCENE_ACTIVITY);
                        break;
                    default:
                        break;
                }
                
                break;
            }
        }
        
        baseButton::touchUp(touch);
        
        for(int i=0; i<MNH_BTM_MENU_TOTAL; i++) {
            buttons[i].touchUp(touch);
        }
    }
}
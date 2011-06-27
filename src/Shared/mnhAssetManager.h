//
//  mnhAssetManager.h
//  collectionsZone
//
//  Created by Vtron on 6/8/11.
//  Copyright 2011 Vargatron. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxFreeType2.h"

#define MNH_GRID_CELL_SIZE 128

class mnhAssetManager {
    public:
        static mnhAssetManager* getInstance();
        
        bool loadData();
        void loadFonts();
        void loadImages();
    
        ofxXmlSettings data;
    
        //Fonts
        ofxFreeType2 whitneySemiBold22;
    private:
        mnhAssetManager();
        ~mnhAssetManager();
        
        static mnhAssetManager* pmnhAssetManager;
};
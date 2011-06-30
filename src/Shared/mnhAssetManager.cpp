//
//  mnhAssetManager.cpp
//  collectionsZone
//
//  Created by Vtron on 6/8/11.
//  Copyright 2011 Vargatron. All rights reserved.
//

#include "mnhAssetManager.h"

//------------------------------------------------------------------
//Singleton Instance/Get Instance
mnhAssetManager* mnhAssetManager::pmnhAssetManager=NULL;

//------------------------------------------------------------------
mnhAssetManager* mnhAssetManager::getInstance() {
	if(pmnhAssetManager==NULL) {
		pmnhAssetManager=new mnhAssetManager();
	}
	
	return pmnhAssetManager;
}


//------------------------------------------------------------------
mnhAssetManager::mnhAssetManager() {
}


//------------------------------------------------------------------
void mnhAssetManager::loadFonts() {
	whitneySemiBold22.loadFont("fonts/Whitney-Semibold.otf",22);
}


//------------------------------------------------------------------
bool mnhAssetManager::loadData() {
    return true;
}
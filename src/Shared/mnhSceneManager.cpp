//
//  mnhSceneManager.cpp
//  mnhPrototype
//
//  Created by Stephen Varga on 6/23/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "mnhSceneManager.h"


//------------------------------------------------------------------
//Singleton Instance/Get Instance
mnhSceneManager* mnhSceneManager::pmnhSceneManager=NULL;

//------------------------------------------------------------------
mnhSceneManager* mnhSceneManager::getInstance() {
	if(pmnhSceneManager==NULL) {
		pmnhSceneManager=new mnhSceneManager();
	}
	
	return pmnhSceneManager;
}

mnhSceneManager::mnhSceneManager() {
    
}


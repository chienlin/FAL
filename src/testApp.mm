#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// register touch events
	ofRegisterTouchEvents(this);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	//If you want a landscape oreintation 
	iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
    
    //Must call init before doing any animation (ie Menu Coming up)
    Tweenzor::init();
	
	ofBackground(255,255,255);
    
    
    //Load Assets
    mnhAssets = mnhAssetManager::getInstance();
    if(mnhAssets->loadData()) {
        mnhAssets->loadFonts();
        
        //Setup scene manager/Scenes
        mnhSM = mnhSceneManager::getInstance();
        
        scenes[MNH_SCENE_HOME]      = new homeScene();
        scenes[MNH_SCENE_RESEARCH]  = new researchScene();
        scenes[MNH_SCENE_ACTIVITY]  = new activityScene();

        try {
            for(int i=0; i<MNH_TOTAL_SCENES; i++) {
                scenes[i]->setup();
            }
        } catch(string error) {
            cout << "View not intitialized! Please make sure every scene is created above!" << endl;
        }
    } else {
        cout << "Could not load the data!" << endl;
    }
    
    
    
    //Setup Menu
    menu.setup();
    menu.show();
}


//--------------------------------------------------------------
void testApp::update(){
    Tweenzor::update();
    if(mnhSM->getCurSceneChanged()) {
        for(int i=0; i<MNH_TOTAL_SCENES; i++) {
            scenes[i]->deactivate();
        }
        
        scenes[mnhSM->getCurScene()]->activate();
    }
    

    
    
    scenes[mnhSM->getCurScene()]->update();
    
    menu.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    if(!mnhSM->getCurSceneChanged(false)) {
       scenes[mnhSM->getCurScene()]->draw();
    }
    
    menu.draw();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
    scenes[mnhSM->getCurScene()]->touchDown(touch);
    
    menu.touchDown(touch);
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
    scenes[mnhSM->getCurScene()]->touchMoved(touch);
    
    menu.touchMoved(touch);
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
    scenes[mnhSM->getCurScene()]->touchUp(touch);
    
    menu.touchUp(touch);
    
    // if menu is pressed, the screen alway goes back to first subscence(activate)
    if (menu.touched) {
        scenes[mnhSM->getCurScene()]->activate();
    }
    menu.touched = false;
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){
    scenes[mnhSM->getCurScene()]->touchDoubleTap(touch);
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    //Set View to Landscape, for some reason they are reversed on iPad...
	if(newOrientation == OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT) {
		iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT);
	} else if(newOrientation == OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT) {
		iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	}
}


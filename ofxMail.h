//
//  ofxMail.h
//  mnhPrototype
//
//  Created by Miguel on 6/28/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "ofMain.h"
#import <MessageUI/MessageUI.h>

class ofxMail
{
public:
    ofxMail();
    ~ofxMail();
    
    void show();
    void hide();

protected:
    MFMailComposeViewController *mailVC;
};

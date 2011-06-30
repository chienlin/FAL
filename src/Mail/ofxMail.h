//
//  ofxMail.h
//  mnhPrototype
//
//  Created by Miguel on 6/28/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>



@interface mailComposerDelegate : UIViewController<MFMailComposeViewControllerDelegate> 
{
    NSInteger theResult;
}
@property(nonatomic,assign)NSInteger theResult;
@end

class ofxMail
{
public:
    ofxMail();
    ~ofxMail();
    
    void setup();
    void show();
    int  getResult();
    
    mailComposerDelegate    *mailComposer;
};

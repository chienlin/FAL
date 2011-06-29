//
//  ofxMail.mm
//  mnhPrototype
//
//  Created by Miguel on 6/28/11.
//  Copyright 2011 Potion. All rights reserved.
//

#include "ofxMail.h"
#include "ofxiPhoneExtras.h"

ofxMail::ofxMail()
{
    
}

ofxMail::~ofxMail()
{
    
}

void ofxMail::show()
{
    if ([MFMailComposeViewController canSendMail]) {
        
//        mailVC = [[MFMailComposeViewController alloc] init];
//        
//        UIWindow* window = ofxiPhoneGetUIWindow();
//        [window addSubview:mailVC.view];
//        [mailVC release];
        //mfViewController.mailComposeDelegate = self;
        
//        [self presentModalViewController:mfViewController animated:YES];
//        [mfViewController release];
    }
//    }else {
//        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Status:" message:@"Your phone is not currently configured to send mail." delegate:nil cancelButtonTitle:@"ok" otherButtonTitles:nil];
//        
//        [alert show];
//        [alert release];
//    }
}

void ofxMail::hide()
{
    [mailVC.view removeFromSuperview];
    mailVC = nil;
}
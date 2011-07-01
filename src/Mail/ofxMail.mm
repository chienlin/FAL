//
//  ofxMail.h
//  mnhPrototype
//
//  Created by Miguel on 6/28/11.
//  Copyright 2011 Potion. All rights reserved.
//
#include "ofxMail.h"

@implementation mailComposerDelegate

@synthesize theResult;

- (id)init
{
    self = [super init];
    if( self )
    {
        theResult = 0;
    }
    return self;
}

- (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error
{
    switch (result)
	{
		case MFMailComposeResultCancelled:
//            NSLog(@"cancelled");
            self.theResult = -1;
			break;
		case MFMailComposeResultSaved:
//            NSLog(@"saved");
            self.theResult = 1;
			break;
		case MFMailComposeResultSent:
//            NSLog(@"sent");
            self.theResult = 2;
			break;
		case MFMailComposeResultFailed:
//            NSLog(@"failed");
            self.theResult = -2;
			break;
		default:
		{
			UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Email" message:@"Sending Failed – Unknown Error  "
														   delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
			[alert show];
			[alert release];
		}
            
            break;
	}
    [self dismissModalViewControllerAnimated:YES];
}

// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationLandscapeLeft || interfaceOrientation == UIInterfaceOrientationLandscapeRight);
}

@end

ofxMail::ofxMail()
{
    
}

ofxMail::~ofxMail()
{
    [mailComposer release];
    mailComposer = nil;
}

int ofxMail::getResult()
{
    int r = [mailComposer theResult];
    [mailComposer setTheResult:0];
    return r;
}

void ofxMail::setup()
{
    mailComposer = [[mailComposerDelegate alloc] init];
    [mailComposer setView:ofxiPhoneGetGLView()];
    [mailComposer setModalTransitionStyle: UIModalTransitionStyleCoverVertical];
}

void ofxMail::show()
{
    // The actual mail window call
    if([MFMailComposeViewController canSendMail])
    {
        MFMailComposeViewController *mailVC = [[MFMailComposeViewController alloc] init];
        [[mailVC navigationBar] setTintColor:[UIColor blackColor]];
        mailVC.mailComposeDelegate = mailComposer;
        
        [mailVC setSubject: @"Forensic Anthropology Mystery"];
        
        // Fill out the email body text
        
        
        NSString *pageLink = @"http://anthropology.si.edu/writteninbone/comic/";
        NSString *emailBody = [NSString stringWithFormat: @"You completed the Forensic Anthropology activity at the National Museum of Natural History today! Click <a href = '%@'>here</a> to investigate a real-life forensic anthropology mystery.", pageLink];
        
        [mailVC setMessageBody:emailBody isHTML:YES];
        
        [mailComposer presentModalViewController:mailVC animated:YES];
        [mailVC release];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc]
                              initWithTitle: @"No Mail Accounts"
                              message: @"Please set up a Mail account in order to send email."
                              delegate: nil
                              cancelButtonTitle:@"OK"
                              otherButtonTitles:nil];
        [alert show];
        [alert release];
    }
}
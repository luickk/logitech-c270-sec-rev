//
//  LogiDeviceManager.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 03/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "constant.h"
//#import <LogiWebcamComponent/LogiDeviceInfo.h>
//#import <LogiWebcamComponent/LogiWebcamComponent.h>
//#include "LogiDeviceInfo.h"
#import "LogiWebcamComponent.h"

@interface LogiDeviceManager : NSObject
{
    NSArray* mVideoDevices;
    NSArray* mAudioDevices;
}

@property (nonatomic, readonly, getter = getAudioDeviceList)  NSArray* audioDevices;
@property (nonatomic, readonly, getter = getVideoDeviceList)  NSArray* videoDevices;


+(LogiDeviceManager*)getSharedInstance;

+(void)destroy;

-(NSArray*)getVideoDeviceList;

-(NSArray*)getAudioDeviceList;

-(void)updateVideoDeviceList;

-(void)updateAudioDevicelist;

@end

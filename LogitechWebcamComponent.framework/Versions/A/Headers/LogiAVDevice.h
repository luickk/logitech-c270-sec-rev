//
//  LogiAVStream.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 04/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MacTypes.h>
#import <Cocoa/Cocoa.h>
#import "LogiDeviceInfo.h"
//@class LogiDeviceInfo;

@protocol LogiAVDeviceDelegate <NSObject>

-(void)didCaptureFrame: (void*)frame
                length: (UInt32)outLength
             timestamp: (TimeValue64)outTime
            withDevice: (LogiDeviceInfo*)outDevice;

@optional
-(void)didMicLevelEventOccured:(float)inLevel;

@end

//abc
@interface LogiAVDevice : NSObject
{
    LogiDeviceInfo* mDeviceInfo;
    NSMutableArray* mDelegates;
    BOOL            mIsCapturing;
    BOOL            mIsOpen;
    void*           mHandle;
}

@property (readonly)   NSArray*           delegates;
@property (readonly) LogiDeviceInfo*    deviceInfo;
@property (readonly) BOOL               isCapturing;
@property (readonly) BOOL               isOpen;

+(LogiAVDevice*)newDevice:(LogiDeviceInfo*)inDeviceinfo;

-(id)initWithDeviceInfo: (LogiDeviceInfo*)inDeviceInfo;

-(void)addDelegate:(id<LogiAVDeviceDelegate>)inDelegate;

-(void)removeDelegate:(id<LogiAVDeviceDelegate>)inDelegate;

@end

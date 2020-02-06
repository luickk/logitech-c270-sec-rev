//
//  LogiRecordSession.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 05/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "LogiAVDevice.h"

@class LogiAudioDevice;
@class LogiVideoDevice;
@class LogiRecorder;

@interface LogiRecordSession : NSObject <LogiAVDeviceDelegate>
{
    LogiVideoDevice*    mVideoDevice;
    LogiAudioDevice*    mAudioDevice;
    LogiRecorder*       mRecorder;
    NSString*           mFileURL;
    
    BOOL                mIsRunning;
}

@property (readonly) NSString*      fileURL;
@property (retain) LogiVideoDevice* videoDevice;
@property (retain) LogiAudioDevice* audioDevice;
@property (readonly) BOOL           isRunning;

-(id)initWithVideoDevice:(LogiAVDevice*)inVideoDevice
             audioDevice:(LogiAVDevice*)inAudioDevice
              andFileURL:(NSString*) inURL;

-(OSStatus)startSession;

-(OSStatus)stopSession;

@end

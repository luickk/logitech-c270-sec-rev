//
//  LogiRecorder.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 05/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "constant.h"

@class LogiAudioDevice;
@class LogiVideoDevice;

typedef struct LogiMovieCreator LogiMovieCreator;

@interface LogiRecorder : NSObject
{
    LogiMovieCreator* mMovieCreator;
    
    LogiAudioDevice* mAudioStream;
    LogiVideoDevice* mVideoStream;
    
    NSString* mFileURL;
    
    BOOL mIsRecording;
}

@property (retain) NSString*        fileURL;
@property (assign) LogiAudioDevice* audioStream;
@property (assign) LogiVideoDevice* videoStream;
@property (readonly) BOOL           isRecording;

-(OSStatus)openRecorderWithFilPath:(NSString*)inURL
                    forVideoStream:(LogiVideoDevice*)inVideoStream
                    forAudioStream:(LogiAudioDevice*)inAudioStream;

-(OSStatus)addVideoSample:(void*)inFrame
                   length:(UInt32)inLength
                timestamp:(TimeValue64)inTime;

-(OSStatus)addAudioSample:(void*)inFrame
                   length:(UInt32)inLength
                timestamp:(TimeValue64)inTime;

-(OSStatus)closeRecorder;

@end

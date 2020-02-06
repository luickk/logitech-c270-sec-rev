//
//  LogiAudioStream.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 04/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

#import <CoreMedia/CoreMedia.h>
//#import <LogiWebcamComponent/LogiAVDevice.h>
#import "LogiAVDevice.h"

@class LogiDeviceInfo;

@interface LogiAudioDevice : LogiAVDevice {

    CFArrayRef                      mSupportedFormats;
    CMAudioFormatDescriptionRef     mFormat;
    
    NSTimer*                        mMicLevelTimer;
    AVCaptureSession*               mSession;
    AVCaptureAudioPreviewOutput*    mAudioPreviewOutput;
    AVCaptureDeviceInput*           mAudioDeviceInput;
}

@property (assign, getter=getFormat, setter=setFormat:)  CMAudioFormatDescriptionRef format;
@property (readonly, getter=getSupportedFormats)         CFArrayRef                  supportedFormats;

+(NSArray*)getAudioDeviceList;

-(id)initWithDeviceInfo:(LogiDeviceInfo*)inDeviceinfo;

-(OSStatus)openDevice;

-(CFArrayRef)getSupportedFormats;

-(CMAudioFormatDescriptionRef)getFormat;

-(void)setFormat:(CMAudioFormatDescriptionRef)inFormat;

-(OSStatus)startCapture;

-(OSStatus)startVUMeter;

-(OSStatus)stopCapture;

-(OSStatus)stopVUMeter;

-(void)closeDevice;

-(BOOL)isMuteOn;
-(void)setMute:(BOOL)inMute;

-(NSNumber*)getVolumeMax;
-(NSNumber*)getVolumeMin;
-(NSNumber*)getVolumeCur;
-(NSNumber*)getVolumeDefault;
-(void)setVolumeCur:(NSNumber*)inVolume;

-(BOOL)isAutoVolumeSet;
-(void)setAutoVolume:(BOOL)inAutoVolume;

@end

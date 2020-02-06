//
//  LogiVideoStream.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 04/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#ifndef __LogiVideoDevice__
#define __LogiVideoDevice__
#import <CoreMedia/CoreMedia.h>
//#import <LogiWebcamComponent/LogiAVDevice.h>
#import "LogiAVDevice.h"

@interface LogiVideoDevice : LogiAVDevice {

    NSNumber*                   mFrameinterval;
    NSArray*                    mSupportedFrameIntervals;
    CFArrayRef                  mSupportedFormats;
    UInt32                      mSubstream;
    CMVideoFormatDescriptionRef mFormat;
    NSInteger stop;
    dispatch_queue_t            _localQueue;
   
}

@property (assign, getter = getFormat, setter = setFormat:)  CMVideoFormatDescriptionRef format;
@property (readonly, getter = getSupportedFormats)           CFArrayRef                  supportedFormats;
@property (readonly, getter = getSupportedFrameIntervals)    NSArray*                    supportedFrameIntervals;
@property (retain)                                           NSNumber*                   frameInterval;

+(NSArray*)getVideoDeviceList;

+ (BOOL)hasBuiltInCamera;

-(id)initWithDeviceInfo:(LogiDeviceInfo*)inDeviceinfo;

-(OSStatus)openDevice;

-(CMVideoFormatDescriptionRef)getFormat;

-(void)setFormat:(CMVideoFormatDescriptionRef)inFormat;

-(CFArrayRef)getSupportedFormats;

-(NSArray*)getSupportedFrameIntervals:(CMVideoFormatDescriptionRef)inFormat;

-(CFArrayRef)copyFormatsForCodec:(CMVideoCodecType)inCodec formats:(CFArrayRef)inFormats;

-(OSStatus)startCapture;

-(OSStatus)stopCapture;

-(void)closeDevice;

-(NSNumber*)getPanMin;
-(NSNumber*)getPanMax;
-(NSNumber*)getPanCur;
-(void)setPanCur:(NSNumber*)inPan;

-(NSNumber*)getPanRelMin;
-(NSNumber*)getPanRelMax;
-(NSNumber*)getPanRelCur;
-(NSNumber*)getPanRelDef;
-(NSNumber*)getPanDef;
-(void)setPanRelCur:(NSNumber*)inPan;
-(void)resetPanTiltRel;
-(BOOL)isPTZRelativeSupported;

-(NSNumber*)getTiltMin;
-(NSNumber*)getTiltMax;
-(NSNumber*)getTiltCur;
-(NSNumber*)getTiltDef;
-(void)setTiltCur:(NSNumber*)inPan;

-(NSNumber*)getTiltRelMin;
-(NSNumber*)getTiltRelMax;
-(NSNumber*)getTiltRelCur;
-(NSNumber*)getTiltRelDef;
-(void)setTiltRelCur:(NSNumber*)inPan;

-(NSNumber*)getZoomDef;
-(NSNumber*)getZoomMin;
-(NSNumber*)getZoomMax;
-(NSNumber*)getZoomCur;
-(void)setZoomCur:(NSNumber*)inPan;

-(NSNumber*)getZoomRelDef;
-(NSNumber*)getZoomRelMin;
-(NSNumber*)getZoomRelMax;
-(NSNumber*)getZoomRelCur;
-(void)setZoomRelCur:(NSNumber*)inZoomRelative;

-(NSNumber*)getBrightnessMin;
-(NSNumber*)getBrightnessMax;
-(NSNumber*)getBrightnessCur;
-(NSNumber*)getBrightnessDefault;
-(void)setBrightnessCur:(NSNumber*)inBrightness;

-(NSNumber*)getContrastMin;
-(NSNumber*)getContrastMax;
-(NSNumber*)getContrastCur;
-(NSNumber*)getContrastDefault;
-(void)setContrastCur:(NSNumber*)inContrast;

-(NSNumber*)getSaturationMin;
-(NSNumber*)getSaturationMax;
-(NSNumber*)getSaturationCur;
-(NSNumber*)getSaturationDefault;
-(void)setSaturationCur:(NSNumber*)inSaturation;

-(NSNumber*)getHueMin;
-(NSNumber*)getHueMax;
-(NSNumber*)getHueCur;
-(NSNumber*)getHueDefault;
-(void)setHueCur:(NSNumber*)inHue;

-(BOOL)isAutoHueSet;
-(BOOL)getAutoHueDefault;
-(void)setAutoHue:(BOOL)inAutoExposure;

-(NSNumber*)getSharpnessMin;
-(NSNumber*)getSharpnessMax;
-(NSNumber*)getSharpnessCur;
-(NSNumber*)getSharpnessDefault;
-(void)setSharpnessCur:(NSNumber*)inSharpness;


-(NSNumber*)getExposureMin;
-(NSNumber*)getExposureMax;
-(NSNumber*)getExposureCur;
-(NSNumber*)getExposureDefault;
-(void)setExposureCur:(NSNumber*)inPan;

-(BOOL)isAutoExposureSet;
-(void)setAutoExposure:(BOOL)inAutoExposure;

-(BOOL)isRightLightSet;
-(void)setRightLight:(BOOL)inRightLight;

//anils.bhandarkar@robosoftin.com:Begin:Added these function in Progress:
-(NSNumber*)getWhiteBalMin;
-(NSNumber*)getWhiteBalMax;
-(NSNumber*)getWhiteBalCur;
-(NSNumber*)getWhiteBalDefault;
-(void)setWhiteBalAuto:(BOOL)inFlag;
-(void)setWhiteBalCur:(NSNumber*)inWhiteBal;

-(NSNumber*)getFocusMin;
-(NSNumber*)getFocusMax;
-(NSNumber*)getFocusCur;
-(NSNumber*)getFocusDefault;
-(void)setFocusCur:(NSNumber *)inFocus;
-(void)setAutoFocusCur:(NSInteger)inState;
-(NSNumber *)isAutoFocusSet;
-(BOOL)getAutoFocusDefault;

-(NSNumber *)isAutoWhiteBalanceSet;
-(BOOL)getAutoWhiteBalanceDefault;
-(NSDictionary*)getEEPROMInfo;
-(NSDictionary*)getSensorInfo;
-(NSDictionary*)getFirmwareVersion;
-(NSNumber *)getFirmwareCRCControl;

//anils.bhandarkar@robosoftin.com:End

-(void)panRelativeLeft;
-(void)panRelativeRight;
-(void)tiltRelativeUp;
-(void)tiltRelativeDown;
-(OSErr)relativePanTiltStop:(NSInteger)inValue;

// Anti Flicker feature.
-(BOOL)isAntiFlickerSupported;
-(NSNumber*)getAntiFlickerCur;
-(void)setAntiFlickerCur:(NSNumber*)value;
-(NSNumber*)getAntiFlickerDefault;

// Mirror feature. Normal 0, Mirror 1.
-(BOOL)isMirrorSupported;
-(NSNumber*)getMirrorDef;
-(NSNumber*)getMirrorCur;
-(void)setMirrorCur:(NSNumber*)inMirror;

/**
 * @brief   Set Field of View for the camera. Buffer is one byte
 * @param   dFoV    0 for 90 degree FOV and 1 for 78 degree FOV
 */
-(void)setFieldOfView:(int)dFoV;

/**
 * @brief   Get Field of View form the camera
 */
-(bool)getFieldOfView:(NSNumber**)fov;

/**
* Set the HDR value
*/
-(void)setHDRValue:(int)dHdr;

/**
* Get the HDR value
*/
-(NSNumber*)getHDRValue;
@end

#endif

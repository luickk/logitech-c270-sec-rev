//
//  LogiWebcamErrorCodes.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 05/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LogiWebcamComponent_LogiWebcamErrorCodes_h
#define LogiWebcamComponent_LogiWebcamErrorCodes_h

extern NSString* const LWSAudioChannel;    // NSNumber with int.
extern NSString* const LWSAudioSampleRate; // NSNumber with int.
extern NSString* const LWSAudioCodec;      // NSString of four char code.

extern NSString* const LWSVideoWidth;      // NSNumber with int.
extern NSString* const LWSVideoHeight;     // NSNumber with int.
extern NSString* const LWSVideoCodec;      // NSNumber with int.

// Notification keys for Device removed and device added events.
// UserInfo feild of notification contains LogiDeviceInfo containing the description of the device.
extern NSString* const LWSDeviceRemoved;
extern NSString* const LWSDeviceAdded;

enum LogiErrorCodes {
    kNoError,
    kNoMemory,
    kInvalidArguments,
    kInvalidDevice,
    kDeviceBusy,
    kAudioDeviceBusy,
    kVideoDeviceBusy,
    kStreamFailed,
    kMovieError
};

#endif

//
//  LogiDeviceDiscovery.h
//  LogiWebcamComponent
//
//  Created by Tejus Adiga on 03/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include <MacTypes.h>
#include <Cocoa/Cocoa.h>
#include "constant.h"



enum LogiDeviceInterfaceType {
    kDeviceInterfaceTypeUSB,
    kDeviceInterfaceTypeIP
};

enum LogiStreamType {
    kDeviceTypeVideo = 0,
    kDeviceTypeAudio = 1
};

typedef enum LogiStreamType LogiDeviceType;

@interface LogiDeviceInfo : NSObject {
@private
    NSString* mName;
    NSString* mPath;
    UInt16 mProductID;
    UInt16 mVendorID;
    LogiDeviceType mDeviceType;
     UInt16 mRevisionID;
}

@property (retain) NSString* name;
@property (retain) NSString* path;
@property (nonatomic, assign) UInt16 productID;
@property (nonatomic, assign) UInt16 vendorID;
@property (nonatomic, assign) UInt16 revisionID;
@property (nonatomic, assign) LogiDeviceType deviceType;

- (BOOL)isEqualToDevice: (LogiDeviceInfo*)inDevice;

@end

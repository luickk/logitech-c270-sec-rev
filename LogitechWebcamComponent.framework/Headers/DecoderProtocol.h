/************************************************************************************
 *
 * File name:	DecoderProtocol.h
 *
 * Author:		Anil Bhandarkar
 *
 * Copyright: 	Copyright © 2011, Logitech
 *              Written under contract by Robosoft Technologies Pvt. Ltd.
 *
 *************************************************************************************/
#import <CoreVideo/CoreVideo.h>
#import "constant.h"

@protocol DecoderProtocol <NSObject>

- (void)displayData:(CVPixelBufferRef)pixelBuffer;

@end

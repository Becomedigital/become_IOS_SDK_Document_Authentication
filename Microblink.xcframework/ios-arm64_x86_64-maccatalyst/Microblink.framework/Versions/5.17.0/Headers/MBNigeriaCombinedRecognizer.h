//
// MBNigeriaCombinedRecognizer.h
//
// Created by juraskrlec on 11/11/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizer.h"
#import "MBNigeriaCombinedRecognizerResult.h"

#import "MBCombinedRecognizer.h"

#import "MBGlareDetection.h"
#import "MBFaceImage.h"
#import "MBEncodeFaceImage.h"
#import "MBFaceImageDpi.h"
#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of Nigerian Voter ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdCombinedRecognizer.") MB_FINAL
@interface MBNigeriaCombinedRecognizer : MBRecognizer<NSCopying, MBCombinedRecognizer, MBGlareDetection, MBFaceImage, MBEncodeFaceImage, MBFaceImageDpi, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning NigeriaCombinedRecognizer
 */
@property (nonatomic, strong, readonly) MBNigeriaCombinedRecognizerResult *result;

/**
 * Defines how many times the same document should be detected before the detector
 * returns this document as a result of the deteciton
 *
 * Higher number means more reliable detection, but slower processing
 *
 * Default: 6
 */
@property (nonatomic, assign) NSInteger numStableDetectionsThreshold;

@end

NS_ASSUME_NONNULL_END

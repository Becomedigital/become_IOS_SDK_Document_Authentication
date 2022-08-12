//
//  MBKuwaitIdBackRecognizer.h
//  MicroblinkDev
//
//  Created by juraskrlec on 30/08/2018.
//

#import "MBRecognizer.h"
#import "MBKuwaitIdBackRecognizerResult.h"

#import "MBFullDocumentImage.h"
#import "MBEncodeFullDocumentImage.h"
#import "MBFullDocumentImageDpi.h"
#import "MBGlareDetection.h"
#import "MBFullDocumentImageExtensionFactors.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Recognizer which can scan back side of Kuwait national ID cards.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_CLASS_DEPRECATED("Use MBBlinkIdCombinedRecognizer.") MB_FINAL
@interface MBKuwaitIdBackRecognizer : MBRecognizer<NSCopying, MBFullDocumentImage, MBEncodeFullDocumentImage, MBFullDocumentImageDpi, MBGlareDetection, MBFullDocumentImageExtensionFactors>

MB_INIT

/**
 * Result of scanning Kuwait Id Back Recognizer
 */
@property (nonatomic, strong, readonly) MBKuwaitIdBackRecognizerResult *result;

/**
 * Defines if serial number of Kuwait ID should be extracted
 *
 * Default: YES
 */
@property (nonatomic, assign) BOOL extractSerialNo;

@end

NS_ASSUME_NONNULL_END

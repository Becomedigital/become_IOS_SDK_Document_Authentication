// Created by Jura Skrlec on 25.03.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import <Foundation/Foundation.h>
#import "MBCardNumberAnonymizationSettings.h"
#import "MBBlinkCardAnonymizationSettings.h"
#import "MBMicroblinkDefines.h"

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(9.0) MB_FINAL
@interface MBBlinkCardAnonymizationSettings : NSObject<NSCopying>

MB_INIT

/**
 * Defines the parameters of card number anonymization.
 */
@property(nonatomic, strong) MBCardNumberAnonymizationSettings *cardNumberAnonymizationSettings;

/**
 * Defines the mode of card number prefix anonymization.
 *
 * Default: MBBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBBlinkCardAnonymizationMode cardNumberPrefixAnonymizationMode;

/**
 * Defines the mode of CVV anonymization.
 *
 * Default: MBBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBBlinkCardAnonymizationMode cvvAnonymizationMode;

/**
 * Defines the mode of IBAN anonymization.
 *
 * Default: MBBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBBlinkCardAnonymizationMode ibanAnonymizationMode;

/**
 * Defines the mode of owner anonymization.
 *
 * Default: MBBlinkCardAnonymizationModeNone
 */
@property(nonatomic, assign) MBBlinkCardAnonymizationMode ownerAnonymizationMode;

@end

NS_ASSUME_NONNULL_END

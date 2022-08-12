//
// MBNigeriaCombinedRecognizerResult.h
//
// Created by juraskrlec on 11/11/2019
// Copyright © Microblink Ltd. All rights reserved.
//

#import "MBRecognizerResult.h"
#import "MBDateResult.h"

#import "MBCombinedRecognizerResult.h"

#import "MBFaceImageResult.h"
#import "MBEncodedFaceImageResult.h"
#import "MBCombinedFullDocumentImageResult.h"
#import "MBEncodedCombinedFullDocumentImageResult.h"

NS_ASSUME_NONNULL_BEGIN

/**
* Recognizer which can scan front and back side of Nigerian Voter ID cards.
*/
MB_CLASS_AVAILABLE_IOS(8.0)
@interface MBNigeriaCombinedRecognizerResult : MBRecognizerResult<NSCopying, MBCombinedRecognizerResult, MBFaceImageResult, MBEncodedFaceImageResult, MBCombinedFullDocumentImageResult, MBEncodedCombinedFullDocumentImageResult>

MB_INIT_UNAVAILABLE

/**
* The address of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *address;

/**
* The date of birth of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) MBDateResult *dateOfBirth;

/**
* The first name of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *firstName;

/**
* The raw barcode data of Nigeria Voter ID card.
*/
@property (nonatomic, readonly) NSString *rawBarcodeData;

/**
* The sex of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *sex;

/**
* The surname of Nigeria Voter ID owner.
*/
@property (nonatomic, readonly) NSString *surname;

@end

NS_ASSUME_NONNULL_END

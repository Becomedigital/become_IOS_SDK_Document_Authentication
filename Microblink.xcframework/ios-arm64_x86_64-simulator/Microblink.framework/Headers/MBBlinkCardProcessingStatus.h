//
//  MBBlinkCardProcessingStatus.h
//  BlinkShowcaseDev
//
//  Created by Jura Skrlec on 02/11/2020.
//

#ifndef MBBlinkCardProcessingStatus_h
#define MBBlinkCardProcessingStatus_h

/**
* MBBlinkCardProcessingStatus enum defines status of the last recognition process.
*/
typedef NS_ENUM(NSInteger, MBBlinkCardProcessingStatus) {

    /** Recognition was successful. */
    MBBlinkCardProcessingStatusSuccess,

    /** Detection of the document failed. */
    MBBlinkCardProcessingStatusDetectionFailed,

    /** Preprocessing of the input image has failed. */
    MBBlinkCardProcessingStatusImagePreprocessingFailed,

    /** Recognizer has inconsistent results. */
    MBBlinkCardProcessingStatusStabilityTestFailed,

    /** Wrong side of the document has been scanned. */
    MBBlinkCardProcessingStatusScanningWrongSide,

    /** Identification of the fields present on the document has failed. */
    MBBlinkCardProcessingStatusFieldIdentificationFailed,

    /** Failed to return a requested image. */
    MBBlinkCardProcessingStatusImageReturnFailed,

    /** Payment card currently not supported by the recognizer. */
    MBBlinkCardProcessingStatusUnsupportedCard
};

#endif /* MBBlinkCardProcessingStatus_h */

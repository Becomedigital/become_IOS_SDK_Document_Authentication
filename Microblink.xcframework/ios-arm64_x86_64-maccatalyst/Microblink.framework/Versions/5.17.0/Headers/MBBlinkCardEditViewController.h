//
//  MBBlinkCardEditViewController.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 16/10/2020.
//

#import <UIKit/UIKit.h>
#import "MBMicroblinkDefines.h"
#import "MBBlinkCardEditResult.h"
#import "MBBlinkCardRecognizerResult.h"
#import "MBBlinkCardEditFieldConfiguration.h"

@protocol MBBlinkCardEditViewControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBlinkCardEditViewController : UIViewController

MB_INIT_UNAVAILABLE

/**
 * Init view controller with empty MBBlinkCardResult and default MBBlinkCardEditFieldConfiguration
 */
- (instancetype)initWithDelegate:(nonnull id<MBBlinkCardEditViewControllerDelegate>)delegate;

/**
 * Init view controller with MBBlinkCardResult and custom MBBlinkCardEditFieldConfiguration
 */
- (instancetype)initWithBlinkCardRecognizerResult:(nullable MBBlinkCardRecognizerResult *)result
                               fieldConfiguration:(MBBlinkCardEditFieldConfiguration *)fieldConfiguration
                                         delegate:(nonnull id<MBBlinkCardEditViewControllerDelegate>)delegate;

/**
 * Delegate
 */
@property (nonatomic, weak) id<MBBlinkCardEditViewControllerDelegate> delegate;

@end

@protocol MBBlinkCardEditViewControllerDelegate <NSObject>

/**
 * Called when confirm button is pressed, user has finished editing
 *
 *  @param blinkCardEditViewController Edit view controller responsible for editing
 *  @param editResult Blink Card Edited results
 */
- (void)blinkCardEditViewControllerDidFinishEditing:(nonnull MBBlinkCardEditViewController *)blinkCardEditViewController
                                         editResult:(nonnull MBBlinkCardEditResult *)editResult;

/**
 * Edit view controller was closed, usually by the user pressing close button and cancelling the scan
 *
 *  @param blinkCardEditViewController Edit view controller responsible for editing
 */
- (void)blinkCardEditViewControllerDidTapClose:(nonnull MBBlinkCardEditViewController *)blinkCardEditViewController;

@end

NS_ASSUME_NONNULL_END

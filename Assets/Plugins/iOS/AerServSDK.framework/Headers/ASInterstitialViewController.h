//
//  ASViewController.h
//  AerServSDK
//
//  Copyright (c) 2014 AerServ, LLC. All rights reserved.
//
/*! @header
 * View controller used to display an ad
 */

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "ASConstants.h"

@protocol ASInterstitialViewControllerDelegate;

/*!
 * @class ASInterstitialViewController
 *
 * The `ASInterstitialViewController` class provides a full-screen advertisement.
 */
@interface ASInterstitialViewController : UIViewController

/*! The delegate that receives controller state changes. */
@property (nonatomic, weak) id<ASInterstitialViewControllerDelegate> delegate;

/*! Returns the placement Id */
@property (readonly, nonatomic, copy) NSString* placementID;

/*! Will be set to YES when the ad is ready to be displayed. */
@property (readonly, nonatomic, assign) BOOL isReady;

/*! 
 * A flag that defines the environment that the adserver requests are sent to.
 * kASEnvProduction, kASEnvStaging are the recommended choices for this flag.
 *
 * Remember to set this to kASEnvProduction before production builds!!!
 */
@property (nonatomic, assign) ASEnvironmentType env;

/*!
 * If set to YES the ads are in preload mode and will attempt to preload when loadAd is called
 */
@property (nonatomic, assign) BOOL isPreload;

/*!
 * An optional set of keywords that should be passed to the ad server to receive
 * more relevant advertising.
 */
@property (nonatomic, strong) NSArray* keyWords;

/*!
 * An optional set of publisher keys that should be passed to the ad server to receive
 * more relevant advertising.
 */
@property (nonatomic, strong) NSDictionary* pubKeys;

/*!
 * An optional variable to associate ad requests with a user id.
 */
@property (nonatomic, copy) NSString* userId;

/*!
 * If set to YES the ads are outlined in red. Remember to set
 * to NO for production builds.
 */
@property (nonatomic, assign) BOOL showOutline;

/*!
 * The number of seconds to wait before a loading ad should timeout.
 * Ad will send interstitialViewControllerAdFailedToLoad:withError: message on timeout.
 * Defaults to 15 seconds.
 */
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

/*!
 * When set to YES will invoke a location services authorization request
 * if the location services authorization is undetermined. Default is NO.
 */
@property (nonatomic, assign) BOOL locationServicesEnabled;

/*!
 * Internal variable used for measurement, has no affect on serving ads. *
 */
@property (nonatomic, assign) ASPlatformType platform;

/*!
 * Returns an interstitial ad for the given ID.
 *
 * This will create a new full screen view controller for the given placement ID. If this
 * is called again before the controller is destroyed then a cached object for that ID is
 * returned. The view controller is uncached when the controller is destroyed.
 *
 * There can only be one controller for an ID at a time
 *
 * @param placementID An ID that identifies the placement to show.
 */
+ (instancetype)viewControllerForPlacementID:(NSString*)placementID withDelegate:(id<ASInterstitialViewControllerDelegate>)delegate;

/*!
 * Starts the ad request by loading the ad from the server.
 *
 * The delegate should implement interstitialViewControllerAdLoadedSuccssfully to know if an ad has loaded
 * sucessfully. interstitialViewControllerAdFailedToLoad:withError will be called if there is an error while
 * loading the ad.
 */
- (void)loadAd;

/*!
 * Presents the ad's view controller on the parent view controller modally.
 *
 * If there is no ad to display the user will be presented with a spinner until the ad
 * loads.
 */
- (void)showFromViewController:(UIViewController*)parentViewController;

/*!
 * play, pause
 *
 * Controls for the media player.
 */
- (void)play;
- (void)pause;

@end



/*!
 * The protocol is implemented to watch for ASInterstitialViewController state chages.
 */
@protocol ASInterstitialViewControllerDelegate<NSObject>

@optional

/*!
 * Called when the ad has loaded successfuly without preload. 
 * 
 * @param viewController The view controller that the ad is displayed on.
 */
- (void)interstitialViewControllerAdLoadedSuccessfully:(ASInterstitialViewController*)viewController;

/*!
 * Called when the ad has preloaded and is ready to be shown.
 *
 * @param viewController - The view controller with an ad preloaded, needs to be implemented for preload case.
 */
- (void)interstitialViewControllerDidPreloadAd:(ASInterstitialViewController*)viewController;

/*!
 * Called when the ad failed has failed to load.
 *
 * @param viewController The view controller that attempted to load the ad.
 * @param error The error that caused the load to fail.
 */
- (void)interstitialViewControllerAdFailedToLoad:(ASInterstitialViewController*)viewController withError:(NSError*)error;

/*!
 * Called just before the view appears
 * 
 * @param viewController The view controller whose view is about to appear.
 */
- (void)interstitialViewControllerWillAppear:(ASInterstitialViewController*)viewController;

/*!
 * Called just after the view controller's view appears.
 *
 * @param viewController The view controller whose view appeared.
 */
- (void)interstitialViewControllerDidAppear:(ASInterstitialViewController*)viewController;

/*!
 * Called after an ad finishes playing.
 *
 * @param viewController The view controller whose view is about to be dismissed.
 */
- (void)interstitialViewControllerAdDidComplete:(ASInterstitialViewController*)viewController;

/*!
 * Called just before the view is dismissed
 *
 * @param viewController The view controller whose view is about to be dismissed.
 */
- (void)interstitialViewControllerWillDisappear:(ASInterstitialViewController*)viewController;

/*!
 * Called just after the view is dismissed
 *
 * @param viewController The view controller whose view was dismissed.
 */
- (void)interstitialViewControllerDidDisappear:(ASInterstitialViewController*)viewController;

/*!
 * Called when an ad has been touched.
 *
 * @param viewController The view controller whose as has expired.
 */
- (void)interstitialViewControllerAdWasTouched:(ASInterstitialViewController*)viewController;

/*!
 * This called when an ad with a virtual currency reward has loaded
 *
 * @param viewController - The view controller wtih an ad loaded that has virtual currency enabled.
 * @param vcData - A dictionary containing the virtual currency data; contains "name", "rewardAmount", "buyerName", and "buyerPrice" keys
 */
- (void)interstitialViewControllerDidVirtualCurrencyLoad:(ASInterstitialViewController*)viewController vcData:(NSDictionary*)vcData;

/*!
 * This called when an ad with a virtual currency reward has been rewarded
 *
 * @param viewController - The view controller with an ad that completed rewarding virtual currency
 * @param vcData - A dictionary containing the virtual currency data; contains "name" and "rewardAmount" keys
 */
- (void)interstitialViewControllerDidVirtualCurrencyReward:(ASInterstitialViewController*)viewController vcData:(NSDictionary*)vcData;

/*!
 * This is called when there's an advertiser event reported
 *
 * @param viewController - The view controller with an advertiser event reported
 * @param msg - The message associated with the advertiser event
 */
- (void)interstitialViewController:(ASInterstitialViewController*)viewController didFireAdvertiserEventWithMessage:(NSString*)msg;

/*!
 * This is called when virtual currency is not enabled to pass on information pertaining to the ad
 *
 * @param viewController - The view controller with an ad to show
 * @param transactionData - A dictionary containing transaction data; contains "buyerName" and "buyerPrice" keys
 */
- (void)interstitialViewController:(ASInterstitialViewController*)viewController didShowAdWithTransactionInfo:(NSDictionary*)transcationData;


@end

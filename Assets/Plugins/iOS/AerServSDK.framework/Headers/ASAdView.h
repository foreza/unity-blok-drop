//
//  ASAdView.h
//  AerServSDK
//
//  Copyright (c) 2014 AerServ, LLC. All rights reserved.
//
/*! @header
 * View that contains a banner ad.
 */

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "ASConstants.h"

@protocol ASAdViewDelegate;

/*! @name
 * Common banners sizes
 */

/*!
 *  320x50 banner size
 */
extern CGSize const ASBannerSize;

/*!
 *  320x100 banner size
 */
extern CGSize const ASLargeBannerSize;

/*!
 * 300x240 banner size.
 */
extern CGSize const ASMediumRectSize;

/*!
 * 728x90 banner size.
 */
extern CGSize const ASLeaderBoardSize;

/*!
 * 160x600 banner size.
 */
extern CGSize const ASWideSkypscraperSize;



/*!
 * @class ASAdView
 *
 * The `ASAdView` class provides a view that contains a banner ad.
 */
@interface ASAdView : UIView

/*! 
 * The delegate of the ad view
 */
@property (nonatomic, weak) id<ASAdViewDelegate> delegate;

/*!
 * The placement ID of the ad to display.
 */
@property (readonly, nonatomic, copy) NSString* placementID;

/*!
 * An optional seet of keywords that should be passed to the ad server to recieve
 * more relevant advertising.
 */
@property (nonatomic, strong) NSArray* keyWords;

/*!
 * An optional seet of keywords that should be passed to the ad server to recieve
 * more relevant advertising.
 */
@property (nonatomic, strong) NSDictionary* pubKeys;

/*!
 * An optional variable to associate ad requests with a user id.
 */
@property (nonatomic, copy) NSString* userId;

/*! A flag that defines the environment that the adserver requests are sent to.
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
 * If set to YES the ads are outlined in red. Remember to set
 * to NO for production builds.
 */
@property (nonatomic, assign) BOOL outlineAd;

/*!
 * When set to YES, will attempt to scale the ad to fit the corresponding view size, but never bigger
 * than the actual ad size. Defaults to NO.
 */
@property (nonatomic, assign) BOOL sizeAdToFit;

/*!
 * The number of seconds before loading the ad should timeout.
 * Ad will send adViewDidFailToLoadAd:withError: message on timeout.
 * Defaults to 15 seconds.
 */
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

/*!
 * Optionally set a programmatic time interval that will control the rate of refresh for HTML
 * banners. The minimum time interval that can be set is 10 seconds. If not set, there will be a
 * default time interval of 30 seconds.
 *
 * Additionally, any server side configuration should override this value.
 */
@property (nonatomic, assign) NSTimeInterval bannerRefreshTimeInterval;

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
 * Initializes an the view with the given ad ID and banner size.
 * 
 * @param placementID the ID of the ad to display.
 * @param size the desired ad size.
 * @return the view the ad will be placed in.
 */
+ (instancetype)viewWithPlacementID:(NSString*)placementID andAdSize:(CGSize)adSize;

/*!
 * Requests a new ad from the server. If an ad is already loading
 * this call will be ignored. You can use 'forceRefreshAd' to force cancel
 * any existing ad requests and force a new ad to load.
 */
- (void)loadAd;

/*!
 * Cancels any exiting ad requests and requests a new ad from the server.
 */
- (void)forceRefreshAd;

/*!
 * Returns the size of the actual ad that was fetched. 
 *
 * Ad sizes can very between the different ad networks. This is the actual size
 * of the underlying mediated ad. You can use this to adjust the ad view size and 
 * adjust accordingly.
 * 
 * @return The size of the underlying mediated ad.
 */
- (CGSize)adContentSize;

/*!
 * Turns off auto refreshing the banner ad.
 *
 * Ads by default auto refresh every 30 seconds. This will turn the
 * automatic refreshing. Make sure to call startAutomaticallyRefresingContents
 * to re start the auto refresh.
*
 */
- (void)stopAutomaticallyRefreshingContents;

/*!
 * Turns on auto refreshing the banner ad.
 *
 * This turns on the auto refresh for banner ads. To disable you can
 * call stopAutomaticallyRefreshingConetnts.
 */
- (void)startAutomaticallyRefreshingContents;

/*!
 * rotateToOrientation
 *
 * Call this when your view's orientation changes. Some adds may display
 * differently based on rotation.
 *
 * @param newOrientation - the devices current orientation.
 */
- (void)rotateToOrientation:(UIInterfaceOrientation)newOrientation;

/*!
 * play, pause
 * 
 * Call this for video playback control.
 */
- (void)play;
- (void)pause;

/*!
 * showPreloadedBanner
 *
 * Call this after your banner has preloaded to display the ad.
*/
- (void)showPreloadedBanner;

/*!
 * cancel
 *
 * Call this if you want to cancel the ad load attempt during a preload.
 */
- (void)cancel;

@end



/*!
 * The protocol is implemented to watch for ASAdView state changes and provide the view controller
 * for modal view presentation.
 */
@protocol ASAdViewDelegate <NSObject>

/*!
 * The view controller that can be used to present modal view controllers. Like the web
 * brwoser. This must be impletmented.
 *
 * @return the view controller to use when the add needs to present a modal view.
 */
- (UIViewController*)viewControllerForPresentingModalView;

@optional

/*!
 * This called when the ad has been fully loaded.
 *
 * @param adView - The ad that has been loaded.
 */
- (void)adViewDidLoadAd:(ASAdView*)adView;

/*!
 * This called when the ad has failed to load.
 *
 * @param adView - The ad that failed.
 */
- (void)adViewDidFailToLoadAd:(ASAdView*)adView withError:(NSError*)error;

/*!
 * This called when the ad has preloaded
 *
 * @param adView - The ad that preloaded. Must implement for preload functionality.
 */
- (void)adViewDidPreloadAd:(ASAdView*)adView;

/*!
 * This called when the ad is about to present a modal fullscreen view.
 *
 * @param adView - The ad that is presenting the modal fullscreen view.
 */
- (void)willPresentModalViewForAd:(ASAdView*)adView;

/*!
 * Called when the ad's modal view has been dismissed.
 *
 * @param adView - The ad that was displaying the modal view.
 */
- (void)didDismissModalViewForAd:(ASAdView*)adView;

/*!
 * This called when the app is about to the leave the application after
 * ad is clicked.
 *
 * @param adView - The ad that was clicked.
 */
- (void)willLeaveApplicatonFromAd:(ASAdView*)adView;

/*!
 * This is called when a vast video has completed playing
 *
 * @param adView - The ad that completed showing
 */
- (void)adViewDidCompletePlayingWithVastAd:(ASAdView*)adView;

/*!
 * This is called when the size of the ad changes. For example a VAST ad that a playlist with
 * multiple elemnts of different sizes.
 *
 * @param adView - The ad that was clicked.
 */
- (void)adSizedChanged:(ASAdView*)adView;

/*!
 * This is called when the ad is clicked on.
 *
 * @param adView - The ad that was clicked.
 */
- (void)adWasClicked:(ASAdView*)adView;

/*!
 * This is called when the ad view fires an advertiser event
 *
 * @param adView - The ad that fired the adververtiser event
 * @param msg - The message associated with the event
 */
- (void)adView:(ASAdView*)adView didFireAdvertiserEventWithMessage:(NSString*)msg;

/*!
 * This is called when virtual currency is not enabled to pass on information pertaining to the ad
 *
 * @param adView - The view containing an ad to show
 * @param transactionData - A dictionary containing transaction data; contains "buyerName" and "buyerPrice" keys
 */
- (void)adView:(ASAdView*)adVidew didShowAdWithTransactionInfo:(NSDictionary*)transcationData;


@end

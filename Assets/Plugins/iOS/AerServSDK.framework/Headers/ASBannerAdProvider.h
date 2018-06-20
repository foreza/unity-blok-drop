//
//  ASBannerAdProvider.h
//  AerServSDK
//
//  Copyright (c) 2014 AerServ, LLC. All rights reserved.
//

/*! @header
 * Class that must be implemented to provide banners ads to AerServ. */

#import <AVFoundation/AVFoundation.h>

extern NSString* const ASBannerParameter_Parameters;
extern NSString* const ASBannerParameter_HTMLHeaders;
extern NSString* const ASBannerParameter_HTMLData;
extern NSString* const ASBannerParameter_Parameter_URL;
extern NSString* const ASBannerParameter_Location;
extern NSString* const ASBannerParameter_Timeout;

@class ASAdView;
@class ASMRAIDView;

@protocol ASBannerAdProviderDelegate;

@interface ASBannerAdProvider : NSObject

@property (nonatomic, weak) id<ASBannerAdProviderDelegate> delegate;
@property (nonatomic, assign) BOOL outlineAd;
@property (nonatomic, strong) NSDictionary* parameters;
@property (nonatomic, assign) BOOL isPreload;
@property (nonatomic, assign) NSTimeInterval timeoutInt;

@property (nonatomic, strong) NSTimer* refreshTimer;
@property (nonatomic, assign) BOOL automaticallyRefreshAds;
@property (nonatomic, assign) NSTimeInterval bannerRefreshTimeInterval;

- (void)requestAdWithSize:(CGSize)size withProperties:(NSDictionary*)properties isPreload:(BOOL)preload;
- (void)rotateToOrientation:(UIInterfaceOrientation)newOrientation;
- (void)rotateToOrientation:(UIInterfaceOrientation)newOrientation withSize:(CGSize)currSize;
- (void)startPreloadedBannerAd;
- (void)cancel;

- (void)stopAutomaticallyRefreshingAds;
- (void)startAutomaticallyRefreshingAds;
- (void)killRefreshTimer;
- (void)scheduleRefresh;

@end

@protocol ASBannerAdProviderDelegate <NSObject>

@property (nonatomic, copy) NSString* closeOffset;

- (UIViewController*)viewControllerForPresentingModalView;

- (void)bannerProvider:(ASBannerAdProvider*)provider didLoadAd:(UIView*)ad;
- (void)bannerProvider:(ASBannerAdProvider*)provider didPreloadAd:(UIView*)ad;
- (void)bannerProvider:(ASBannerAdProvider*)provider willShowAd:(UIView*)ad;
- (void)bannerProvider:(ASBannerAdProvider*)provider didFailToLoadAdWithError:(NSError*)error;

- (void)bannerProviderWillBeginAction:(ASBannerAdProvider*)provider;
- (void)bannerProviderWillEndAction:(ASBannerAdProvider*)provider;

- (void)bannerProviderWillLeaveApplication:(ASBannerAdProvider*)provider;
- (void)bannerProviderAdChangedSize:(ASBannerAdProvider*)provider;
- (void)bannerProviderAdWasClicked:(ASBannerAdProvider*)provider;
- (void)bannerProviderDidShowAdCompletely:(ASBannerAdProvider*)provider;

- (NSArray*)getKeyWords;
- (NSDictionary*)getPubKeys;

- (void)AVPlayerCreated:(AVPlayer*)avPlayer;

- (void)bannerProvider:(ASBannerAdProvider*)provider willChangeFrameTo:(CGRect)newFrame;
- (ASAdView*)bannerProviderWillGetAdView:(ASBannerAdProvider*)provider;
- (UIView*)bannerProviderWillGetContentView:(ASBannerAdProvider*)provider;
- (void)bannerProvider:(ASBannerAdProvider*)provider willSetContentViewToMRAIDView:(ASMRAIDView*)mraidView;
- (void)bannerProvider:(ASBannerAdProvider*)provider didLoadPlayerLayer:(AVPlayerLayer*)pl;

- (void)bannerProvider:(ASBannerAdProvider*)provider willShowSkip:(BOOL)show;
- (void)bannerProviderWillAttemptRefresh:(ASBannerAdProvider*)provider;

- (void)bannerProvider:(ASBannerAdProvider*)provider didFireAdvertiserEventWithMessage:(NSString*)msg;
- (void)bannerProvider:(ASBannerAdProvider*)provider willUpdateForFailoverWithResponseHeaders:(NSDictionary*)headers;

- (BOOL)bannerProviderWillMute:(ASBannerAdProvider*)provider;
- (void)bannerProviderWillFireBannerPixelEvent:(ASBannerAdProvider*)provider;

@end

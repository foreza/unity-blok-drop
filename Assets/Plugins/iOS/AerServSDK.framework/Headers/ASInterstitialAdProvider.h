//
//  ASAdProvider.h
//  AerServSDK
//
//  Copyright (c) 2014 AerServ, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*! @header
 * Class that must be impletented to provide interstitial ads to AerServ. */

extern NSString* const ASInterstitialParameter_Parameters;
extern NSString* const ASInterstitialParameter_HTMLHeaders;
extern NSString* const ASInterstitialParameter_HTMLData;
extern NSString* const ASInterstitialParameter_Parameter_URL;
extern NSString* const ASInterstitialParameter_Location;
extern NSString* const ASInterstitialParameter_Timeout;

@protocol ASInterstitialAdProviderDelegate;

@interface ASInterstitialAdProvider : NSObject

@property (nonatomic, weak) id<ASInterstitialAdProviderDelegate> delegate;
@property (nonatomic, assign) BOOL outlineAd;
@property (nonatomic, strong) NSDictionary* parameters;
@property (nonatomic, assign) BOOL shouldShowAd;
@property (nonatomic, assign) NSTimeInterval timeoutInt;

- (void)requestInterstitialAdWithProperties:(NSDictionary*)info isPreload:(BOOL)preload;
- (BOOL)enableAutomaticImpressionAndClickTracking;
- (void)showInterstitialFromRootViewController:(UIViewController*)rootViewController;
- (void)cancel;

@end


/* Delegate calls that the interstitial ad provider must call. */

@protocol ASInterstitialAdProviderDelegate <NSObject>

@property (nonatomic, copy) NSString* closeOffset;

- (NSArray*)getKeyWords;
- (NSDictionary*)getPubKeys;
- (void)AVPlayerCreated:(AVPlayer*)avPlayer;

- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didLoadAd:(id)ad;
- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didFailToLoadAdWithError:(NSError*)error;
- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didPreloadAd:(id)ad;
- (void)interstitialAdProviderDidAdComplete:(ASInterstitialAdProvider*)provider;

- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didVirtualCurrencyLoad:(NSDictionary*)vcData;
- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didVirtualCurrencyReward:(NSDictionary*)vcData;

- (void)interstitialAdProviderWillAppear:(ASInterstitialAdProvider*)provider;
- (void)interstitialAdProviderDidAppear:(ASInterstitialAdProvider*)provider;

- (void)interstitialAdProviderWillDisappear:(ASInterstitialAdProvider*)provider;
- (void)interstitialAdProviderDidDisappear:(ASInterstitialAdProvider*)provider;

- (void)interstitialAdProviderAdWasTouched:(ASInterstitialAdProvider*)provider;

- (BOOL)interstitialAdProviderIsPreload:(ASInterstitialAdProvider*)provider;

- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider didFireAdvertiserEventWithMessage:(NSString*)msg;
- (void)interstitialAdProvider:(ASInterstitialAdProvider*)provider willUpdateForFailoverWithResponseHeaders:(NSDictionary*)headers;

- (BOOL)interstitialAdProviderWillMuteAd:(ASInterstitialAdProvider*)provider;
- (void)interstitialAdProviderWillFireBannerPixelEvent:(ASInterstitialAdProvider*)provider;

@end

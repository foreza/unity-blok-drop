//
//  ASCustomBannerAdProvider.h
//  AerServSDK
//
//  Copyright (c) 2015 AerServ, LLC. All rights reserved.
//

#import "ASBannerAdProvider.h"

@interface ASCustomBannerAdProvider : ASBannerAdProvider

- (instancetype)initWithAdClassName:(NSString*)adClassName;
- (instancetype)initWithAdClassName:(NSString*)adClassName timeout:(NSTimeInterval)timeout;

- (void)adFailed:(NSString*)msg;
- (NSString*)valueInProperty:(NSDictionary*)properties forKey:(NSString*)key;

- (void)initializePartnerAd:(NSDictionary*)properties;
- (BOOL)hasPartnerAdInitialized;
- (BOOL)hasPartnerAdFailedToInitialize;
- (void)loadPartnerAd:(NSDictionary*)properties;
- (BOOL)hasPartnerAdLoaded;
- (BOOL)hasPartnerAdFailedToLoad;
- (void)showPartnerAd;
- (void)terminatePartnerAd;

- (UIViewController*)asBannerViewController;
- (UIView*)partnerAdView;
- (UIView*)asAdView;

- (void)asPartnerBannerAdDidLoad:(id)ad;
- (void)asPartnerBannerAdWasClicked;
- (void)asPartnerBannerDidShowAdCompletely;
- (void)asPartnerBannerWillEndAction;
- (void)asPartnerBannerWillLeaveApplication;
- (void)asPartnerBannerWillBeginAction;

@end

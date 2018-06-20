//
//  ASCustomInterstitialAdProvider.h
//  AerServSDK
//
//  Copyright (c) 2015 AerServ, LLC. All rights reserved.
//

#import "ASInterstitialAdProvider.h"
#import <Foundation/Foundation.h>

@interface ASCustomInterstitialAdProvider : ASInterstitialAdProvider

@property (readonly, nonatomic, strong) NSDictionary* properties;
@property (nonatomic, strong) NSDictionary* vcData;

- (id)initWithAdClassName:(NSString*)adClassName;
- (id)initWithAdClassName:(NSString*)adClassName timeout:(NSTimeInterval)timeout;

- (void)initializePartnerAd:(NSDictionary*)properties;
- (BOOL)hasPartnerAdInitialized;
- (BOOL)hasPartnerAdFailedToInitialize;
- (void)loadPartnerAd:(NSDictionary*)properties;
- (BOOL)hasPartnerAdLoaded;
- (BOOL)hasPartnerAdFailedToLoad;
- (void)showPartnerAd:(UIViewController*)rootViewController;
- (void)terminatePartnerAd;
- (void)cancelAdLoadingTimer;
- (NSString*)valueInProperty:(NSDictionary*)properties forKey:(NSString*)key;

- (void)asPartnerInterstitialAdDidLoad:(id)ad;
- (void)asPartnerInterstitialAdWillDisappear;
- (void)asPartnerInterstitialAdDidDisappear;
- (void)asPartnerInterstitialAdWillAppear;
- (void)asPartnerInterstitialAdDidAppear;
- (void)asPartnerInterstitialAdWasTouched;
- (void)asPartnerInterstitialVideoCompleted;

@end

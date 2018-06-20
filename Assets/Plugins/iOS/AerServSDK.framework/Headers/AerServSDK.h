//
//  AerServSDK.h
//  AerServSDK
//
//  Copyright (c) 2014 AerServ, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AerServSDK/ASConstants.h>

#import <AerServSDK/ASAdView.h>
#import <AerServSDK/ASInterstitialViewController.h>
#import <AerServSDK/ASCustomBannerAdProvider.h>
#import <AerServSDK/ASCustomInterstitialAdProvider.h>

#import <AerServSDK/ASAlertManager.h>

#import <AerServSDK/ASAdView+UnityCheck.h>


@interface AerServSDK : NSObject

/*!
 * Looks into each supplied placement and will run pre-initialization for any mediation partner sources that requires an extra setup phase.
 *
 * @param plcArr, an array of string placement ids (i.e. @[@"1002090", @"1005992"])
 */
+ (void)initializeWithPlacments:(NSArray*)plcArr;

/*!
 * Looks into the supplied app id and will run pre-initialization for any mediation partner sources that requires an extra setup phase.
 *
 * @param appIdStr, a string of the app id
 */
+ (void)initializeWithAppID:(NSString*)appIdStr;

/*!
 * Returns current AerServSDK version
 */
+ (NSString*)sdkVersion;

/*!
 * Shows console logs for debugging purposes.
 */
+ (void)showLogs:(BOOL)yesOrNo;

@end

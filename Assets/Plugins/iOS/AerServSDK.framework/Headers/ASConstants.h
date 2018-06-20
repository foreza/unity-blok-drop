//
//  kAerServConstants.h
//  AerServSDK
//
//  Created by Albert Zhu on 6/5/15.
//  Copyright (c) 2015 AerServ, LLC. All rights reserved.
//

#ifndef AerServSDK_AerServConstants_h
#define AerServSDK_AerServConstants_h


#pragma mark - AerServ Constants

#define kAerServSDKName @"AerServ-iOS-SDK"
#define kAerServSDKVersion @"2.39.4"

#define kASProductionBaseURL @"https://ads.aerserv.com/as/"
#define kASStagingBaseURL @"https://staging-ads.aerserv.com/as/"
#define kASDevBaseURL @"https://dev-ads.aerserv.com/as/"

#pragma mark - Enum Constants

typedef void (^ASRequestCompletionBlock)(NSURLResponse* resp, NSData* data, NSError* err);

typedef NS_ENUM(NSUInteger, ASEnvironmentType) {
    kASEnvProduction,
    kASEnvStaging,
    kASEnvDevelopment
};

typedef NS_ENUM(NSUInteger, ASPlatformType) {
    kASPlatformCS = 0,
    kASPlatformU,
    kASPlatformPG,
    kASPlatformB4A,
    kASPlatformAA,
    kASPlatformE
};

#pragma mark - Constants

#define kBannerRefreshKey @"bannerRefresh"
#define kBannerRefreshDefaultInterval 30
#define kBannerRefreshNullValue @"null"
#define kBannerRefreshMinValue 10.0f
#define kBannerRefreshNeverValue 0.0f
#define kBannerRefreshNeverTokenValue -9999.0f

#define kTrueStr @"true"
#define kEmptyStr @""
#define kMillisInSec 1000.0f

#pragma mark - WebKit Message Handlers

#define kDocuementDimensionsCallback @"documentDimensionsCallback"
#define kDocumentInnerHTMLCallback @"documentInnerHTMLCallback"
#define kVPAIDBridgeCallback @"vpaidBridgeCallback"
#define kVPAIDBridgeGetterCallback @"vpaidBridgeGetterCallback"


#pragma mark - Macros

#define kIS_iOS_7_OR_LATER ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0)
#define kIS_iOS_8_OR_LATER ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0)
#define kIS_iOS_9_OR_LATER ([[UIDevice currentDevice].systemVersion floatValue] >= 9.0)
#define kIS_iOS_10_OR_LATER ([[UIDevice currentDevice].systemVersion floatValue] >= 10.0)

#define kIS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define kIS_PORTRAIT UIInterfaceOrientationIsPortrait([UIApplication sharedApplication].statusBarOrientation)
#define kIS_LANDSCAPE UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)

#define kIS_MAINTHREAD NSLog(@"-- Is Main Thread: %d", [[NSThread currentThread] isMainThread]);


#pragma mark - Logging Macros

#define DLog(FORMAT, ...) NSDateFormatter* format=[[NSDateFormatter alloc] init]; format.locale=[NSLocale currentLocale]; format.dateFormat=@"yyyy.MM.dd HH:mm:ss.SSS"; printf("AerServ-iOS-SDK | %s | %s\n", [[NSString stringWithFormat:@"%@", [format stringFromDate:[NSDate date]]] UTF8String], [[NSString stringWithFormat:FORMAT, __VA_ARGS__] UTF8String]); format=nil;



#pragma mark - Generic Javascript Queries

#define kJSGetDocumentWidth @"document.documentElement.scrollWidth"
#define kJSGetDocumentHeight @"document.documentElement.scrollHeight"


#pragma mark - Static Ads

#define kUseStaticTestVASTAd 0
#define kVastStaticTestAdFileName @"AdPod2Ads1stAdFail"
#define kVastStaticTestAdFileType @"xml"

#define kUseStaticTestMRAIDAd 0
#define kMRAIDStaticTestAdFileName @"mraid2_resize"
#define kMRAIDStaticTestAdFileType @"html"


#endif

//
//  WebViewJavascriptBridgeBase.h
//
//  Created by @LokiMeyburg on 10/15/14.
//  Copyright (c) 2014 @LokiMeyburg. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^WVJBResponseCallback)(id responseData);
typedef void (^WVJBHandler)(id data, WVJBResponseCallback responseCallback);
typedef NSDictionary WVJBMessage;

@protocol WebViewJavascriptBridgeBaseDelegate <NSObject>
- (NSString*) _evaluateJavascript:(NSString*)javascriptCommand;
@end

@interface WebViewJavascriptBridgeBase : NSObject


@property (assign) id <WebViewJavascriptBridgeBaseDelegate> delegate;
@property (strong, nonatomic) NSMutableArray* startupMessageQueue;
@property (strong, nonatomic) NSMutableDictionary* responseCallbacks;
@property (strong, nonatomic) NSMutableDictionary* messageHandlers;
@property (strong, nonatomic) WVJBHandler messageHandler;
@property NSUInteger numRequestsLoading;
@property (nonatomic, copy) NSString *customProtocolScheme;
@property (nonatomic, copy) NSString *customHostName;

+ (void)enableLogging;
+ (void)setLogMaxLength:(int)length;
- (id)initWithHandler:(WVJBHandler)messageHandler resourceBundle:(NSBundle*)bundle;
- (void)reset;
- (void)sendData:(id)data responseCallback:(WVJBResponseCallback)responseCallback handlerName:(NSString*)handlerName;
- (void)flushMessageQueue:(NSString *)messageQueueString;
- (void)injectJavascriptFile:(BOOL)shouldInject;
- (BOOL)isCorrectProcotocolScheme:(NSURL*)url;
- (BOOL)isCorrectHost:(NSURL*)urll;
- (void)logUnkownMessage:(NSURL*)url;
- (void)dispatchStartUpMessageQueue;
- (NSString *)webViewJavascriptCheckCommand;
- (NSString *)webViewJavascriptFetchQueyCommand;

@end
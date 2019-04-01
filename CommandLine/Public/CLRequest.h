//
//  CLRequest.h
//  CommandLineDemo
//
//  Created by Unique on 2018/5/15.
//  Copyright © 2018年 unique. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CLCommand;

NS_ASSUME_NONNULL_BEGIN
@interface CLRequest : NSObject

@property (nonatomic, strong, readonly) NSArray *commands;

@property (nonatomic, strong, readonly) NSDictionary *queries;

@property (nonatomic, strong, readonly) NSSet *flags;

@property (nonatomic, strong, readonly) NSArray *paths;

@property (nonatomic, strong, readonly) CLCommand *command;

@property (nonatomic, strong, readonly) NSError *illegalError;

+ (instancetype)request;

+ (instancetype)requestWithArgc:(int)argc argv:(const char *_Nonnull[_Nonnull])argv;

+ (nullable instancetype)requestWithArguments:(NSArray *)arguments;

+ (nullable instancetype)requestWithCommands:(NSArray *)commands queries:(nullable NSDictionary *)queries flags:(nullable  id)flags paths:(nullable NSArray *)paths;

+ (nullable instancetype)illegallyRequestWithCommands:(NSArray *)commands error:(NSError *)error;

- (NSString *)stringForQuery:(NSString *)query;

- (NSString *)pathForQuery:(NSString *)query;

- (NSInteger)integerValueForQuery:(NSString *)query;

- (BOOL)flag:(NSString *)flag;

- (NSString *)pathForIndex:(NSUInteger)index;

- (void)verbose:(NSString *)format, ...;

- (void)verbose:(NSString *)format args:(va_list)arguments;

- (void)print:(NSString *)format, ...;

- (void)print:(NSString *)format args:(va_list)arguments;

- (void)error:(NSString *)format, ...;

- (void)error:(NSString *)format args:(va_list)arguments;

- (void)warning:(NSString *)format, ...;

- (void)warning:(NSString *)format args:(va_list)arguments;

- (void)success:(NSString *)format, ...;

- (void)success:(NSString *)format args:(va_list)arguments;

- (void)info:(NSString *)format, ...;

- (void)info:(NSString *)format args:(va_list)arguments;

@end
NS_ASSUME_NONNULL_END

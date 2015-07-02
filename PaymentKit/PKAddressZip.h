//
//  PKZip.h
//  PKPayment Example
//
//  Created by Alex MacCaw on 2/1/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PKAddressZip : NSObject {
@protected
    NSString *zip;
    NSString *countryCode;
}

@property (nonatomic, readonly) NSString *string;
@property (nonatomic, readonly) NSString *countryCode;

+ (instancetype)addressZipWithString:(NSString *)string;
+ (instancetype)addressZipWithString:(NSString *)string countryCode:(NSString *)countryCode;
- (instancetype)initWithString:(NSString *)string;
- (instancetype)initWithString:(NSString *)string countryCode:(NSString *)countryCode;
- (NSString *)string;
- (BOOL)isValid;
- (BOOL)isPartiallyValid;

@end

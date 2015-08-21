//
//  PKZip.m
//  PKPayment Example
//
//  Created by Alex MacCaw on 2/1/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import "PKAddressZip.h"

@implementation PKAddressZip

+ (instancetype)addressZipWithString:(NSString *)string
{
    return [[self alloc] initWithString:string];
}

+ (instancetype)addressZipWithString:(NSString *)string countryCode:(NSString *)countryCode
{
    return [[self alloc] initWithString:string countryCode:countryCode];
}

- (instancetype)initWithString:(NSString *)string
{
    self = [super init];
    if (self) {
        zip = string;
        countryCode = nil;
    }
    return self;
}

- (instancetype)initWithString:(NSString *)string countryCode:(NSString *)code
{
    self = [super init];
    if (self) {
        zip = string;
        countryCode = code;
    }
    return self;
}

- (NSString *)string
{
    return zip;
}

- (NSString *)countryCode
{
    return countryCode;
}

- (BOOL)isValid
{
    NSString* stripped = [zip stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    
    if (!countryCode)
        return stripped.length == 0;
    
    if ([countryCode isEqualToString:@"US"]) {
        NSString *regEx = @"[0-9]{5}";
        NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
        return [predicate evaluateWithObject:zip];
    }
    
    if ([countryCode isEqualToString:@"CA"]) {
        return stripped.length == 7;
    }

    return stripped.length == 0;
//    return stripped.length > 2;
}

- (BOOL)isPartiallyValid
{
    
    if (!countryCode)
        return zip.length == 0;
    
    if ([countryCode isEqualToString:@"US"]) {
        
        NSString *regEx = @"[0-9]*";
        NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regEx];
        return [predicate evaluateWithObject:zip] && zip.length <= 5;
    }
    
    if ([countryCode isEqualToString:@"CA"]) {
        return zip.length <= 7;
    }
    
    
    return zip.length == 0;
    
//    return zip.length < 10;
}

@end

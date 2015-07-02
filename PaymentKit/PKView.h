//
//  PKPaymentField.h
//  PKPayment Example
//
//  Created by Alex MacCaw on 1/22/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PKCard.h"
#import "PKCardNumber.h"
#import "PKCardExpiry.h"
#import "PKCardCVC.h"
#import "PKAddressZip.h"
#import "PKUSAddressZip.h"

@class PKView, PKTextField;

typedef enum {
    PKViewStateCardNumber,
	PKViewStateExpiry,
	PKViewStateCVC,
    PKViewStateZip
} PKViewState;

typedef enum {
	PKViewImageStyleNormal,
    PKViewImageStyleOutline,
    PKViewImageStyleSmall,
} PKViewImageStyle;


@protocol PKViewDelegate <NSObject>
@optional
- (void)paymentView:(PKView *)paymentView withCard:(PKCard *)card isValid:(BOOL)valid;
- (void)paymentView:(PKView *)paymentView didChangeState:(PKViewState)state;
- (void)paymentViewDidTapCountryFlag:(PKView *)paymentView;
- (BOOL)paymentViewShouldBegingEditing:(PKView *)paymentView;
@end

@interface PKView : UIView

- (BOOL)isValid;

@property(nonatomic) UITextBorderStyle borderStyle;
@property(nonatomic) PKViewImageStyle imageStyle;
@property(nonatomic) UIFont *font;
@property(nonatomic) UIColor *textColor;
@property(nonatomic, copy) NSDictionary *defaultTextAttributes;
@property(nonatomic, copy) NSString *countryCode;
@property(nonatomic) NSTextAlignment cardNumberAlignment;

@property (nonatomic, readonly) UIView *opaqueOverGradientView;
@property (nonatomic, readwrite) PKCardNumber *cardNumber;
@property (nonatomic, readwrite) PKCardExpiry *cardExpiry;
@property (nonatomic, readwrite) PKCardCVC *cardCVC;
@property (nonatomic, readwrite) PKAddressZip *addressZip;

@property UIView *innerView;
@property UIView *clipView;
@property PKTextField *cardNumberField;
@property UITextField *cardLastFourField;
@property PKTextField *cardExpiryField;
@property PKTextField *cardCVCField;
@property PKTextField *cardZipField;
@property UIImageView *placeholderView;
@property (weak) id <PKViewDelegate> delegate;
@property (retain) PKCard *card;

@end

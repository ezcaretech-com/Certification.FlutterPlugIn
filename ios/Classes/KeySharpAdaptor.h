//
//  KeySharpAdaptor.h
//  EzCertificationData
//
//  Created by Jinho Lee on 2022/10/02.
//

#import <Foundation/Foundation.h>
#import "CertManager.h"
#import "ios_Cert.h"
#import "KSBase64.h"
#import "KSutil.h"

@interface KeySharpAdaptor : NSObject {
    NSString *serviceUrl;
    CertManager *certManager;
    NSInteger certIndex;
    NSString *password;
}

@property (nonatomic, retain) NSString *serviceUrl;
@property (nonatomic, retain) CertManager *certManager;
@property (nonatomic, assign) NSInteger certIndex;
@property (nonatomic, retain) NSString *password;

+ (id)shared;
- (id)init;
- (BOOL)downloadWith:(NSString *)userId error:(NSError **)error;
- (int)checkPasswordWith:(int)idx password:(NSString *)userPw error:(NSError **)error;
/// 인증서 암호화 및 검증(AS-IS)
- (NSString *)signAndVerifyWith:(NSString *)password message:(NSString *)message error:(NSError **)error;
/// 인증서 암호화 및 검증(TO-BE)
- (NSString *)signWith:(NSString *)password message:(NSString *)message error:(NSError **)error;
- (void)removeAll;

@end

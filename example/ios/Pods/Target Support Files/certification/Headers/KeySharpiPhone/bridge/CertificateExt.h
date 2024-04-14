//
//  Header.h
//  CertmanagerLibrary
//
//  Created by shield on 12/07/2021.
//  Copyright © 2021 lee minsu. All rights reserved.
//

#ifndef __CERTIFICSTE_EXT_H__
#define __CERTIFICSTE_EXT_H__

#import "CloudNPKI/CloudNPKI.h"

typedef NS_ENUM(NSInteger, CNCertificateType)
{
    CNCertificateCloud = 1,
    CNCertificateFingerPrint
};

@interface CertificateExt : NSObject {
    CNCertificateInfo *certInfo;
    CNCertificateType type;
    BOOL isCache;
}

-(id)initWithCertificateInfo:(CNCertificateInfo *)certInfo isCache:(BOOL)isCache isBio:(BOOL)isBio;

- (CNCertificateType) getType;
- (NSString *)getSubjectDN;
- (NSString *)getIssuerDN;
- (NSString *)getIssuerName;
- (NSString *)getSerial;
- (NSString *)getSerialInt;
- (NSString *)getObjectId;
- (NSDate *)getNotBefore;
- (NSDate *)getNotAfter;
- (NSString *)getId;
- (BOOL)isLock;
- (int)getErrorCount;
- (int) getCertificateCheckExpired;
- (NSString *)getCertificatePolicyString;

//MARK: - 인증서 정보 추출 함수 추가 2023-05-22
- (NSString *)getSubjectCn;
- (NSArray *)getSubjectOu;
- (NSString *)getSubjectOrg;
- (NSString *)getSubjectC;
- (NSString *)getIssuerCn;
- (NSString *)getIssuerOu;
- (NSString *)getIssuerOrg;
- (NSString *)getIssuerC;

@property (nonatomic, retain) CNCertificateInfo* certInfo;
@property (nonatomic) CNCertificateType type;
@property (nonatomic) BOOL isCache ;

@end


#endif /* Header_h */

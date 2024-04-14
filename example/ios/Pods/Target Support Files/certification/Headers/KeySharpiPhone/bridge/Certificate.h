//
//  Certificate.h
//  MyTable2
//
//  Created by leopard on 09. 08. 19.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KSx509.h"

@interface Certificate : NSObject {
	X509Certificate* x509Certificate;
	ks_uint8* certBuf;
	ks_uint8* keyBuf;
	int certLen;
	int keyLen;
	NSString* cn;
	NSString* certPath;
	int idx;
	NSString* label;
    
    ks_uint8* kmCertBuf;
    ks_uint8* kmKeyBuf;
    int kmCertLen;
    int kmKeyLen;
}


- (id) initWithCertPath: (NSString *) certFullPath;
-(id)initWithCert:(NSData*)cert;
-(id)initWithCert:(NSData*)cert withKey:(NSData*)key index:(int)_idx;
-(id)initWithCert:(NSData*)cert withKey:(NSData*)key label:(NSString*)label;
-(id)initWithCerts:(NSData*)cert withKey:(NSData*)key kmCert:(NSData*)kmCert kmKey:(NSData*)kmKey index:(int)_idx;

#ifdef _MAC
-(id)initWithCert:(NSData*)cert andKey:(NSData*)key path:(NSString *)path;
#endif

- (X509Certificate *) getX509Certificate;
- (NSString *) getPEMCertificate;

// 인증서 간단 정보
- (NSString *) getCertificatePolicy;
- (NSString *) getCertificatePolicyTranslator:(int)lnagType;    //15.02.03
- (NSString *) getCertificateSubjectName;
- (NSString *) getCertificateIssuerName;

// 인증서 상세 정보
- (NSString *) getCertificateVersion;
- (NSString *) getCertificateSerialNumber;
- (NSString *) getCertificateSerialNumberIntString;
- (NSString *) getCertificateAlgorithm;
- (NSString *) getCertificateSignatureAlgorithm;	//130326 GPKI
- (NSString *) getCertificateIssuer;
- (NSString *) getCertificateSubject;
- (NSString *) getCertificateValidFrom;
- (NSString *) getCertificateValidTo;
- (NSString *) getCertificateValidTo2;

- (NSData*) getCertificateData;
- (NSData*) getKeyData;
- (NSData*) getKmCertificateData;
- (NSData*) getKmKeyData;
- (NSString *) getCertificateOrganizationname;
- (NSString *) getCertificateUsage;
- (NSString *) getCertificateSubjectLocality;
- (NSString *) getCertificateSubjectStateOrProvinceName;
// 인증서 만료 여부
- (int) getCertificateCheckExpired;
//인증서 정책 스트링.
- (NSString *) getCertificatePolicyString;
//인증서 공개키
- (NSString *) getCertificatePublicKeyString;
//ca 한글
- (NSString *) getCertificateIssuerNameKorean;
//인증서 User Notice
- (NSString *) getUserNotice;

@property (nonatomic, retain) NSString* cn;
@property (nonatomic, readonly) ks_uint8* certBuf;
@property (nonatomic, readonly) ks_uint8* keyBuf;
@property (nonatomic, readonly) int certLen;
@property (nonatomic, readonly) int keyLen;
@property (nonatomic, readonly) int idx;
@property (nonatomic, readonly) NSString* certPath;
@property (nonatomic, readonly) X509Certificate* x509Certificate;
@property (nonatomic, readonly) ks_uint8* kmCertBuf;
@property (nonatomic, readonly) ks_uint8* kmKeyBuf;
@property (nonatomic, readonly) int kmCertLen;
@property (nonatomic, readonly) int kmKeyLen;
@end

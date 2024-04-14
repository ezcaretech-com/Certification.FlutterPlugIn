//
//  SecureData.h
//  Cloud NPKI Example
//
//  Created by Shield팀 on 2021/08/17.
//

#ifndef SecureData_h
#define SecureData_h

#import <CommonCrypto/CommonCryptor.h>

#import "CloudNPKI/CNSecureData.h"

@interface SecureDataImp : CNSecureData

- (id)init;
- (NSData *)setData:(NSData *)plain;
- (NSData *)getData:(NSData *)cipher;

@end


#endif /* SecureDataImp_h */

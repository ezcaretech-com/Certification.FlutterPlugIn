// //
// //  CertManagerExt.h
// //  CertmanagerLibrary
// //
// //  Created by shield on 25/06/2021.
// //  Copyright © 2021 lee minsu. All rights reserved.
// //

// #ifndef CertManagerExt_h
// #define CertManagerExt_h

// #import "ProtectedData.h"
// #import "Certificate.h"
// #import "CertManager.h"
// #import "SecureDataImp.h"
// #import "BillViewController.h"

// #define CLOUD_NPKI_DEFAULT_TIME_SERVER_URL    @"center.signkorea.com:8700/dday/dday.json"
// #define CLOUD_NPKI_DEFAULT_TIME_SERVER_PORT   8700

// NS_ASSUME_NONNULL_BEGIN
 
// typedef NS_ENUM(NSInteger, KoscomError)
// {
//     // common
//     KoscomErrorInvalidInput = -1001,
//     KoscomErrorInvalidPin = -1002,
//     KoscomErrorMemoryAllocation = -1003,
//     KoscomErrorSaveCert = -1004,
//     KoscomErrorNoCacheCert = -1005,
//     KoscomErrorNoServerConnection = -1006,
//     KoscomErrorCertIsNotLocked = -1007,
//     KoscomErrorNoCloudCert = -1008,
    
//     // sign
//     KoscomErrorSignFail = -2001,
//     KoscomErrorUnsupportedAlgorithm = -2002,
//     KoscomErrorGetRandom = -2003,
//     KoscomErrorVerifyVID = -2004,
    
//     // management
//     KoscomErrorInvalidPassword           = -3001,
//     KoscomErrorInvalidRepeatedSameChars  = -3002,
//     KoscomErrorInvalidRepeatedTwoChar    = -3003,
//     KoscomErrorInvalidRepeatedThreeChars = -3004,
//     KoscomErrorInvalidConsecuriveLetters = -3005,
    
//     // cmp
//     KoscomErrorUpdateFail = -4001,
//     KoscomErrorUpdateUnsupported = -4002,
//     KoscomErrorUpdateInvalidPin = -4003,
    
//     KoscomErrorRevokeFail = -4011,
    
//     // save
//     KoscomErrorSaveFail = -5001,
//     KoscomErrorSaveSignKeyPair = -5002,
//     KoscomErrorSaveKMKeyPair = -5003,
//     // cloud
//     KoscomErrorNotUnlockCert = -6000,
    
//     // bio
//     //KoscomErrorAuthFail = -7001,
//     //KoscomErrorAddItemFail = -7002,
//     //KoscomErrorGetItemFail = -7003,
//     KoscomErrorCheckPinFail = -7004,
    
    
//     // total
//     KoscomErrorNotImplement = -9000,
//     KoscomErrorNoSavedCacheCert = -65550,
    
//     // 고도화 에러코드 추가
//     //    KoscomErrorMaxCacheCertFail = CNErrorMaxCacheCertFail
    
// };

// typedef NS_ENUM(NSInteger, Status) {
//     SWITCH_ISSUE,
//     SWITCH_UPDATE
// };
// //@interface NSError (yettie) {
// //
// //}

// //@end


// // 고도화 3차 Delegate 추가(클라우드 전환 발급/갱신 목적)
// @protocol CertManagerExtDelegate <NSObject>

// @optional

// /**
//  클라우드 전환 발급 시 사용자의 패스워드를 전달받기 위한 Delegate
//  @discussion 고객사에서는 해당 delegate를 통해 전달받은 패스워드 타입을 전달할 수 있도록 구현한다.
//  @param secretType 클라우드 전환 발급 함수 등에서 요청하는 사용자 패스워드 타입(qwerty, pin)
//  @param completion 성공 핸들러
//  */
// - (void)acquireUserSecretType:(NSString *)secretType
//                    completion:(void(^)(ProtectedData *))completion;


// /**
//  빌링을 위한 WebView를 호출하여 사용자 빌링정보를 전달받기 위한 Delegate
//  @discussion 고객사에서는 해당 delegate를 통해 사용자에게 빌링임을 알리고, billing 페이지를 호출한다.
//  @param billVC presentViewController 등의 메서드를 통해 화면에 출력할 ViewController
//  @param completion 성공 핸들러
//  */
// - (void)doShowBillViewController:(BillViewController *)billVC
//                       completion:(void(^)(void))onSuccess;

// /**
//  인증서 발급/갱신 성공 여부를 전달하기 위한 Delegate
//  @discussion 고객사에서는 해당 delegate를 구현하여 발급, 갱신에 대한 출력을 구현할 수 있다.
//  @param message 발급/갱신 결과에 따른 메시지
//  @param title 발급/갱신 내용에 따른 타이틀
//  @param isSuccess 성공 실패 여부
//  @param completion 성공 핸들러
//  */
// - (void)doShowAlertMessage:(NSString *)message
//                      title:(nullable NSString *)title
//                  errorCode:(NSUInteger)errorCode
//                   errorLog:(nullable NSString *)errorLog;

// - (void)showStatus:(Status)status
//            message:(NSString *)message
//         completion:(void(^)(void))completion
//            onError:(void(^)(void))cancel;


// //- (void)doShowAlertMessage:(NSString *)message
// //                     title:(nullable NSString *)title
// //                completion:(void(^)(void))completion;

// @end

// @interface CertManagerExt : NSObject <CNClientDelegate, CertManagerExtDelegate, BillViewControllerDelegate>  {
//     //NSMutableArray *arrCert; //property와 동일한 멤버 이름은 혼돈이 옴, 잘못알고 쓴것 같음, 기본 CertManager도 똑같던데.. 확인필요
//     NSString *mLastErrorLog;
//     int mLastErrorCode;
    
//     BOOL mAutoAuth;
//     int mAutoAuthInterval;
//     NSTimeInterval mLastAuthTime;
//     BOOL mFingerprintAuthenticated;
// }

// @property (nonatomic, retain) NSMutableArray* arrCert;
// @property (nonatomic, readonly) CNClient *client;
// @property (nonatomic, readonly) CertManager *localManager;
// @property (nonatomic, readonly) ProtectedData *cmpData;
// @property (nonatomic, readonly) SecureDataImp *sd;

// @property (nonatomic, retain) id<CertManagerExtDelegate> delegate;
// @property (nonatomic, strong, nullable) void(^didAlert)(void);

// - (id)initWithClient: (CNClient *)client;

// /**
//  클라우드 서버에서 인증서 리스트를 반환한다.
//  @discussion 일반적인 상황에서 서버를 통해 인증서를 가져오지만 운영모드에 따라 디바이스 내 저장된 인증서 목록을 반환한다. 이 경우 completion  핸들러의 isCache 값이 YES로 전달된다.
//  @param completion completion 핸들러, 성공 시 인증서 리스트 객체를 반환한다. (서버에서 목록을 다운로드한 경우 NO, 캐시된 인증서들에 대한 목록을 반환하는 경우 YES를 반환한다.)
//  @param onError 에러 핸들러, 실패 시 에러 코드를 반환한다.
//  */
// - (void)loadList:(void(^)(NSArray *, BOOL))completion
//          onError:(void(^)(NSError *))onError;

// /**
//  디바이스에 저장된 캐시 목록을 반환한다.
//  @discussion fromCloud가 YES인 경우 서버 목록을 바로 반환하며, NO인 경우 디바이스에 저장된 캐시 목록을 반환한다.
//  저장된 캐시목록을 반환하는 경우에는 completion 핸들러의 BOOL 값은 YES이나, 리스트 갱신 등의 경우에는 NO 를 반환한다.
//  @param completion completion 핸들러, 성공 시 캐시 목록, 캐시/클라우드 인증서 유무, 캐시된 시간을 반환한다.
//  @param onError 에러 핸들러, 실패 시 에러 코드를 반환한다.
//  */
// - (void)loadListInCache:(BOOL)fromCloud
//            onCompletion:(void(^)(NSArray *, BOOL, NSDate *))completion
//                 onError:(void(^)(NSError *))onError;

// /**
//  클라우드 인증서 목록과 로컬 인증서 목록을 함께 반환한다.
//  @param completion 클라우드 인증서 + 로컬 인증서 목록을 담은 NSArray 를 반환한다.
//  @param onError 에러 핸들러, 실패 시 에러 코드를 반환한다.
//  */
// - (void)totalLoadList:(void(^)(NSArray *))completion
//               onError:(void(^)(NSError *))onError;

// - (void) cmsSign_C:(int)idx
//           password:(ProtectedData *)password
//         signSource:(NSData*)signSource
//        signingTime:(NSData*)signingTime
//         completion:(void(^)(NSData *))completion
//            onError:(void(^)(NSError *))onError;
// - (void) cmsSign_CForId:(NSString *)certId
//                password:(ProtectedData *)password
//              signSource:(NSData*)signSource
//             signingTime:(NSData*)signingTime
//              completion:(void(^)(NSData *))completion
//                 onError:(void(^)(NSError *))onError;

// - (void) simpleSign_C:(int)idx
//              password:(ProtectedData *)password
//            signSource:(NSData*)signSource
//           signingTime:(NSData*)signingTime
//            completion:(void(^)(NSData *))completion
//               onError:(void(^)(NSError *))onError;
// - (void) simpleSign_CForId:(NSString *)certId
//                   password:(ProtectedData *)password
//                 signSource:(NSData*)signSource
//                signingTime:(NSData*)signingTime
//                 completion:(void(^)(NSData *))completion
//                    onError:(void(^)(NSError *))onError;

// - (void) koscomSign_C:(int)idx
//              password:(ProtectedData*)password
//            signSource:(NSData*)signSource
//            completion:(void(^)(NSData *))completion
//               onError:(void(^)(NSError *))onError;
// - (void) koscomSign_CForId:(NSString *)certId
//                   password:(ProtectedData*)password
//                 signSource:(NSData*)signSource
//                 completion:(void(^)(NSData *))completion
//                    onError:(void(^)(NSError *))onError;


// /**
//  KoscomSign을 기반으 로컬 서명 혹은 클라우드 서명을 수행할 수 있는 메서드
//  @discussion  CacheFlag에 따라 캐시 서명만 수행하는 경우와 클라우드 서명+인증서 업데이트를 수행하는 경우로 나뉜다.
//  @param idx 서명 시 사용하고자 하는 인증서의 idx
//  @param isCacheFlag YES인 경우 캐시 서명 후 성공하면 completion 핸들러를, 이외에는 모두 에러코드를 바로 리턴한다.
//  NO인 경우 캐시 서명 수행 후 인증서가 없는 경우 클라우드 인증서를 이용하여 서명을 수행하고, 캐시 인증서의 PIN이 틀린 경우
//  서버에서 인증서 목록을 갱신 후 다시 클라우드 서명을 수행한다.
//  @param password 간편 PIN
//  @param signSource 서명 원문
//  @param completion 서명 성공 시 전자서명값을 리턴하는 성공 핸들러
//  @param onError 서명 실패 시 에러를 반환하는 에러 핸들러
//  */
// - (void) koscomCMSSignExt:(int)idx
//               isCacheFlag:(BOOL)flag
//                  password:(ProtectedData *)password
//                signSource:(NSData *)signSource
//                completion:(void (^)(NSData *, NSUInteger))completion
//                   onError:(void(^)(NSError *))onError;
// - (void) koscomCMSSignExtForId:(NSString *)certId
//                    isCacheFlag:(BOOL)flag
//                       password:(ProtectedData *)password
//                     signSource:(NSData *)signSource
//                     completion:(void (^)(NSData *, NSUInteger))completion
//                        onError:(void(^)(NSError *))onError;

// - (void) koscomSimpleSign_C:(int)idx
//                    password:(ProtectedData*)password
//                  signSource:(NSData*)signSource
//                  completion:(void(^)(NSData *))completion
//                     onError:(void(^)(NSError *))onError;
// - (void) koscomSimpleSign_CForId:(NSString *)certId
//                         password:(ProtectedData*)password
//                       signSource:(NSData*)signSource
//                       completion:(void(^)(NSData *))completion
//                          onError:(void(^)(NSError *))onError;

// - (void) koscomSignHash_C:(int)idx
//                  password:(ProtectedData*)password
//          hashedSignSource:(NSData*)hashedSignSource
//                     dummy:(NSData*)dummy
//                completion:(void(^)(NSData *))completion
//                   onError:(void(^)(NSError *))onError;
// - (void) koscomSignHash_CForId:(NSString *)certId
//                       password:(ProtectedData*)password
//               hashedSignSource:(NSData*)hashedSignSource
//                          dummy:(NSData*)dummy
//                     completion:(void(^)(NSData *))completion
//                        onError:(void(^)(NSError *))onError;

// - (void) cmsSignHash_C:(int)idx
//               password:(ProtectedData*)password
//       hashedSignSource:(NSData*)hashedSignSource
//                  dummy:(NSData*)dummy
//             completion:(void(^)(NSData *))completion
//                onError:(void(^)(NSError *))onError;
// - (void) cmsSignHash_CForId:(NSString *)certId
//                    password:(ProtectedData*)password
//            hashedSignSource:(NSData*)hashedSignSource
//                       dummy:(NSData*)dummy
//                  completion:(void(^)(NSData *))completion
//                     onError:(void(^)(NSError *))onError;

// - (void) simpleSignHash_C:(int)idx
//                  password:(ProtectedData *)password
//          hashedSignSource:(NSData*)hashedSignSource
//                completion:(void(^)(NSData *))completion
//                   onError:(void(^)(NSError *))onError;
// - (void) simpleSignHash_CForId:(NSString *)certId
//                       password:(ProtectedData *)password
//               hashedSignSource:(NSData*)hashedSignSource
//                     completion:(void(^)(NSData *))completion
//                        onError:(void(^)(NSError *))onError;

// - (void) cmsSignHashWithSigningTime_C:(int)idx
//                              password:(ProtectedData*)password
//                      hashedSignSource:(NSData*)hashedSignSource
//                            completion:(void(^)(NSData *))completion
//                               onError:(void(^)(NSError *))onError;
// - (void) cmsSignHashWithSigningTime_CForId:(NSString *)certId
//                                   password:(ProtectedData*)password
//                           hashedSignSource:(NSData*)hashedSignSource
//                                 completion:(void(^)(NSData *))completion
//                                    onError:(void(^)(NSError *))onError;

// - (void) cmsSignWithSigningTime_C:(int)idx
//                          password:(ProtectedData*)password
//                        signSource:(NSData*)signSource
//                       signingTime:(NSData*)signingTime
//                        completion:(void(^)(NSData *))completion
//                           onError:(void(^)(NSError *))onError;
// - (void) cmsSignWithSigningTime_CForId:(NSString *)certId
//                               password:(ProtectedData*)password
//                             signSource:(NSData*)signSource
//                            signingTime:(NSData*)signingTime
//                             completion:(void(^)(NSData *))completion
//                                onError:(void(^)(NSError *))onError;

// - (void) mydataSign_C:(int)idx
//              password:(ProtectedData*)password
//            signSource:(NSArray<NSData *> *)signSources
//           signingTime:(NSData*)signingTime
//            completion:(void(^)(NSString *, NSArray<NSData *> *))completion
//               onError:(void(^)(NSError *))onError;
// - (void) mydataSign_CForId:(NSString *)certId
//                   password:(ProtectedData*)password
//                 signSource:(NSArray<NSData *> *)signSources
//                signingTime:(NSData*)signingTime
//                 completion:(void(^)(NSString *, NSArray<NSData *> *))completion
//                    onError:(void(^)(NSError *))onError;


// - (void) getRandomFromKey_C:(int)idx
//                    password:(ProtectedData*)password
//                  completion:(void(^)(NSData *))completion
//                     onError:(void(^)(NSError *))onError ;
// - (void) getRandomFromKey_CForId:(NSString *)certId
//                         password:(ProtectedData*)password
//                       completion:(void(^)(NSData *))completion
//                          onError:(void(^)(NSError *))onError ;

// - (void) selfUserVerify_C: (int)idx
//                       idv:(ProtectedData *)idv
//                  password:(ProtectedData*)password
//                completion:(void(^)(void))completion
//                   onError:(void(^)(NSError *))onError;
// - (void) selfUserVerify_CForId:(NSString *)certId
//                            idv:(ProtectedData *)idv
//                       password:(ProtectedData*)password
//                     completion:(void(^)(void))completion
//                        onError:(void(^)(NSError *))onError;

// - (void) importCertificate:(NSData *)certificate
//                        key:(NSData *)key
//              kmCertificate:(nullable NSData *)kmCertificate
//                      kmKey:(nullable NSData *)kmKey
//                     secret:(ProtectedData *)secret
//                        pin:(ProtectedData *)pin
//                 completion:(void(^)(void))completion
//                    onError:(void(^)(NSError *))onError;

// - (void) exportCertificate:(int)idx
//                        pin:(ProtectedData *)pin
//                     secret:(ProtectedData*)secret
//                 completion:(void(^)(NSArray<CNCertificate *> *, BOOL))completion
//                    onError:(void(^)(NSError *))onError;
// - (void) exportCertificateForId:(NSString *)certId
//                             pin:(ProtectedData *)pin
//                          secret:(ProtectedData*)secret
// //                completion:(void(^)(void))completion
//                      completion:(void(^)(NSArray<CNCertificate *> *, BOOL))completion
//                         onError:(void(^)(NSError *))onError;

// - (void) delCert:(int)idx
//       completion:(void(^)(void))completion
//          onError:(void(^)(NSError *))onError;
// - (void) delCertForId:(NSString *)certId
//            completion:(void(^)(void))completion
//               onError:(void(^)(NSError *))onError;

// - (void) changeCertPassword_C:(int)idx
//                   oldPassword:(ProtectedData *)oldPassword
//                   newPassword:(ProtectedData *)newPassword
//                    completion:(void(^)(void))completion
//                       onError:(void(^)(NSError *))onError;
// - (void) changeCertPassword_CForId:(NSString *)certId
//                        oldPassword:(ProtectedData *)oldPassword
//                        newPassword:(ProtectedData *)newPassword
//                         completion:(void(^)(void))completion
//                            onError:(void(^)(NSError *))onError;


// - (void) setOperationPrompt: (NSString *)aString;

// - (void) addBioCloud:(int)idx
//                  pin:(ProtectedData *)pin
//     isAuthentication:(BOOL) isAuthentication
//           completion:(void(^)(void))completion
//              onError:(void(^)(NSError *))onError ;
// - (void) addBioCloudForId:(NSString *)certId
//                       pin:(ProtectedData *)pin
//          isAuthentication:(BOOL) isAuthentication
//                completion:(void(^)(void))completion
//                   onError:(void(^)(NSError *))onError ;

// - (void) getBioCloud: (int)idx
//           completion:(void(^)(ProtectedData *))completion
//              onError:(void(^)(NSError *))onError ;
// - (void) getBioCloudForId:(NSString *)certId
//                completion:(void(^)(ProtectedData *))completion
//                   onError:(void(^)(NSError *))onError ;

// - (void) getBioCloudNonAuto: (int)idx
//                  completion:(void(^)(ProtectedData *))completion
//                     onError:(void(^)(NSError *))onError ;
// - (void) getBioCloudNonAutoForId:(NSString *)certId
//                       completion:(void(^)(ProtectedData *))completion
//                          onError:(void(^)(NSError *))onError ;

// - (BOOL) removeBioCloud:(int)idx;
// - (BOOL) removeBioCloudForId:(NSString *)certId;

// - (BOOL) hasBioCloud:(NSString *) certId;
// - (void)setAutoAuth:(BOOL)value;
// - (void)setAutoSignInterval:(unsigned int)second;
// - (long) getRemainTimeOfAutoSignInterval;

// // 마지막에 발생한 에러로그를 반환합니다.
// - (NSString *)getLastErrorString;

// // 마지막에 발생한 에러코드를 반환합니다.
// - (int) getLastErrorCode;

// - (void) setBillFlag : (BOOL) flag;

// - (Certificate *) issueWithRefNumWithoutStore_C:(NSString*)refNum
//                                        authCode:(NSString*)authCode
//                                              ip:(NSString *)ip
//                                            port:(int)port
//                                           caNum:(int)caNum
//                                       isReIssue:(BOOL)isReIssue;

// - (Certificate *) issueWithRefNumWithoutStore_C:(NSString*)refNum
//                                        authCode:(NSString*)authCode
//                                          caName:(NSString*)caName
//                                        testFlag:(NSUInteger)testFlag;
// - (void) update_C:(int)idx
//          password:(ProtectedData *)password
//                ip:(NSString *)ip
//              port:(int)port
//             caNum:(int)caNum
//        completion:(void(^)(void))onSuccess
//           onError:(void(^)(NSError *))onError;

// - (void) update_C:(int)idx
//          password:(ProtectedData *)password
//            caName:(NSString*)caName
//          testFlag:(NSUInteger)testFlag
//        completion:(void(^)(void))onSuccess
//           onError:(void(^)(NSError *))onError;
// - (void) update_CForId:(NSString *)certId
//               password:(ProtectedData *)password
//                 caName:(NSString*)caName
//               testFlag:(NSUInteger)testFlag
//             completion:(void(^)(void))onSuccess
//                onError:(void(^)(NSError *))onError;

// - (void) revoke_C:(int)idx
//          password:(ProtectedData *)password
//                ip:(NSString *)ip
//              port:(int)port
//             caNum:(int)caNum
//        completion:(void(^)(void))onSuccess
//           onError:(void(^)(NSError *))onError;

// - (void) revoke_C:(int)idx
//          password:(ProtectedData *) password
//            caName:(NSString*)caName
//          testFlag:(NSUInteger)testFlag
//        completion:(void(^)(void))onSuccess
//           onError:(void(^)(NSError *))onError;
// - (void) revoke_CForId:(NSString *)certId
//               password:(ProtectedData *) password
//                 caName:(NSString*)caName
//               testFlag:(NSUInteger)testFlag
//             completion:(void(^)(void))onSuccess
//                onError:(void(^)(NSError *))onError;

// // CMP 호출 후 내부 변수 초기화한다.
// - (void) clearCMP;

// - (void) saveCloudCert:(NSData*)certData
//                    key:(NSData*)keyData
//                 kmCert:(NSData*)kmCert
//                  kmKey:(NSData*)kmKey
//                    pin:(ProtectedData *)newPin
//             completion:(void(^)(void))onSuccess
//                onError:(void(^)(NSError *))onError;

// /*
//  - (BOOL) saveKeyChainCert:(NSData*)certData
//  key:(NSData*)keyData
//  kmCert:(NSData*)kmCert
//  kmKey:(NSData*)kmKey
//  password:(ProtectedData *)password;
//  */
// - (void) saveKeyChainCert:(NSData*)certData
//                       key:(NSData*)keyData
//                    kmCert:(NSData*)kmCert
//                     kmKey:(NSData*)kmKey
//                  password:(ProtectedData *)password
//                completion:(void(^)(BOOL)) completion
//                   onError:(void(^)(NSError *))onError;

// - (void) checkPin:(int)idx
//          password:(ProtectedData*)password
//        completion:(void(^)(void))completion
//           onError:(void(^)(NSError *))onError ;
// - (void) checkPinForId:(NSString *)certId
//               password:(ProtectedData*)password
//             completion:(void(^)(void))completion
//                onError:(void(^)(NSError *))onError ;

// + (int)checkPinValidity:(char *)pin
//                  length:(int)len;

// - (void) unlockCertificate:(int)idx
//                 completion:(void(^)(void))completion
//                    onError:(void(^)(NSError *))onError;
// - (void) unlockCertificateForId:(NSString *)certId
//                      completion:(void(^)(void))completion
//                         onError:(void(^)(NSError *))onError;
// // filter
// - (void)filterCertListWithIssuer:(NSArray *)issuers
//                     onCompletion:(void(^)(NSArray *))completion;
// - (void)filterCertListWithIssuerCN:(NSArray *)issuers
//                       onCompletion:(void(^)(NSArray *))completion;
// //- (void)filterCertListWithPolicyOid:(NSArray *)policies;
// - (void)filterCertListWithPolicyOid:(NSArray *)policies
//                        onCompletion:(void(^)(NSArray *))completion;
// - (void)filterExpiredCert:(void(^)(NSArray *))completion;

// // cache sign
// - (int) cmsSignCache_C:(int)idx
//               password:(ProtectedData *)password
//             signSource:(NSData*)signSource
//            signingTime:(NSData*)signingTime
//             signResult:(char*)signResult;
// - (int) cmsSignCache_CForId:(NSString *)certId
//                    password:(ProtectedData *)password
//                  signSource:(NSData*)signSource
//                 signingTime:(NSData*)signingTime
//                  signResult:(char*)signResult;

// - (int) simpleSignCache_C:(int)idx
//                  password:(ProtectedData*)password
//                signSource:(NSData*)signSource
//                signResult:(char*)signResult;
// - (int) simpleSignCache_CForId:(NSString *)certId
//                       password:(ProtectedData*)password
//                     signSource:(NSData*)signSource
//                     signResult:(char*)signResult;

// - (int) koscomSignCache_C:(int)idx
//                  password:(ProtectedData*)password
//                signSource:(NSData*)signSource
//                signResult:(char*)signResult;
// - (int) koscomSignCache_CForId:(NSString *)certId
//                       password:(ProtectedData*)password
//                     signSource:(NSData*)signSource
//                     signResult:(char*)signResult;

// - (int) koscomSimpleSignCache_C:(int)idx
//                        password:(ProtectedData*)password
//                      signSource:(NSData*)signSource
//                      signResult:(char*)signResult;
// - (int) koscomSimpleSignCache_CForId:(NSString *)certId
//                             password:(ProtectedData*)password
//                           signSource:(NSData*)signSource
//                           signResult:(char*)signResult;

// - (int) koscomSignHashCache_C:(int)idx
//                      password:(ProtectedData*)password
//              hashedSignSource:(NSData*)hashedSignSource
//                         dummy:(NSData*)dummy
//                    signResult:(char*)signResult;
// - (int) koscomSignHashCache_CForId:(NSString *)certId
//                           password:(ProtectedData*)password
//                   hashedSignSource:(NSData*)hashedSignSource
//                              dummy:(NSData*)dummy
//                         signResult:(char*)signResult;

// - (int) cmsSignHashCache_C:(int)idx
//                   password:(ProtectedData*)password
//           hashedSignSource:(NSData*)hashedSignSource
//                      dummy:(NSData*)dummy
//                 signResult:(char*)signResult;
// - (int) cmsSignHashCache_CForId:(NSString *)certId
//                        password:(ProtectedData*)password
//                hashedSignSource:(NSData*)hashedSignSource
//                           dummy:(NSData*)dummy
//                      signResult:(char*)signResult;

// - (int) simpleSignHashCache_C:(int)idx
//                      password:(ProtectedData*)password
//              hashedSignSource:(NSData*)hashedSignSource
//                    signResult:(char*)signResult;
// - (int) simpleSignHashCache_CForId:(NSString *)certId
//                           password:(ProtectedData*)password
//                   hashedSignSource:(NSData*)hashedSignSource
//                         signResult:(char*)signResult;

// - (int) cmsSignHashWithSigningTimeCache_C:(int)idx
//                                  password:(ProtectedData *)password
//                          hashedSignSource:(NSData*)hashedSignSource
//                                signResult:(char*)signResult;
// - (int) cmsSignHashWithSigningTimeCache_CForId:(NSString *)certId
//                                       password:(ProtectedData *)password
//                               hashedSignSource:(NSData*)hashedSignSource
//                                     signResult:(char*)signResult;

// - (int) mydataSignCache_C:(int)idx
//                  password:(ProtectedData*)password
//                signSource:(NSArray<NSData *> *)signSources
//               signingTime:(NSData*)signingTime
//                     caOrg:(NSString *)caOrg
//                signResult:(NSArray<NSData *> *)signResult;
// - (int) mydataSignCache_CForId:(NSString *)certId
//                       password:(ProtectedData*)password
//                     signSource:(NSArray<NSData *> *)signSources
//                    signingTime:(NSData*)signingTime
//                          caOrg:(NSString *)caOrg
//                     signResult:(NSArray<NSData *> *)signResult;

// - (NSData*) getRandomFromKeyCache_C: (int)idx
//                            password:(ProtectedData *)password;
// - (NSData*) getRandomFromKeyCache_CForId:(NSString *)certId
//                                 password:(ProtectedData *)password;

// - (int) selfUserVerifyCache_C: (int)idx
//                           idv:(ProtectedData *)idv
//                      password:(ProtectedData *)password;
// - (int) selfUserVerifyCache_CForId:(NSString *)certId
//                                idv:(ProtectedData *)idv
//                           password:(ProtectedData *)password;

// // 클라우드 인증서 인덱스 검색 API 추가 (2022.05.30)
// - (int) count;
// /**
//  인증서의 DN을 이용하며 캐시된 인증서의 유무를 반환한다.
//  @param dn 인증서의 캐시 유무를 확인하기 위한 DN 값
//  */
// - (int)getCertIdxBySubjectDNForCloud:(NSString*)dn;






// // 고도화 3차 모바일인증서 로컬 발급

// /**
//  로컬에 저장된 인증서에 대한 리스트를 출력하는 메서드(Not cache)
//  @discussion 로컬인증서를 발급하거나, 갱신할 때 저장된 인증서를 가져오기 위한 메서드
//  @param completion 성공 핸들러
//  @param onError 에러 핸들러
//  */
// - (void)loadLocalList:(void(^)(NSArray *))completion
//               onError:(void(^)(NSError *))onError;


// /**
//  사용자가 클라우드 인증서를 발급하도록 유도하며, 거부할 경우 로컬 인증서를 발급 후 저장한다.
//  @discussion 설정된 dday가 지났거나 사용자가 클라우드 로그인/가입을 수행하는 경우 인증서를 클라우드에 저장한다. 만약 클라우드 로그인/가입을 거부하는 경우에는 로컬 인증서를 발급 후 저장한다.
//  @param refNumParam 인증서 발급 시 인증서 발급 서버에 전달하는 참조번호
//  @param authNumParam 인증서 발급 시 인증서 발급 서버에 전달하는 인가코드
//  @param isTestFlagParam isTest가 YES인 경우에는 테스트용, NO인 경우에는 REAL 인증서를 발급한다.
//  @param onError 에러 핸들러
//  */
// - (void) issueLocal:(NSString *)refNumParam
//            authCode:(NSString *)authNumParam
//              caName:(NSString *)caName
//            testFlag:(BOOL)isTestFlagParam
//             onError:(void (^)(NSError * Error))onError;

// - (void) issueLocal:(NSString *)refNumParam
//            authCode:(NSString *)authNumParam
//                  ip:(NSString *)caIP
//                port:(int)caPort
//               caNum:(int)caNum
//             onError:(void (^)(NSError * Error))onError;




// /**
//  사용자가 클라우드 연결이 되어 있는 경우 인증서를 발급하고 PIN을 이용해 클라우드 서버에 저장한다.
//  @discussion 기존 issueWithRefNumWithoutStore_C 메서드의 경우 인증서 저장을 자동으로 하지 않지만, 해당 메서드는 인증서 저장까지 지원한다.
//  @param refNumParam 인증서 발급 시 인증서 발급 서버에 전달하는 참조번호
//  @param authNumParam 인증서 발급 시 인증서 발급 서버에 전달하는 인가코드
//  @param isTestFlagParam isTest가 YES인 경우에는 테스트용, NO인 경우에는 REAL 인증서를 발급한다.
//  @param pin 사용자의 PIN 입력 값
//  @param onError 에러 핸들러
//  */
// - (void) issueCloud:(NSString *)refNumParam
//            authCode:(NSString *)authNumParam
//              caName:(NSString *)caName
//            testFlag:(BOOL)isTestFlagParam
//       userSecretPin:(ProtectedData *)userPin
//             onError:(void (^)(NSError * Error))onError;


// - (void) issueCloud:(NSString *)refNumParam
//            authCode:(NSString *)authNumParam
//                  ip:(NSString *)caIP
//                port:(int)caPort
//               caNum:(int)caNum
//       userSecretPin:(ProtectedData *)userPin
//             onError:(void (^)(NSError * Error))onError;



// /**
//  사용자의 로컬 인증서를 갱신 후 클라우드에 저장하여 사용할 수 있도록 유도하는 갱신 메서드
//  @discussion 인증서 갱신 시 클라우드 로그인/회원 가입을 유도한 후 갱신된 인증서를 로컬과 클라우드에 각각 저장한다.
//  @param idx 갱신할 인증서의 idx
//  @param password 갱신할 인증서의 패스워드(qwerty 타입)
//  @param caName 갱신을 요청할 CA의 이름
//  @param completion 성공 핸들러
//  @param onError 에러 핸들러
//  */
// - (void) updateLocal:(int)idx
//               caName:(NSString*)caName
//             testFlag:(BOOL)testFlag
//             password:(ProtectedData *)password
//              onError:(void(^)(NSError *))onError;
// - (void) updateLocalForId:(NSString *)certId
//                    caName:(NSString*)caName
//                  testFlag:(BOOL)testFlag
//                  password:(ProtectedData *)password
//                   onError:(void(^)(NSError *))onError;

// - (void) updateLocal:(int)idx
//                   ip:(NSString *)caIP
//                 port:(int)caPort
//                caNum:(int)caNum
//             password:(ProtectedData *)password
//              onError:(void(^)(NSError *))onError;



// /**
//  사용자의 클라우드 인증서를 갱신하고 저장하는 메서드
//  @discussion 기존 update_C 메서드와의 차이점은 저장여부이다.
//  @param idx 갱신하고자 하는 인증서의 idx
//  @param password 갱신할 인증서의 패스워드(qwerty 타입)
//  @param caName 갱신을 요청할 CA의 이름
//  @param completion 성공 핸들러
//  @param onError 에러 핸들러
//  */
// - (void) updateCloud:(int)idx
//               caName:(NSString*)caName
//             testFlag:(BOOL)testFlag
//        userSecretPin:(ProtectedData *)userPin
//              onError:(void(^)(NSError *))onError;
// - (void) updateCloudForId:(NSString *)certId
//                    caName:(NSString*)caName
//                  testFlag:(BOOL)testFlag
//             userSecretPin:(ProtectedData *)userPin
//                   onError:(void(^)(NSError *))onError;




// - (void) updateCloud:(int)idx
//                   ip:(NSString *)caIP
//                 port:(int)caPort
//                caNum:(int)caNum
//        userSecretPin:(ProtectedData *)userPin
//              onError:(void(^)(NSError *))onError;

// /**
//  메모리에 불러온 클라우드 인증서 리스트에서 해당 inx에 해당하는 캐시 인증서가 존재하는 경우 인증서를 추출한다.
//  */
// - (NSData *)getCertificate:(int)idx
//                    onError:(void(^)(NSError *))onError;

// - (NSData *)getCertificateForId:(NSString *)certId
//                         onError:(void(^)(NSError *))onError;


// /**
//  NSData 타입의 인증서에서 공개키를 추출한다.
//  */
// - (NSData *)getPublicKey:(NSData *)certData;

// /**
//  PIN에 대한 유효성을 검증한다.
//  */
// - (CNError)checkPinValidity:(NSData*)pin;

// @end

// NS_ASSUME_NONNULL_END

// #endif /* CertManagerExt_h */

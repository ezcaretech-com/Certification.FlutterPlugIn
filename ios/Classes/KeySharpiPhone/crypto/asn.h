//
// Created by SignKorea KOSCOM HS
//

#ifndef ASN_H
#define ASN_H
#ifndef U8
typedef unsigned char U8;
#endif

/* Error code */
#define ERR_INVALID_NEGATIVE_PARAMETER      -1
#define ERR_DER_INVALID_LENGTH              -2
#define ERR_USER_AGREE_INFO_EMPTY           -3
#define ERR_NULL_BUFFER                     -4
#define ERR_LENGTH_OVERFLOW                 -5

/* Der tag type */
#define DERTYPE_INTEGER                   0x02
#define DERTYPE_BITSTRING                 0x03
#define DERTYPE_OCTETSTRING               0x04
#define DERTYPE_UTF8STRING                0x0C
#define DERTYPE_SEQUENCE                  0x30

/* User Agree Info */
#define UAI_REAL_NAME       16
#define UAI_GENDER          8
#define UAI_NATIONAL_INFO   4
#define UAI_BIRTH_DATE      2
#define UAI_CI              1

unsigned right_zero_length(U8 x);

int make_person_info_req(U8 *buf, U8 *user_agreement, int user_agreement_len, U8 user_agree_info);

int make_module_version(U8 *buf, int major, int minor);

int
make_module_info(U8 *buf, U8 *moduleName, int moduleName_len, U8 *moduleVendorName, int moduleVendorName_len, int major,
                 int minor);

int make_version(U8 *buf, int version);

int make_ucpid_nonce(U8 *buf, U8 *ucpid_nonce, int ucpid_nonce_leh);

int make_ucpid_request_info(U8 *buf, int version, U8 *ucpid_nonce, int ucpid_nonce_len, U8 *user_agreement,
                            int user_agreement_len, U8 user_agree_info, U8 *moduleName,
                            int moudleName_len, U8 *moduleVendorName, int moduleVendorName_len,
                            int module_version_major, int module_version_minor, U8 *isp_url_info, int isp_url_info_len);

int koscom_ucpid_request_info(U8 *buf, U8 *ucpid_nonce, int ucpid_nonce_len, U8 *user_agreement,
                              int user_agreement_len, U8 user_agree_info, U8 *isp_url_info, int isp_url_info_len);

#endif

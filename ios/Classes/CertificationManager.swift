//
//  CertificationManager.swift
//  certification
//
//  Created by Moon Jihong on 2024/04/04.
//

import Foundation

class CertificationManager {
    static var _keySharp: KeySharpAdaptor?
    static var _verifyUrl = ""

    // MARK: Initialize
    public init(downloadUrl: String, verifyUrl: String) {
        CertificationManager._verifyUrl = verifyUrl
        if CertificationManager._keySharp == nil {
            CertificationManager._keySharp = KeySharpAdaptor.shared() as? KeySharpAdaptor
        }
        CertificationManager._keySharp?.serviceUrl = downloadUrl
    }
    
    public static func download(with userId: String) throws -> Int {
        guard let keySharp = CertificationManager._keySharp else {
            throw NSError(domain: "CertificationManager", code: -1, userInfo: [NSLocalizedDescriptionKey: "KeySharpAdaptor is not initialized"])
        }
        try keySharp.download(with: userId)
        return keySharp.certIndex
    }
    
    public static func checkPassword(with idx: Int, userPw: String) throws -> Bool {
        guard let keySharp = CertificationManager._keySharp else {
            throw NSError(domain: "CertificationManager", code: -1, userInfo: [NSLocalizedDescriptionKey: "KeySharpAdaptor is not initialized"])
        }
        let checkPwd = keySharp.checkPassword(with: Int32(idx), password: userPw)
        return checkPwd != -1 ? true : false
    }

    public static func sign(with password: String, message: String, completion: @escaping (String?) -> Void) throws -> Void {
        guard let keySharp = CertificationManager._keySharp else {
            throw NSError(domain: "CertificationManager", code: -1, userInfo: [NSLocalizedDescriptionKey: "KeySharpAdaptor is not initialized"])
        }

        if _verifyUrl.isEmpty {
            completion(try keySharp.signAndVerify(with: password, message: message))
        } else {
            let cipherText = try keySharp.sign(with: password, message: message)
            NetworkHelper.verifications(verifyUrl: _verifyUrl, convertData: cipherText, completion: {
                response in
                if let responseData = response {
                    print("Cert Verify Result: \(responseData)")
                    if responseData != "1" {
                        completion("")
                    } else {
                        completion(cipherText)
                    }
                } else {
                    print("Failed to get response data")
                    completion("")
                }
            })
        }
        
    }

    public static func removeAll() {
        CertificationManager._keySharp?.removeAll()
    }
}

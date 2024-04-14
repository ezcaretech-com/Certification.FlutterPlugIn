import Flutter
import UIKit

public class CertificationPlugin: NSObject, FlutterPlugin {
    
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "certification", binaryMessenger: registrar.messenger())
    let instance = CertificationPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    switch call.method {
    case "getPlatformVersion":
      result("iOS " + UIDevice.current.systemVersion)
    case "initialize" :
        do {
            guard let argMaps = call.arguments as? Dictionary<String, Any>,
                  let downloadUrl = argMaps["downloadUrl"] as? String,
                  let verifyUrl = argMaps["verifyUrl"] as? String else {
                result(-1)
                return
            }
            CertificationManager(downloadUrl: downloadUrl, verifyUrl: verifyUrl)
            result(-3701)
        } catch {
            result(-1)
        }
    case "certAuth" :
        do {
            guard let argMaps = call.arguments as? Dictionary<String, Any>,
                  let userId = argMaps["userId"] as? String,
                  let password = argMaps["password"] as? String else {
                result(false)
                return
            }
            let certIndex = try CertificationManager.download(with:userId)
            print("certIndex : \(certIndex)")
            guard certIndex > -1 else {
                result(false)
                return
            }
            let checkpwd = try CertificationManager.checkPassword(with: certIndex, userPw: password)
            print("checkpwd : \(checkpwd)")
            guard checkpwd else {
                result(false)
                return
            }
            CertificationManager.removeAll()
            result(true)
        } catch {
            result(false)
        }
    case "encrypt" :
        do {
            guard let argMaps = call.arguments as? Dictionary<String, Any>,
                  let userId = argMaps["userId"] as? String,
                  let password = argMaps["password"] as? String,
                  let plainText = argMaps["plainText"] as? String else {
                result("")
                return
            }
            let certIndex = try CertificationManager.download(with:userId)
            print("certIndex : \(certIndex)")
            guard certIndex > -1 else {
                result("")
                return
            }
            try CertificationManager.sign(with: password, message: plainText, completion: {
                _encrypt in
                guard let encrypt = _encrypt, !encrypt.isEmpty else {
                    result("")
                    return
                }
                print("encrypt : \(encrypt)")
                CertificationManager.removeAll()
                result(encrypt)
            })
        } catch {
            print("eror")
            result("")
        }
    default:
      result(FlutterMethodNotImplemented)
    }
  }
}

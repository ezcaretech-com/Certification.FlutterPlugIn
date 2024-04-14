//
//  NetworkHelper.swift
//  certification
//
//  Created by Moon Jihong on 2024/04/05.
//

import Foundation

class NetworkHelper {
    static func verifications(verifyUrl:String, convertData: String, completion: @escaping (String?) -> Void) {
        guard let url = URL(string: verifyUrl) else {
            print("Invalid URL")
            completion(nil)
            return
        }
        
        let mediaType = "application/json; charset=utf-8"
        let client = URLSession.shared
        
        guard let postData = try? JSONEncoder().encode(convertData) else {
            print("Failed to encode data")
            completion(nil)
            return
        }
        
        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.setValue("application/json", forHTTPHeaderField: "Accept")
        request.setValue("application/json; charset=utf-8", forHTTPHeaderField: "Content-Type")
        request.httpBody = postData
        
        var isSuccess = false
        var code = 0
        var responseData = ""
        
        let semaphore = DispatchSemaphore(value: 0)
        
        let task = client.dataTask(with: request) { data, response, error in
            defer {
                semaphore.signal()
            }
            
            guard let httpResponse = response as? HTTPURLResponse else {
                print("Invalid response")
                completion(nil)
                return
            }
            
            code = httpResponse.statusCode
            isSuccess = (200...299).contains(code)
            var responseString = ""
            
            if let responseData = data {
                do {
                    responseString = try JSONDecoder().decode(String.self, from: responseData)
                } catch {
                    print("Error decoding response data: \(error)")
                    completion(nil)
                    return
                }
            }
            
            completion(responseString) // Task가 종료된 후에 값을 외부로 반환
        }
        
        task.resume()
        semaphore.wait()
    }
}

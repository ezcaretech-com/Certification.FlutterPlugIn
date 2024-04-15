#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint certification.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'certification'
  s.version          = '0.0.1'
  s.summary          = 'A new Flutter plugin project.'
  s.description      = <<-DESC
A new Flutter plugin project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*.{swift,h,m}'
  s.framework = 'Security'
  s.library = 'sqlite3'
  s.vendored_libraries = 'Assets/**/*'
  s.exclude_files = 'Classes/certification-Bridging-Header.h'
  # , 'Classes/KeySharpAdaptor.h'
  s.private_header_files = 'Classes/KeySharpAdaptor.h'
  s.dependency 'Flutter'
  s.platform = :ios, '11.0'
  # s.preserve_paths = '../example/ios/Pods/Target Support Files/certification/certification-Bridging-Header.h'
  # s.public_header_files = '../example/ios/Pods/Target Support Files/certification/certification-umbrella.h'
  
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.swift_version = '5.0'
end

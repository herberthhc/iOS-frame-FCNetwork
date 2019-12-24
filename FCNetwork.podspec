#
# Be sure to run `pod lib lint FCNetwork.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FCNetwork'
  s.version          = '0.1.1'
  s.summary          = '基于AFNetworking封装的网络库，支持缓存，过程拦截'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/LtyFantasy/iOS-frame-FCNetwork'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'LeoLiu' => 'ltyfantasy@163.com' }
  s.source           = { :git => 'https://github.com/LtyFantasy/iOS-frame-FCNetwork.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.public_header_files = 'FCNetwork/**/*.h'
  s.source_files = 'FCNetwork/**/*'
  
  s.dependency 'AFNetworking', '~> 3.2.0'
  
  # s.resource_bundles = {
  #   'FCNetwork' => ['FCNetwork/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
